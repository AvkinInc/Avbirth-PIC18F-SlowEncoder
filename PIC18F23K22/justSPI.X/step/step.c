#include "step.h"
#include "../mcc_generated_files/mcc.h"
// #include "../mcc_generated_files/interrupt_manager.h"
#include "../EUSART_Helpers/EUSART_Helpers.h"

// Pololu DRV8711 Stepper driver breakout - https://www.pololu.com/product/3730

#define EUSART1_Write(x) __nop()
#define get_INTERRUPT_STEPPER_BREAK_FLAG() false
#define set_INTERRUPT_STEPPER_BREAK_FLAG(x) __nop()

uint16_t control_bits = CTRL_DEFAULT;
uint8_t control_bits_read_high = 0; // this will be zzzzdddd, lower byte is data, higher byte is trash
uint8_t control_bits_read_low = 0; // this will be dddddddd, both bytes are data

void initDRV8711(void){
    /* according to Pololu, we need to do these things at power-on
     * SPI init // done elsewhere
     * set DRV8711 Chip Select via GPIO // done elsewhere
     * reset DRV8711 settings over SPI
     * clear DRV8711 status over SPI
     * set DRV8711 decay mode over SPI
     * set DRV8711 current limit over SPI
     * enable DRV8711 via GPIO pin
     */
        
    // resetting settings for torque
    DRV8711_SPI_CMD(TORQUE_ADDR_DRV8711, TORQUE_DEFAULT);
    // resetting settings for off
    DRV8711_SPI_CMD(OFF_ADDR_DRV8711, OFF_DEFAULT);
    // resetting settings for blank
    DRV8711_SPI_CMD(BLANK_ADDR_DRV8711, BLANK_DEFAULT);
    // resetting settings for decay
    DRV8711_SPI_CMD(DECAY_ADDR_DRV8711, DECAY_DEFAULT);
    // resetting settings for drive
    DRV8711_SPI_CMD(DRIVE_ADDR_DRV8711, DRIVE_DEFAULT);
    // resetting settings for stall
    DRV8711_SPI_CMD(STALL_ADDR_DRV8711, STALL_DEFAULT);
    // resetting settings for ctrl - set this last because it has the enable bit
    DRV8711_SPI_CMD(CTRL_ADDR_DRV8711, CTRL_DEFAULT);
    
    // clear the status
    DRV8711_SPI_CMD(STATUS_ADDR_DRV8711, 0);
    
    // set the decay
    DRV8711_SPI_CMD(DECAY_ADDR_DRV8711, 0);
    
    // set the current limit - MAX 8 AMPS?
    // From the DRV8711 datasheet, section 7.3.4, equation 2:
    //
    //   Ifs = (2.75 V * TORQUE) / (256 * ISGAIN * Risense)
    //
    // Rearranged:
    //
    //   TORQUE = (256 * ISGAIN * Risense * Ifs) / 2.75 V
    //
    // The 36v4 has an Risense of 30 milliohms, and "current" is in milliamps,
    // so:
    //
    //   TORQUE = (256 * ISGAIN * (30/1000) ohms * (current/1000) A) / 2.75 V
    //          = (7680 * ISGAIN * current) / 2750000
    //
    // We want to pick the highest gain (5, 10, 20, or 40) that will not
    // overflow TORQUE (8 bits, 0xFF max), so we start with a gain of 40 and
    // calculate the TORQUE value needed.
    uint8_t isgainBits = 0b11;
    uint16_t torqueBits = ((uint32_t)768  * CURRENT_LIMIT) / 6875; // = 139

    // Halve the gain and TORQUE until the TORQUE value fits in 8 bits.
  /*  while (torqueBits > 0xFF)
    {
      isgainBits--;
      torqueBits >>= 1;
    }  */
    // 139 is already less than 255

    control_bits = (control_bits & 0b110011111111) | (isgainBits << 8);
    DRV8711_SPI_CMD(CTRL_ADDR_DRV8711, control_bits);
    uint16_t torque = (TORQUE_DEFAULT & 0b111100000000) | torqueBits;
    DRV8711_SPI_CMD(TORQUE_ADDR_DRV8711, torque);
    
    // when you start the motor, remember to set the step size and enable bit over SPI!
}

void DRV8711_SPI_CMD(uint8_t addr, uint16_t cmd){ 
    // cmd is only 12 bits
    // SPI data is sent in 2 8 bit writes
    // first write: 0xxxdddd, where xxx is the address, and dddd is the higheset nibble
    // second write: dddddddd, the lowest 2 nibbles
    uint8_t addr4 = (addr & 0b0111); // 4 bits, highest bit is 0 for a write
    uint16_t cmd12 = (cmd & 0xFFF); // 12 bits
    SPI_CS_SetHigh();
   // SPI1_Open(SPI1_DEFAULT);
    SPI1_WriteByte((addr4<<4) | (cmd12>>8));
    SPI1_WriteByte(cmd12 & 0xFF); 
  //  SPI1_Close();
    SPI_CS_SetLow();
    writeString("w:");
    writeByte('\t');
    write1byteHex((addr4<<4) | (cmd12>>8));
    writeByte('\t');
    write1byteHex(cmd12 & 0xFF);
    writeByte('\t');
    writeString("No r");
    writeByte('\n');
}

void DRV8711_SPI_read(uint8_t addr){ 
    // SPI data is sent in 2 8 bit writes
    // first write: 1xxxzzzz, where xxx is the address, and zzzz is the dummy data
    // second write: zzzzzzzz, dummy data
    uint8_t addr4 = (addr | 0b1000); // 4 bits, highest bit is 1 for a read
    SPI_CS_SetHigh();
  //  SPI1_Open(SPI1_DEFAULT);
    control_bits_read_high = SPI1_ExchangeByte((addr4<<4) & 0b11110000);
    control_bits_read_low = SPI1_ExchangeByte(0);  // dummy data for write
  /*  SPI_CS_SetHigh();
    SSP1BUF = (addr4<<4) & 0b11110000;
    while(!PIR1bits.SSP1IF);
    PIR1bits.SSP1IF = 0;
    control_bits_read_high = SSP1BUF;
    SPI_CS_SetLow();
    SSP1BUF = (addr4<<4) & 0b11110000;
    while(!PIR1bits.SSP1IF);
    PIR1bits.SSP1IF = 0;
    control_bits_read_low = SSP1BUF; */
  //  SPI1_Close(); 
    SPI_CS_SetLow();
    writeString("w:");
    writeByte('\t');
    write1byteHex((addr4<<4) & 0b11110000);
    writeByte('\t');
    write1byteHex(0);
    writeByte('\t');
    writeString("r:");
    writeByte('\t');
    write1byteHex(control_bits_read_high);
    writeByte('\t');
    write1byteHex(control_bits_read_high);
    writeByte('\n');
}

void Step(direction dir, uint16_t num_steps, step_size size) {
    // we need 1 and 2 because breaths can be made up of two different step sizes

    __delay_ms(20); //for stability

    /***** set direction ****/
    setDirection(dir);

    /***** set steps *****/
    stepperSleep(false);
    setStepSize(size);
    
    DRV8711_SPI_read(CTRL_ADDR_DRV8711);

    uint16_t stepsCounter;
    for (stepsCounter = 0; stepsCounter < num_steps; stepsCounter++) { //on B1
        if (get_INTERRUPT_STEPPER_BREAK_FLAG()) {
            //INTERRUPT_BREAK_FLAG = false; <----- this flag needs to be reset higher up in the program
            break; //from for loop, thrown back to switch statement for new instruction
        } else {
            STEPPER_STEP_SetHigh();
            __delay_us(STEP_DELAY); //__delay_ms(1);// __delay_us(1150); //__delay_ms_debug(1);
            STEPPER_STEP_SetLow();
            __delay_us(STEP_DELAY); //__delay_ms(1);// __delay_us(1150); //__delay_ms_debug(1);
        }
    }
    if(stepsCounter == num_steps){
        // we finished all the steps, end of command
        EUSART1_Write(STEPPER_STOPPED_END_OF_CMD);
    }else{
        // we were interrupted - we don't know what by
    }
    stepperSleep(true);
    DRV8711_SPI_read(CTRL_ADDR_DRV8711);
}

void slowStepTest(void) {
    //CW
    setDirection(BACKWARDS);
    //Full Steps
    setStepSize(Full);
    stepperSleep(false);
    while (!get_INTERRUPT_STEPPER_BREAK_FLAG()) {
        STEPPER_STEP_SetHigh();
        __delay_ms(500);
        STEPPER_STEP_SetLow();
        __delay_ms(500);
    }
    stepperSleep(true);
}

void moveUntilZ(direction dir, step_size size) {
    stepperSleep(false);
    setDirection(dir);
    setStepSize(size); // Quarter
    while (get_INTERRUPT_STEPPER_BREAK_FLAG() == false) {
        //move stepper up told to stop
        // sending 'z' sets this true, will stop it
        STEPPER_STEP_SetHigh();
        __delay_us(STEP_DELAY_CALIBRATION);
        STEPPER_STEP_SetLow();
        __delay_us(STEP_DELAY_CALIBRATION);
    }
    stepperSleep(true);
}

// mason you might not use this function (leftover from Avthor)

void calibrate(void) {
    stepperSleep(false);
    /*CALIBRATION START*/
    set_INTERRUPT_STEPPER_BREAK_FLAG(false);
    setDirection(BACKWARDS); //Dir_SetLow() makes the bellows travel upwards
    setStepSize(Half); //Half Steps
    while (!get_INTERRUPT_STEPPER_BREAK_FLAG()) {
        //move stepper up until it hits the top, then it will go to the center and vent solenoid to 1ATM
        STEPPER_STEP_SetHigh();
        __delay_us(STEP_DELAY_CALIBRATION);
        STEPPER_STEP_SetLow();
        __delay_us(STEP_DELAY_CALIBRATION);
    }
    /*CALIBRATION END*/
    stepperSleep(true);
}

void inchForwards(step_size size) {
    Step(FORWARDS, (MOTOR_NUM_STEPS * 2 *  getMultiplier(size)), size); //2 revolutions
}

void inchBackwards(step_size size) {
    Step(BACKWARDS, (MOTOR_NUM_STEPS * 2 * getMultiplier(size)), size); //2 revolutions
}

void stepperSleep(bool in) {
    if (in) {
        control_bits &= ~1; // disables driver - the lowest bit 0
        STEPPER_SLEEP_SetLow();
    } else {
        control_bits |= 1; // enables driver - the lowest bit 1
        STEPPER_SLEEP_SetHigh();
    }
    DRV8711_SPI_CMD(CTRL_ADDR_DRV8711, control_bits);
}

bool stepperIsAsleep(void){
    if(STEPPER_SLEEP_LAT){
        // awake and likely stepping
        return false;
    }else{
        // asleep, not stepping
        return true;
    }
}

#define STEPPER_MS1_SetLow() __nop() // do nothing, placeholder
#define STEPPER_MS2_SetLow() __nop() // do nothing, placeholder
#define STEPPER_MS3_SetLow() __nop() // do nothing, placeholder
#define STEPPER_MS1_SetHigh() __nop() // do nothing, placeholder
#define STEPPER_MS2_SetHigh() __nop() // do nothing, placeholder
#define STEPPER_MS3_SetHigh() __nop() // do nothing, placeholder

void setStepSize(step_size size) {
    // for DRV8711, this is done over SPI
    uint8_t step_size_bits;
    switch (size) {
        case Full:
        {
            STEPPER_MS1_SetLow();
            STEPPER_MS2_SetLow();
            STEPPER_MS3_SetLow();
            step_size_bits = FULL_STEP_CNTRL_BITS;
            break;
        }
        case Half:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetLow();
            STEPPER_MS3_SetLow();
            step_size_bits = HALF_STEP_CNTRL_BITS;
            break;
        }
        case Quarter:
        {
            STEPPER_MS1_SetLow();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetLow();
            step_size_bits = QUARTER_STEP_CNTRL_BITS;
            break;
        }
        case Eighth:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetLow();
            step_size_bits = EIGHTH_STEP_CNTRL_BITS;
            break;
        }
        case Sixteenth:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetHigh();
            step_size_bits = SIXTEENTH_STEP_CNTRL_BITS;
            break;
        }
        case NullStep:
        default:
        {
            STEPPER_SLEEP_SetLow();
            //this is for when we want to
            //go slower than 16th steps; we split time
            //between 16ths and this state
            //ex: 80% sixteenth steps. 20% null steps
            return;
            break;
        }
    }
    control_bits = ((control_bits & 0b111110000111) | step_size_bits << 3);
    DRV8711_SPI_CMD(CTRL_ADDR_DRV8711, control_bits);
}

void setDirection(direction dir) {
    // DIR pin: LOW=CW, HIGH=CCW ---- verify this
    if (dir == FORWARDS) {
        //CW
        STEPPER_DIR_SetHigh();
    } else { //if(dir == BACKWARDS){
        //CCW
        STEPPER_DIR_SetLow();
    }
}


uint8_t getMultiplier(step_size size){
    uint16_t multiplier; // this is 16 bit for compatability because num_steps is 16 bit
    switch (size) {
        case Full:
        {
            multiplier = FULL_STEP_SIZE_MULTIPLIER;
            break;
        }
        case Half:
        {
            multiplier = HALF_STEP_SIZE_MULTIPLIER;
            break;
        }
        case Quarter:
        {
            multiplier = QUARTER_STEP_SIZE_MULTIPLIER;
            break;
        }
        case Eighth:
        {
            multiplier = EIGHTH_STEP_SIZE_MULTIPLIER;
            break;
        }
        case Sixteenth:
        {
            multiplier = SIXTEENTH_STEP_SIZE_MULTIPLIER;
            break;
        }
        default:
        {
            multiplier = 1; // no multiplier
            break;
        }
    }
    return multiplier;
}
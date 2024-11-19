#include "step.h"
#include "../mcc_generated_files/mcc.h"
#include "interrupt_manager.h"

void Step(direction dir, uint16_t num_steps, step_size size) {
    // we need 1 and 2 because breaths can be made up of two different step sizes

    __delay_ms(20); //for stability

    /* DIR pin: LOW=CW, HIGH=CCW 
     * steps: 
     * Full - MS1=LOW, MS2=LOW, MS3=LOW
     * Half - MS1=HIGH, MS2=LOW, MS3=LOW
     * Quarter - MS1=LOW, MS2=HIGH, MS3=LOW
     * Eighth - MS1=HIGH, MS2=HIGH, MS3=LOW
     * Sixteenth - MS1=HIGH, MS2=HIGH, MS3=HIGH
     */

    /***** set direction ****/
    setDirection(dir);

    /***** set steps *****/
    stepperSleep(false);
    setStepSize(size);

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
        EUSART2_Write(STEPPER_STOPPED_END_OF_CMD);
    }else{
        // we were interrupted - we don't know what by
    }
    stepperSleep(true);
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
    uint16_t multiplier; // this is 16 bit for compatability because num_steps is 16 bit
 /*   if ((Stepper.IS.RECEIVING_MOVING_COMMANDS) && (instr != MOVING_INSTRUCTIONS_CHAR)) {
        *Stepper.moving_instructions_pointer = instr;
        Stepper.moving_instructions_pointer++;
    } else {  */
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
  //  }
    Step(FORWARDS, (MOTOR_NUM_STEPS * 2 * multiplier), size); //2 revolutions
}

void inchBackwards(step_size size) {
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
    Step(BACKWARDS, (MOTOR_NUM_STEPS * 2 * multiplier), size); //2 revolutions
}

void stepperSleep(bool in) {
    if (in) {
        STEPPER_SLEEP_SetLow();
    } else {
        STEPPER_SLEEP_SetHigh();
    }
}

bool stepperIsAsleep(void){
    if(STEPPER_SLEEP_GetValue()){
        // awake and likely stepping
        return false;
    }else{
        // asleep, not stepping
        return true;
    }
}

void setStepSize(step_size size) {
    switch (size) {
        case Full:
        {
            STEPPER_MS1_SetLow();
            STEPPER_MS2_SetLow();
            STEPPER_MS3_SetLow();
            break;
        }
        case Half:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetLow();
            STEPPER_MS3_SetLow();
            break;
        }
        case Quarter:
        {
            STEPPER_MS1_SetLow();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetLow();
            break;
        }
        case Eighth:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetLow();
            break;
        }
        case Sixteenth:
        {
            STEPPER_MS1_SetHigh();
            STEPPER_MS2_SetHigh();
            STEPPER_MS3_SetHigh();
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
            break;
        }
    }
}

void setDirection(direction dir) {
    if (dir == FORWARDS) {
        //CW
        STEPPER_DIR_SetHigh();
    } else { //if(dir == BACKWARDS){
        //CCW
        STEPPER_DIR_SetLow();
    }
}
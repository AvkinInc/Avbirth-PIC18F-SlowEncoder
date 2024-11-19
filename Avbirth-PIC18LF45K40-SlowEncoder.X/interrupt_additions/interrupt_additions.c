#include "interrupt_additions.h"

// 'down' = backwards
#define cervixLimitSwitchTriggered() !RA6_GetValue() // cervix end
#define motorLimitSwitchTriggered() !RA4_GetValue() // motor end
// INT0 - A4 - Motor Limit Switch (falling edge)
// INT1 - A6 - Cervix Limit Switch (falling edge)
// INT2 - A7 - Encoder X in (rising edge - detecting pulse)

// careful! making these static so they can only be accessed from this file
static volatile uint8_t UART_RX_in; // holds incoming RX char
static volatile bool INTERRUPT_STEPPER_BREAK_FLAG;
static volatile interrupt_action interruptAction;

void interruptAdditionsInit(void){ 
    // UART 1
    //enable EUSART1 RX Interrupts
    PIE3bits.RC1IE = 1; 
    // reset flag to 0
    PIR3bits.RC1IF = 0;
    
    // reset external interrupt flags
    PIR0bits.INT0IF = 0;
    PIR0bits.INT1IF = 0;
    PIR0bits.INT2IF = 0;

    // init interruptAction
    interruptAction = NULL_ACTION;
}

bool get_INTERRUPT_STEPPER_BREAK_FLAG(void) {
    return INTERRUPT_STEPPER_BREAK_FLAG;
}

void set_INTERRUPT_STEPPER_BREAK_FLAG(bool in) {
    INTERRUPT_STEPPER_BREAK_FLAG = in;
}

uint8_t get_interruptAction(void) {
    return interruptAction;
}

void reset_interruptAction(void) {
    interruptAction = NULL_ACTION;
}

void readUART(void){
    /***** UART! *****/
    // UART RX! switch statement, decide what to do:
    UART_RX_in = EUSART1_Read();
    switch (UART_RX_in) {
        case 0x7A: 
        case 0x41: {
            // Stop All!!
            // also do this when we disconnect
            GENERAL_LED_SetHigh(); // off
            // pumps OFF
            setAmnioticOn(false);
            setBloodOn(false);
            setBloodPumpPWM(PWM_OFF_BLOOD);
            setAmnioticPumpPWM(PWM_OFF_AMNIOTIC);
            // if we return to a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            interruptAction = NULL_ACTION;
            if(!stepperIsAsleep()){
                // stepper is awake, that means we are interrupting a command
                EUSART1_Write(STEPPER_STOPPED_STOP_CMD);
            }
            break;
        /***** stepper actions ******/
        }case 0xE5: {
            // stepper stop
            GENERAL_LED_SetHigh(); // off
            // if we return to a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            interruptAction = NULL_ACTION;
            if(!stepperIsAsleep()){
                // stepper is awake, that means we are interrupting a command
                EUSART1_Write(STEPPER_STOPPED_STOP_CMD);
            }
            break;
        }case 0xD1: {
            // stepper forwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (cervixLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
            } else {
                interruptAction = STEPPER_FORWARD_UNTIL_STOP_FULL;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD2: {
            // stepper backwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (motorLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            } else {
                interruptAction = STEPPER_BACKWARD_UNTIL_STOP_FULL;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD3: {
            // stepper forwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (cervixLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
            } else {
                interruptAction = STEPPER_FORWARD_UNTIL_STOP_HALF;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD4: {
            // stepper backwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (motorLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            } else {
                interruptAction = STEPPER_BACKWARD_UNTIL_STOP_HALF;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xE6: {
            // stepper forwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (cervixLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
            } else {
                interruptAction = STEPPER_FORWARD_UNTIL_STOP_QUARTER;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xE7: {
            // stepper backwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (motorLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            } else {
                interruptAction = STEPPER_BACKWARD_UNTIL_STOP_QUARTER;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD5: {
            // stepper forwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (cervixLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
            } else {
                interruptAction = STEPPER_FORWARD_UNTIL_STOP_EIGHTH;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD6: {
            // stepper backwards until stop
            // if we are currently in a stepper function, this will stop it:v
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (motorLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            } else {
                interruptAction = STEPPER_BACKWARD_UNTIL_STOP_EIGHTH;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD7: {
            // stepper forwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (cervixLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
            } else {
                interruptAction = STEPPER_FORWARD_UNTIL_STOP_SIXTEENTH;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        }case 0xD8: {
            // stepper backwards until stop
            // if we are currently in a stepper function, this will stop it:
            INTERRUPT_STEPPER_BREAK_FLAG = true;
            // if the limit switch is still pressed, do not allow any more movement in that direction
            if (motorLimitSwitchTriggered()) {
                interruptAction = NULL_ACTION;
                EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            } else {
                interruptAction = STEPPER_BACKWARD_UNTIL_STOP_SIXTEENTH;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART1_Write(STEPPER_STOPPED_NEW_CMD);
                }
            }
            break;
        /***** pump actions ******/
        }case 0x10: {
            setBloodOn(false);
            setBloodPumpPWM(PWM_OFF_BLOOD);
            break;
        }case 0x11:{
            setBloodOn(true);
            setBloodPumpPWM(PWM_1_BLOOD);
            break;
        }case 0x12: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_2_BLOOD);
            break;
        }case 0x13: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_3_BLOOD);
            break;
        }case 0x14: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_4_BLOOD);
            break;
        }case 0x15: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_5_BLOOD);
            break;
        }case 0x16: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_6_BLOOD);
            break;
        }case 0x17: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_7_BLOOD); 
            break;
        }case 0x18: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_8_BLOOD);
            break;
        }case 0x19: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_9_BLOOD);
            break;
        }case 0x1A: {
            setBloodOn(true);
            setBloodPumpPWM(PWM_10_BLOOD);
            break;   
        }case 0x1B: {
            setAmnioticOn(false);
            setAmnioticPumpPWM(PWM_OFF_AMNIOTIC);
            break;
        }case 0x1C: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_1_AMNIOTIC);
            break;
        }case 0x1D: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_2_AMNIOTIC);
            break;
        }case 0x1E: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_3_AMNIOTIC);
            break; 
        }case 0x1F: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_4_AMNIOTIC);
            break;  
        }case 0x20: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_5_AMNIOTIC);
            break;
        }case 0x21: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_6_AMNIOTIC);
            break; 
        }case 0x22: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_7_AMNIOTIC); 
            break;
        }case 0x23: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_8_AMNIOTIC); 
            break;
        }case 0x24: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_9_AMNIOTIC);
            break;
        }case 0x25: {
            setAmnioticOn(true);
            setAmnioticPumpPWM(PWM_10_AMNIOTIC); 
            break;
        }default: {
            break;
        }
    }
}

void motorLimitSwitchTrigger(void){
    EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
    resetEncoderTicks();
    set_INTERRUPT_STEPPER_BREAK_FLAG(true);
    reset_interruptAction();
  //  GENERAL_LED_SetHigh();
}

void cervixLimitSwitchTrigger(void){
    EUSART1_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
    set_INTERRUPT_STEPPER_BREAK_FLAG(true);
    reset_interruptAction();
   // GENERAL_LED_SetHigh();
}

/*
 
case 0x7A: Stop All!!
case 0xE5: stepper stop
case 0xD1: STEPPER_FORWARD_UNTIL_STOP_FULL
case 0xD2: STEPPER_BACKWARD_UNTIL_STOP_FULL
case 0xD3: STEPPER_FORWARD_UNTIL_STOP_HALF
case 0xD4: STEPPER_BACKWARD_UNTIL_STOP_HALF
case 0xE6: STEPPER_FORWARD_UNTIL_STOP_QUARTER
case 0xE7: STEPPER_BACKWARD_UNTIL_STOP_QUARTER
case 0xD5: STEPPER_FORWARD_UNTIL_STOP_EIGHTH
case 0xD6: STEPPER_BACKWARD_UNTIL_STOP_EIGHTH
case 0xD7: STEPPER_FORWARD_UNTIL_STOP_SIXTEENTH
case 0xD8: STEPPER_BACKWARD_UNTIL_STOP_SIXTEENTH
case 0xDA: STEPPER_INCH_FORWARD_FULL
case 0xDB: STEPPER_INCH_BACKWARD_FULL
case 0xDC: STEPPER_INCH_FORWARD_HALF
case 0xDD: STEPPER_INCH_BACKWARD_HALF
case 0xF6: STEPPER_INCH_FORWARD_QUARTER
case 0xF7: STEPPER_INCH_BACKWARD_QUARTER
case 0xDE: STEPPER_INCH_FORWARD_EIGHTH
case 0xDF: STEPPER_INCH_BACKWARD_EIGHTH
case 0xFA: STEPPER_INCH_FORWARD_SIXTEENTH
case 0xFB: STEPPER_INCH_BACKWARD_SIXTEENTH
 
 */
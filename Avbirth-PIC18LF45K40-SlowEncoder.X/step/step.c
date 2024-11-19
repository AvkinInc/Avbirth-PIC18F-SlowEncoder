#include "step.h"

void moveUntilZ(direction dir, step_size size) {
    setDirection(dir);
    setStepSize(size); // Quarter
    stepperSleep(false);
    STEPS_GO_SetHigh();
    while (get_INTERRUPT_STEPPER_BREAK_FLAG() == false) {} // wait
        //move stepper up told to stop
        // sending 'z' sets this true, will stop it
   /*     STEPPER_STEP_SetHigh();
        __delay_us(STEP_DELAY_CALIBRATION);
        STEPPER_STEP_SetLow();
        __delay_us(STEP_DELAY_CALIBRATION);    */
  //  }
    STEPS_GO_SetLow();
    stepperSleep(true);
}

void stepperSleep(bool in) {
    if (in) {
        STEPPER_SLEEP_SetLow();
    } else {
        STEPPER_SLEEP_SetHigh();
    }
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
#include "step.h"
#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/interrupt_manager.h"
#include "../EUSART_Helpers/EUSART_Helpers.h"
#include "../encoder/encoder.h"

/* NOTE: this is not as exact as moving by steps, 
 * since the step resolution is 200 for Full steps, 400 for Half, etc.
 * and 8 for ticks for the X channel of the encoder
 * The A channel is more precise, but I do not think we need that much precision
 * since the app only calls moveUntilZ() (Step() is only used for testing)
 * ***** We do not used Step() in birthing - only move until z
 * */

void moveUntilZ(direction dir, step_size size) {
    setDirection(dir);
    setStepSize(size); // Quarter
    stepperSleep(false);
    TURN_ON_555_SetHigh();
    while (get_INTERRUPT_STEPPER_BREAK_FLAG() == false) {} // wait
        //move stepper up told to stop
        // sending 'z' sets this true, will stop it
   /*     STEPPER_STEP_SetHigh();
        __delay_us(STEP_DELAY_CALIBRATION);
        STEPPER_STEP_SetLow();
        __delay_us(STEP_DELAY_CALIBRATION);    */
  //  }
    TURN_ON_555_SetLow();
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
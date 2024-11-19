#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "../EUSART_Helpers/EUSART_Helpers.h"
#include <stdint.h>
#include <stdbool.h>
#include "../step/step.h"
#include "../encoder/encoder.h"
#include "../pumps/pumps.h"
#include "mcc.h"

#ifndef INTERRUPT_ADDITIONS_H
#define INTERRUPT_ADDITIONS_H

// we create interrupt actions for things we want to happen that are not instantaneous
// meaning they cannot be done in the ISR --> need ot be done in main so they dont block another ISR
// ex: stepper motor moving 2 revolutions
// do not use this for instantaneous actions, those are done in the ISR
// ex: turning on a pump
typedef enum {
    NULL_ACTION, // do nothing/init
    STEPPER_STOP,
    STEPPER_FORWARD_UNTIL_STOP_FULL,
    STEPPER_BACKWARD_UNTIL_STOP_FULL,
    STEPPER_FORWARD_UNTIL_STOP_HALF,
    STEPPER_BACKWARD_UNTIL_STOP_HALF,
    STEPPER_FORWARD_UNTIL_STOP_QUARTER,
    STEPPER_BACKWARD_UNTIL_STOP_QUARTER,
    STEPPER_FORWARD_UNTIL_STOP_EIGHTH,
    STEPPER_BACKWARD_UNTIL_STOP_EIGHTH,
    STEPPER_FORWARD_UNTIL_STOP_SIXTEENTH,
    STEPPER_BACKWARD_UNTIL_STOP_SIXTEENTH,
}interrupt_action;

void interruptAdditionsInit(void);
// INTERRUPT_STEPPER_BREAK_FLAG is used for breaking out of the stepper motor action
bool get_INTERRUPT_STEPPER_BREAK_FLAG(void);
void set_INTERRUPT_STEPPER_BREAK_FLAG(bool in);
uint8_t get_interruptAction(void);
void reset_interruptAction(void);
void readUART(void);
void motorLimitSwitchTrigger(void);
void cervixLimitSwitchTrigger(void);
// encoder trigger in in encoder.c

#endif  // INTERRUPT_ADDITIONS_H
/**
 End of File
*/

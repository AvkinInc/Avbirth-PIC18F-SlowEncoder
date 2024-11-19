/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F23K22
        Driver Version    :  2.04
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB 	          :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "interrupt_manager.h"
#include "mcc.h"
#include "../step/step.h"
#include "eusart2.h"
#include "../pumps/pumps.h"
#include "../encoder/encoder.h"

#define cervixLimitSwitchTriggered() !RB1_GetValue() // cervix end
#define motorLimitSwitchTriggered() !RB2_GetValue() // motor end
// INT1/B1 is motor
// INT2/B2 is cervix

// careful! making these static so they can only be accessed from this file
static volatile uint8_t UART_RX_in; // holds incoming RX char
static volatile bool INTERRUPT_STEPPER_BREAK_FLAG;
static volatile interrupt_action interruptAction;

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

void INTERRUPT_Initialize(void) {
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    RCONbits.IPEN = 0;

    /*
    // UART 1
    //enable EUSART1 RX Interrupts
    PIE1bits.RC1IE = 1; 
    // reset flag to 0
    PIR1bits.RC1IF = 0; */
    
    // UART 2
    //enable EUSART1 RX Interrupts
    PIE3bits.RC2IE = 1; 
    // reset flag to 0
    PIR3bits.RC2IF = 0;
    
    // reset external interrupt flags
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT2IF = 0;

    // init interruptAction
    interruptAction = NULL_ACTION;
}

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCON3bits.INT1IE == 1 && INTCON3bits.INT1IF == 1)
    {
        // motor/back limit switch
        INT1_ISR();
      //  if(!stepperIsAsleep()){
            // stepper is awake, that means we are interrupting a command
            EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
            resetEncoderTicks();
      //  }
    }
    else if(INTCON3bits.INT2IE == 1 && INTCON3bits.INT2IF == 1)
    {
        // cervix/front limit switch
        INT2_ISR();
      //  if(!stepperIsAsleep()){
            // stepper is awake, that means we are interrupting a command
            EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
     //   }
    }else if (EUSART2_is_rx_ready()) {
        /***** UART! *****/
        // UART RX! switch statement, decide what to do:
        UART_RX_in = EUSART2_Read();
        switch (UART_RX_in) {
            case 0x7A: 
            case 0x41: {
                // Stop All!!
                // also do this when we disconnect
                // pumps OFF
                setBloodPumpPWM(PWM_OFF);
                setAmnioticPumpPWM(PWM_OFF);
                // if we return to a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                interruptAction = NULL_ACTION;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART2_Write(STEPPER_STOPPED_STOP_CMD);
                }
                break;
            /***** stepper actions ******/
            }case 0xE5: {
                // stepper stop
                // if we return to a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                interruptAction = NULL_ACTION;
                if(!stepperIsAsleep()){
                    // stepper is awake, that means we are interrupting a command
                    EUSART2_Write(STEPPER_STOPPED_STOP_CMD);
                }
                break;
            }case 0xD1: {
                // stepper up until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_FORWARD_UNTIL_STOP_FULL;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD2: {
                // stepper down until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_BACKWARD_UNTIL_STOP_FULL;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD3: {
                // stepper up until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_FORWARD_UNTIL_STOP_HALF;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD4: {
                // stepper down until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_BACKWARD_UNTIL_STOP_HALF;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xE6: {
                // stepper up until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_FORWARD_UNTIL_STOP_QUARTER;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xE7: {
                // go home function
                // stepper backwards until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_BACKWARD_UNTIL_STOP_QUARTER;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD5: {
                // stepper up until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_FORWARD_UNTIL_STOP_EIGHTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD6: {
                // stepper down until stop
                // if we are currently in a stepper function, this will stop it:v
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_BACKWARD_UNTIL_STOP_EIGHTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD7: {
                // stepper up until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_FORWARD_UNTIL_STOP_SIXTEENTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xD8: {
                // stepper down until stop
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_BACKWARD_UNTIL_STOP_SIXTEENTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            /***** pump actions ******/
            }case 0x10: {
                // Pump 1 OFF
                setBloodPumpPWM(PWM_OFF);
                break;
            }case 0x11: {
                // Pump 1 ON, 10%
                setBloodPumpPWM(PWM_1);
                break;
            }case 0x12: {
                // Pump 1 ON, 20%
                setBloodPumpPWM(PWM_2);
                break;
            }case 0x13: {
                // Pump 1 ON, 30%
                setBloodPumpPWM(PWM_3);
                break;
            }case 0x14: {
                // Pump 1 ON, 40%
                setBloodPumpPWM(PWM_4);
                break;
            }case 0x15: {
                // Pump 1 ON, 50%
                setBloodPumpPWM(PWM_5);
                break;
            }case 0x16: {
                // Pump 1 ON, 60%
                setBloodPumpPWM(PWM_6);
                break;
            }case 0x17: {
                // Pump 1 ON, 70%
                setBloodPumpPWM(PWM_7);
                break;
            }case 0x18: {
                // Pump 1 ON, 80%
                setBloodPumpPWM(PWM_8);
                break;
            }case 0x19: {
                // Pump 1 ON, 90%
                setBloodPumpPWM(PWM_9);
                break;
            }case 0x1A: {
                // Pump 1 ON, 100%
                setBloodPumpPWM(PWM_10);
                break;
           }case 0x1B: {
                // Pump 2 OFF
                setAmnioticPumpPWM(PWM_OFF);
                break;
            }case 0x1C: {
                // Pump 2 ON, 10%
                setAmnioticPumpPWM(PWM_1);
                break;
            }case 0x1D: {
                // Pump 2 ON, 20%
                setAmnioticPumpPWM(PWM_2);
                break;
            }case 0x1E: {
                // Pump 2 ON, 30%
                setAmnioticPumpPWM(PWM_3);
                break;
            }case 0x1F: {
                // Pump 2 ON, 40%
                setAmnioticPumpPWM(PWM_4);
                break;
            }case 0x20: {
                // Pump 2 ON, 50%
                setAmnioticPumpPWM(PWM_5);
                break;
            }case 0x21: {
                // Pump 2 ON, 60%
                setAmnioticPumpPWM(PWM_6);
                break;
            }case 0x22: {
                // Pump 2 ON, 70%
                setAmnioticPumpPWM(PWM_7);
                break;
            }case 0x23: {
                // Pump 2 ON, 80%
                setAmnioticPumpPWM(PWM_8);
                break;
            }case 0x24: {
                // Pump 2 ON, 90%
                setAmnioticPumpPWM(PWM_9);
                break;
            }case 0x25: {
                // Pump 2 ON, 100%
                setAmnioticPumpPWM(PWM_10);
                break;
            }default: {
                break;
            }
        }
    }
    else if(INTCONbits.RBIE == 1 && INTCONbits.RBIF == 1)
    {
        // reset flag and return
      //  INTCONbits.RBIF = 0;
      //  return;
        PIN_MANAGER_IOC();
    }
    else
    {
        //Unhandled Interrupt
    }
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


/**
 End of File
*/

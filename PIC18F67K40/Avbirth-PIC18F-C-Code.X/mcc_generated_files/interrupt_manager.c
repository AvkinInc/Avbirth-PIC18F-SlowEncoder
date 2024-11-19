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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F67K40
        Driver Version    :  1.03
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45 or later
        MPLAB 	          :  MPLAB X 4.15
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

#define cervixLimitSwitchTriggered() !RB0_GetValue() // cervix end
#define motorLimitSwitchTriggered() !RB1_GetValue() // motor end

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
    INTCONbits.IPEN = 0;

    // UART 2
    //enable EUSART1 RX Interrupts
    PIE3bits.RC2IE = 1; //PIE3 in PIC18F67K40
    // reset flag to 0
    PIR3bits.RC2IF = 0;
    
    // reset external interrupt flags
    PIR0bits.INT0IF = 0;
    PIR0bits.INT1IF = 0;
    PIR0bits.INT2IF = 0;
    PIR0bits.INT3IF = 0;

    // init interruptAction
    interruptAction = NULL_ACTION;
}

void __interrupt() INTERRUPT_InterruptManager(void) {
    // interrupt handler
    if (PIE0bits.TMR0IE == 1 && PIR0bits.TMR0IF == 1) {
        TMR0_ISR();
    }else if (EUSART2_is_rx_ready()) {
        /***** UART! *****/
        // UART RX! switch statement, decide what to do:
        UART_RX_in = EUSART2_Read();
        switch (UART_RX_in) {
            case 0x7A: {
                // Stop All!!
                // pumps OFF
                setPump1PWM(PWM_OFF);
                setPump2PWM(PWM_OFF);
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
                if (cervixLimitSwitchTriggered()) {
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
                if (motorLimitSwitchTriggered()) {
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
                if (cervixLimitSwitchTriggered()) {
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
                if (motorLimitSwitchTriggered()) {
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
                if (cervixLimitSwitchTriggered()) {
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
                if (motorLimitSwitchTriggered()) {
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
                if (cervixLimitSwitchTriggered()) {
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
                if (motorLimitSwitchTriggered()) {
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
                if (cervixLimitSwitchTriggered()) {
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
                if (motorLimitSwitchTriggered()) {
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
            }case 0xDA: {
                // stepper inch up
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_INCH_FORWARD_FULL;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xDB: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_INCH_BACKWARD_FULL;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xDC: {
                // stepper inch up
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_INCH_FORWARD_HALF;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xDD: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_INCH_BACKWARD_HALF;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xF6:  {
                // stepper inch up
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if(cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_INCH_FORWARD_QUARTER;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xF7: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_INCH_BACKWARD_QUARTER;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xDE:  {
                // stepper inch up
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_INCH_FORWARD_EIGHTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xDF: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_INCH_BACKWARD_EIGHTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xFA: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (cervixLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
                } else {
                    interruptAction = STEPPER_INCH_FORWARD_SIXTEENTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            }case 0xFB: {
                // stepper inch down
                // if we are currently in a stepper function, this will stop it:
                INTERRUPT_STEPPER_BREAK_FLAG = true;
                // if the limit switch is still pressed, do not allow any more movement in that direction
                if (motorLimitSwitchTriggered()) {
                    interruptAction = NULL_ACTION;
                    EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
                } else {
                    interruptAction = STEPPER_INCH_BACKWARD_SIXTEENTH;
                    if(!stepperIsAsleep()){
                        // stepper is awake, that means we are interrupting a command
                        EUSART2_Write(STEPPER_STOPPED_NEW_CMD);
                    }
                }
                break;
            /***** pump actions ******/
            }case 0x10: {
                // Pump 1 OFF
                setPump1PWM(PWM_OFF);
                break;
            }case 0x11: {
                // Pump 1 ON, 10%
                setPump1PWM(PWM_1);
                break;
            }case 0x12: {
                // Pump 1 ON, 20%
                setPump1PWM(PWM_2);
                break;
            }case 0x13: {
                // Pump 1 ON, 30%
                setPump1PWM(PWM_3);
                break;
            }case 0x14: {
                // Pump 1 ON, 40%
                setPump1PWM(PWM_4);
                break;
            }case 0x15: {
                // Pump 1 ON, 50%
                setPump1PWM(PWM_5);
                break;
            }case 0x16: {
                // Pump 1 ON, 60%
                setPump1PWM(PWM_6);
                break;
            }case 0x17: {
                // Pump 1 ON, 70%
                setPump1PWM(PWM_7);
                break;
            }case 0x18: {
                // Pump 1 ON, 80%
                setPump1PWM(PWM_8);
                break;
            }case 0x19: {
                // Pump 1 ON, 90%
                setPump1PWM(PWM_9);
                break;
            }case 0x1A: {
                // Pump 1 ON, 100%
                setPump1PWM(PWM_10);
                break;
           }case 0x1B: {
                // Pump 2 OFF
                setPump2PWM(PWM_OFF);
                break;
            }case 0x1C: {
                // Pump 2 ON, 10%
                setPump2PWM(PWM_1);
                break;
            }case 0x1D: {
                // Pump 2 ON, 20%
                setPump2PWM(PWM_2);
                break;
            }case 0x1E: {
                // Pump 2 ON, 30%
                setPump2PWM(PWM_3);
                break;
            }case 0x1F: {
                // Pump 2 ON, 40%
                setPump2PWM(PWM_4);
                break;
            }case 0x20: {
                // Pump 2 ON, 50%
                setPump2PWM(PWM_5);
                break;
            }case 0x21: {
                // Pump 2 ON, 60%
                setPump2PWM(PWM_6);
                break;
            }case 0x22: {
                // Pump 2 ON, 70%
                setPump2PWM(PWM_7);
                break;
            }case 0x23: {
                // Pump 2 ON, 80%
                setPump2PWM(PWM_8);
                break;
            }case 0x24: {
                // Pump 2 ON, 90%
                setPump2PWM(PWM_9);
                break;
            }case 0x25: {
                // Pump 2 ON, 100%
                setPump2PWM(PWM_10);
                break;
            }default: {
                break;
            }
        }
    // these call the ISRs for the external interrupts - we use Ext Ints 0 and 1 for the stepper motor limit switches
    } else if (PIE0bits.INT0IE == 1 && PIR0bits.INT0IF == 1) {
        INT0_ISR();
        if(!stepperIsAsleep()){
            // stepper is awake, that means we are interrupting a command
            EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_CERVIX);
        }
    } else if (PIE0bits.INT1IE == 1 && PIR0bits.INT1IF == 1) {
        INT1_ISR();
        if(!stepperIsAsleep()){
            // stepper is awake, that means we are interrupting a command
            EUSART2_Write(STEPPER_STOPPED_END_OF_TRAVEL_MOTOR);
        }
    } else if (PIE0bits.INT2IE == 1 && PIR0bits.INT2IF == 1) {
        INT2_ISR();
    } else if(PIE0bits.INT3IE == 1 && PIR0bits.INT3IF == 1) {
        INT3_ISR();
    }else if(INTCONbits.PEIE == 1){
        if(PIE1bits.ADIE == 1 && PIR1bits.ADIF == 1)
        {
            // we read the ADC conversion here
            ADCC_ISR();
        }    
        else if(PIE5bits.TMR4IE == 1 && PIR5bits.TMR4IF == 1)
        {
            // we start the ADC conversion here
            TMR4_ISR();
        }
    } else {
        //Unhandled Interrupt
    }
}
/**
 End of File
 */

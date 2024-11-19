/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

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

#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H


#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// we create interrupt actions for things we want to happen that are not instantaneous
// meaning they cannot be done in the ISR --> need ot be done in main so they dont block another ISR
// ex: stepper motor moving 2 revolutions
// do not use this for instantaneous actions, those are done in the ISR
// ex: turning on a pump
typedef enum {
    NULL_ACTION, // do nothing/init
    STEPPER_STOP,
    STEPPER_INCH_FORWARD_FULL,
    STEPPER_INCH_BACKWARD_FULL,
    STEPPER_INCH_FORWARD_HALF,
    STEPPER_INCH_BACKWARD_HALF,
    STEPPER_INCH_FORWARD_QUARTER,
    STEPPER_INCH_BACKWARD_QUARTER,
    STEPPER_INCH_FORWARD_EIGHTH,
    STEPPER_INCH_BACKWARD_EIGHTH,
    STEPPER_INCH_FORWARD_SIXTEENTH,
    STEPPER_INCH_BACKWARD_SIXTEENTH,
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

// INTERRUPT_STEPPER_BREAK_FLAG is used for breaking out of the stepper motor action
bool get_INTERRUPT_STEPPER_BREAK_FLAG(void);
void set_INTERRUPT_STEPPER_BREAK_FLAG(bool in);
uint8_t get_interruptAction(void);
void reset_interruptAction(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptEnable();
 */
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptDisable();
 */
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)
/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable peripheral interrupts.
 * @Example
    INTERRUPT_PeripheralInterruptEnable();
 */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable peripheral interrupts.
 * @Example
    INTERRUPT_PeripheralInterruptDisable();
 */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)
/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Main interrupt service routine. Calls module interrupt handlers.
 * @Example
    INTERRUPT_InterruptManager();
 */
void __interrupt() INTERRUPT_InterruptManager(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes PIC18 peripheral interrupt priorities; enables/disables priority vectors
 * @Example
    INTERRUPT_Initialize();
 */
void INTERRUPT_Initialize (void);

#endif  // INTERRUPT_MANAGER_H
/**
 End of File
*/
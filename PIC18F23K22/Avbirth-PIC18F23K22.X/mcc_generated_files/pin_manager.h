/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F23K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PUMP_AIN2_ALT aliases
#define PUMP_AIN2_ALT_TRIS                 TRISAbits.TRISA0
#define PUMP_AIN2_ALT_LAT                  LATAbits.LATA0
#define PUMP_AIN2_ALT_PORT                 PORTAbits.RA0
#define PUMP_AIN2_ALT_ANS                  ANSELAbits.ANSA0
#define PUMP_AIN2_ALT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PUMP_AIN2_ALT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PUMP_AIN2_ALT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PUMP_AIN2_ALT_GetValue()           PORTAbits.RA0
#define PUMP_AIN2_ALT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PUMP_AIN2_ALT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PUMP_AIN2_ALT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define PUMP_AIN2_ALT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set GENERAL_LED aliases
#define GENERAL_LED_TRIS                 TRISAbits.TRISA1
#define GENERAL_LED_LAT                  LATAbits.LATA1
#define GENERAL_LED_PORT                 PORTAbits.RA1
#define GENERAL_LED_ANS                  ANSELAbits.ANSA1
#define GENERAL_LED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define GENERAL_LED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define GENERAL_LED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define GENERAL_LED_GetValue()           PORTAbits.RA1
#define GENERAL_LED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define GENERAL_LED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define GENERAL_LED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define GENERAL_LED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set PUMP_STBY aliases
#define PUMP_STBY_TRIS                 TRISAbits.TRISA2
#define PUMP_STBY_LAT                  LATAbits.LATA2
#define PUMP_STBY_PORT                 PORTAbits.RA2
#define PUMP_STBY_ANS                  ANSELAbits.ANSA2
#define PUMP_STBY_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PUMP_STBY_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PUMP_STBY_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PUMP_STBY_GetValue()           PORTAbits.RA2
#define PUMP_STBY_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PUMP_STBY_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PUMP_STBY_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define PUMP_STBY_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set PUMP_BIN2 aliases
#define PUMP_BIN2_TRIS                 TRISAbits.TRISA5
#define PUMP_BIN2_LAT                  LATAbits.LATA5
#define PUMP_BIN2_PORT                 PORTAbits.RA5
#define PUMP_BIN2_ANS                  ANSELAbits.ANSA5
#define PUMP_BIN2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define PUMP_BIN2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define PUMP_BIN2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define PUMP_BIN2_GetValue()           PORTAbits.RA5
#define PUMP_BIN2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define PUMP_BIN2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define PUMP_BIN2_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define PUMP_BIN2_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set STEPPER_SLEEP aliases
#define STEPPER_SLEEP_TRIS                 TRISBbits.TRISB3
#define STEPPER_SLEEP_LAT                  LATBbits.LATB3
#define STEPPER_SLEEP_PORT                 PORTBbits.RB3
#define STEPPER_SLEEP_WPU                  WPUBbits.WPUB3
#define STEPPER_SLEEP_ANS                  ANSELBbits.ANSB3
#define STEPPER_SLEEP_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define STEPPER_SLEEP_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define STEPPER_SLEEP_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define STEPPER_SLEEP_GetValue()           PORTBbits.RB3
#define STEPPER_SLEEP_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define STEPPER_SLEEP_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define STEPPER_SLEEP_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define STEPPER_SLEEP_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set STEPPER_DIR aliases
#define STEPPER_DIR_TRIS                 TRISBbits.TRISB4
#define STEPPER_DIR_LAT                  LATBbits.LATB4
#define STEPPER_DIR_PORT                 PORTBbits.RB4
#define STEPPER_DIR_WPU                  WPUBbits.WPUB4
#define STEPPER_DIR_ANS                  ANSELBbits.ANSB4
#define STEPPER_DIR_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define STEPPER_DIR_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define STEPPER_DIR_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define STEPPER_DIR_GetValue()           PORTBbits.RB4
#define STEPPER_DIR_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define STEPPER_DIR_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define STEPPER_DIR_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define STEPPER_DIR_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define STEPPER_DIR_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define STEPPER_DIR_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set ENCODER_IN aliases
#define ENCODER_IN_TRIS                 TRISBbits.TRISB5
#define ENCODER_IN_LAT                  LATBbits.LATB5
#define ENCODER_IN_PORT                 PORTBbits.RB5
#define ENCODER_IN_WPU                  WPUBbits.WPUB5
#define ENCODER_IN_ANS                  ANSELBbits.ANSB5
#define ENCODER_IN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define ENCODER_IN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define ENCODER_IN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define ENCODER_IN_GetValue()           PORTBbits.RB5
#define ENCODER_IN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define ENCODER_IN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define ENCODER_IN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define ENCODER_IN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define ENCODER_IN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define ENCODER_IN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)

// get/set PUMP_AIN2 aliases
#define PUMP_AIN2_TRIS                 TRISCbits.TRISC3
#define PUMP_AIN2_LAT                  LATCbits.LATC3
#define PUMP_AIN2_PORT                 PORTCbits.RC3
#define PUMP_AIN2_ANS                  ANSELCbits.ANSC3
#define PUMP_AIN2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PUMP_AIN2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PUMP_AIN2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PUMP_AIN2_GetValue()           PORTCbits.RC3
#define PUMP_AIN2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PUMP_AIN2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PUMP_AIN2_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PUMP_AIN2_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set STEPPER_MS1 aliases
#define STEPPER_MS1_TRIS                 TRISCbits.TRISC4
#define STEPPER_MS1_LAT                  LATCbits.LATC4
#define STEPPER_MS1_PORT                 PORTCbits.RC4
#define STEPPER_MS1_ANS                  ANSELCbits.ANSC4
#define STEPPER_MS1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define STEPPER_MS1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define STEPPER_MS1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define STEPPER_MS1_GetValue()           PORTCbits.RC4
#define STEPPER_MS1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define STEPPER_MS1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define STEPPER_MS1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define STEPPER_MS1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set TURN_ON_555 aliases
#define TURN_ON_555_TRIS                 TRISCbits.TRISC5
#define TURN_ON_555_LAT                  LATCbits.LATC5
#define TURN_ON_555_PORT                 PORTCbits.RC5
#define TURN_ON_555_ANS                  ANSELCbits.ANSC5
#define TURN_ON_555_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define TURN_ON_555_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define TURN_ON_555_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define TURN_ON_555_GetValue()           PORTCbits.RC5
#define TURN_ON_555_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define TURN_ON_555_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define TURN_ON_555_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define TURN_ON_555_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set STEPPER_MS2 aliases
#define STEPPER_MS2_TRIS                 TRISCbits.TRISC6
#define STEPPER_MS2_LAT                  LATCbits.LATC6
#define STEPPER_MS2_PORT                 PORTCbits.RC6
#define STEPPER_MS2_ANS                  ANSELCbits.ANSC6
#define STEPPER_MS2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define STEPPER_MS2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define STEPPER_MS2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define STEPPER_MS2_GetValue()           PORTCbits.RC6
#define STEPPER_MS2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define STEPPER_MS2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define STEPPER_MS2_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define STEPPER_MS2_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set STEPPER_MS3 aliases
#define STEPPER_MS3_TRIS                 TRISCbits.TRISC7
#define STEPPER_MS3_LAT                  LATCbits.LATC7
#define STEPPER_MS3_PORT                 PORTCbits.RC7
#define STEPPER_MS3_ANS                  ANSELCbits.ANSC7
#define STEPPER_MS3_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define STEPPER_MS3_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define STEPPER_MS3_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define STEPPER_MS3_GetValue()           PORTCbits.RC7
#define STEPPER_MS3_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define STEPPER_MS3_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define STEPPER_MS3_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define STEPPER_MS3_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCB5 pin functionality
 * @Example
    IOCB5_ISR();
 */
void IOCB5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCB5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCB5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCB5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCB5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCB5_SetInterruptHandler() method.
    This handler is called every time the IOCB5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(IOCB5_InterruptHandler);

*/
extern void (*IOCB5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCB5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCB5_SetInterruptHandler() method.
    This handler is called every time the IOCB5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(IOCB5_DefaultInterruptHandler);

*/
void IOCB5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
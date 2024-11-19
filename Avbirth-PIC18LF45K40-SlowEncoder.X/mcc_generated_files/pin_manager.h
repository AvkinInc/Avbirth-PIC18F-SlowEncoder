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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18LF45K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RA6_SetPullup()             do { WPUAbits.WPUA6 = 1; } while(0)
#define RA6_ResetPullup()           do { WPUAbits.WPUA6 = 0; } while(0)
#define RA6_SetAnalogMode()         do { ANSELAbits.ANSELA6 = 1; } while(0)
#define RA6_SetDigitalMode()        do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()              PORTAbits.RA7
#define RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()             do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()           do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode()         do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RA7_SetDigitalMode()        do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set AIN1 aliases
#define AIN1_TRIS                 TRISBbits.TRISB3
#define AIN1_LAT                  LATBbits.LATB3
#define AIN1_PORT                 PORTBbits.RB3
#define AIN1_WPU                  WPUBbits.WPUB3
#define AIN1_OD                   ODCONBbits.ODCB3
#define AIN1_ANS                  ANSELBbits.ANSELB3
#define AIN1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define AIN1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define AIN1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define AIN1_GetValue()           PORTBbits.RB3
#define AIN1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define AIN1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define AIN1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define AIN1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define AIN1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define AIN1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define AIN1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define AIN1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set GENERAL_LED aliases
#define GENERAL_LED_TRIS                 TRISCbits.TRISC2
#define GENERAL_LED_LAT                  LATCbits.LATC2
#define GENERAL_LED_PORT                 PORTCbits.RC2
#define GENERAL_LED_WPU                  WPUCbits.WPUC2
#define GENERAL_LED_OD                   ODCONCbits.ODCC2
#define GENERAL_LED_ANS                  ANSELCbits.ANSELC2
#define GENERAL_LED_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define GENERAL_LED_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define GENERAL_LED_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define GENERAL_LED_GetValue()           PORTCbits.RC2
#define GENERAL_LED_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define GENERAL_LED_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define GENERAL_LED_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define GENERAL_LED_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define GENERAL_LED_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define GENERAL_LED_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define GENERAL_LED_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define GENERAL_LED_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set STEPPER_MS3 aliases
#define STEPPER_MS3_TRIS                 TRISCbits.TRISC4
#define STEPPER_MS3_LAT                  LATCbits.LATC4
#define STEPPER_MS3_PORT                 PORTCbits.RC4
#define STEPPER_MS3_WPU                  WPUCbits.WPUC4
#define STEPPER_MS3_OD                   ODCONCbits.ODCC4
#define STEPPER_MS3_ANS                  ANSELCbits.ANSELC4
#define STEPPER_MS3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define STEPPER_MS3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define STEPPER_MS3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define STEPPER_MS3_GetValue()           PORTCbits.RC4
#define STEPPER_MS3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define STEPPER_MS3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define STEPPER_MS3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define STEPPER_MS3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define STEPPER_MS3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define STEPPER_MS3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define STEPPER_MS3_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define STEPPER_MS3_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set STEPPER_MS2 aliases
#define STEPPER_MS2_TRIS                 TRISCbits.TRISC5
#define STEPPER_MS2_LAT                  LATCbits.LATC5
#define STEPPER_MS2_PORT                 PORTCbits.RC5
#define STEPPER_MS2_WPU                  WPUCbits.WPUC5
#define STEPPER_MS2_OD                   ODCONCbits.ODCC5
#define STEPPER_MS2_ANS                  ANSELCbits.ANSELC5
#define STEPPER_MS2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define STEPPER_MS2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define STEPPER_MS2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define STEPPER_MS2_GetValue()           PORTCbits.RC5
#define STEPPER_MS2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define STEPPER_MS2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define STEPPER_MS2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define STEPPER_MS2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define STEPPER_MS2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define STEPPER_MS2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define STEPPER_MS2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define STEPPER_MS2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set STEPPER_MS1 aliases
#define STEPPER_MS1_TRIS                 TRISCbits.TRISC6
#define STEPPER_MS1_LAT                  LATCbits.LATC6
#define STEPPER_MS1_PORT                 PORTCbits.RC6
#define STEPPER_MS1_WPU                  WPUCbits.WPUC6
#define STEPPER_MS1_OD                   ODCONCbits.ODCC6
#define STEPPER_MS1_ANS                  ANSELCbits.ANSELC6
#define STEPPER_MS1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define STEPPER_MS1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define STEPPER_MS1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define STEPPER_MS1_GetValue()           PORTCbits.RC6
#define STEPPER_MS1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define STEPPER_MS1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define STEPPER_MS1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define STEPPER_MS1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define STEPPER_MS1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define STEPPER_MS1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define STEPPER_MS1_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define STEPPER_MS1_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set STEPS_GO aliases
#define STEPS_GO_TRIS                 TRISCbits.TRISC7
#define STEPS_GO_LAT                  LATCbits.LATC7
#define STEPS_GO_PORT                 PORTCbits.RC7
#define STEPS_GO_WPU                  WPUCbits.WPUC7
#define STEPS_GO_OD                   ODCONCbits.ODCC7
#define STEPS_GO_ANS                  ANSELCbits.ANSELC7
#define STEPS_GO_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define STEPS_GO_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define STEPS_GO_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define STEPS_GO_GetValue()           PORTCbits.RC7
#define STEPS_GO_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define STEPS_GO_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define STEPS_GO_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define STEPS_GO_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define STEPS_GO_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define STEPS_GO_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define STEPS_GO_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define STEPS_GO_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set STEPPER_DIR aliases
#define STEPPER_DIR_TRIS                 TRISDbits.TRISD2
#define STEPPER_DIR_LAT                  LATDbits.LATD2
#define STEPPER_DIR_PORT                 PORTDbits.RD2
#define STEPPER_DIR_WPU                  WPUDbits.WPUD2
#define STEPPER_DIR_OD                   ODCONDbits.ODCD2
#define STEPPER_DIR_ANS                  ANSELDbits.ANSELD2
#define STEPPER_DIR_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define STEPPER_DIR_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define STEPPER_DIR_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define STEPPER_DIR_GetValue()           PORTDbits.RD2
#define STEPPER_DIR_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define STEPPER_DIR_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define STEPPER_DIR_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define STEPPER_DIR_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define STEPPER_DIR_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define STEPPER_DIR_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define STEPPER_DIR_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define STEPPER_DIR_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set STEPPER_SLEEP aliases
#define STEPPER_SLEEP_TRIS                 TRISDbits.TRISD3
#define STEPPER_SLEEP_LAT                  LATDbits.LATD3
#define STEPPER_SLEEP_PORT                 PORTDbits.RD3
#define STEPPER_SLEEP_WPU                  WPUDbits.WPUD3
#define STEPPER_SLEEP_OD                   ODCONDbits.ODCD3
#define STEPPER_SLEEP_ANS                  ANSELDbits.ANSELD3
#define STEPPER_SLEEP_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define STEPPER_SLEEP_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define STEPPER_SLEEP_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define STEPPER_SLEEP_GetValue()           PORTDbits.RD3
#define STEPPER_SLEEP_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define STEPPER_SLEEP_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define STEPPER_SLEEP_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define STEPPER_SLEEP_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define STEPPER_SLEEP_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define STEPPER_SLEEP_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set RD4 procedures
#define RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define RD4_GetValue()              PORTDbits.RD4
#define RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define RD4_SetPullup()             do { WPUDbits.WPUD4 = 1; } while(0)
#define RD4_ResetPullup()           do { WPUDbits.WPUD4 = 0; } while(0)
#define RD4_SetAnalogMode()         do { ANSELDbits.ANSELD4 = 1; } while(0)
#define RD4_SetDigitalMode()        do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set BIN1 aliases
#define BIN1_TRIS                 TRISDbits.TRISD5
#define BIN1_LAT                  LATDbits.LATD5
#define BIN1_PORT                 PORTDbits.RD5
#define BIN1_WPU                  WPUDbits.WPUD5
#define BIN1_OD                   ODCONDbits.ODCD5
#define BIN1_ANS                  ANSELDbits.ANSELD5
#define BIN1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define BIN1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define BIN1_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define BIN1_GetValue()           PORTDbits.RD5
#define BIN1_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define BIN1_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define BIN1_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define BIN1_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define BIN1_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define BIN1_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define BIN1_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define BIN1_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set STBY aliases
#define STBY_TRIS                 TRISDbits.TRISD6
#define STBY_LAT                  LATDbits.LATD6
#define STBY_PORT                 PORTDbits.RD6
#define STBY_WPU                  WPUDbits.WPUD6
#define STBY_OD                   ODCONDbits.ODCD6
#define STBY_ANS                  ANSELDbits.ANSELD6
#define STBY_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define STBY_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define STBY_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define STBY_GetValue()           PORTDbits.RD6
#define STBY_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define STBY_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define STBY_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define STBY_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define STBY_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define STBY_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define STBY_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define STBY_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/
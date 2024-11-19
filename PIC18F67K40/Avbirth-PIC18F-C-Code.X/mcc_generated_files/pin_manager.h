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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F67K40
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set STEPPER_SLEEP aliases
#define STEPPER_SLEEP_TRIS                 TRISAbits.TRISA4
#define STEPPER_SLEEP_LAT                  LATAbits.LATA4
#define STEPPER_SLEEP_PORT                 PORTAbits.RA4
#define STEPPER_SLEEP_WPU                  WPUAbits.WPUA4
#define STEPPER_SLEEP_OD                   ODCONAbits.ODCA4
#define STEPPER_SLEEP_ANS                  ANSELAbits.ANSELA4
#define STEPPER_SLEEP_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define STEPPER_SLEEP_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define STEPPER_SLEEP_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define STEPPER_SLEEP_GetValue()           PORTAbits.RA4
#define STEPPER_SLEEP_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define STEPPER_SLEEP_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define STEPPER_SLEEP_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define STEPPER_SLEEP_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define STEPPER_SLEEP_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define STEPPER_SLEEP_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set STEPPER_MS3 aliases
#define STEPPER_MS3_TRIS                 TRISAbits.TRISA5
#define STEPPER_MS3_LAT                  LATAbits.LATA5
#define STEPPER_MS3_PORT                 PORTAbits.RA5
#define STEPPER_MS3_WPU                  WPUAbits.WPUA5
#define STEPPER_MS3_OD                   ODCONAbits.ODCA5
#define STEPPER_MS3_ANS                  ANSELAbits.ANSELA5
#define STEPPER_MS3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define STEPPER_MS3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define STEPPER_MS3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define STEPPER_MS3_GetValue()           PORTAbits.RA5
#define STEPPER_MS3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define STEPPER_MS3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define STEPPER_MS3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define STEPPER_MS3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define STEPPER_MS3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define STEPPER_MS3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define STEPPER_MS3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define STEPPER_MS3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()               do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()                do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()                do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()       do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()      do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()               do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()                do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()                do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()       do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()      do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()               do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()                do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()                do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()       do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()      do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()               do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()                do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()                do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()       do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()      do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()               do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()                do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()                do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()       do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()      do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set STEPPER_DIR aliases
#define STEPPER_DIR_TRIS                 TRISCbits.TRISC0
#define STEPPER_DIR_LAT                  LATCbits.LATC0
#define STEPPER_DIR_PORT                 PORTCbits.RC0
#define STEPPER_DIR_WPU                  WPUCbits.WPUC0
#define STEPPER_DIR_OD                   ODCONCbits.ODCC0
#define STEPPER_DIR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define STEPPER_DIR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define STEPPER_DIR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define STEPPER_DIR_GetValue()           PORTCbits.RC0
#define STEPPER_DIR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define STEPPER_DIR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define STEPPER_DIR_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define STEPPER_DIR_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define STEPPER_DIR_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define STEPPER_DIR_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)

// get/set STEPPER_STEP aliases
#define STEPPER_STEP_TRIS                 TRISCbits.TRISC1
#define STEPPER_STEP_LAT                  LATCbits.LATC1
#define STEPPER_STEP_PORT                 PORTCbits.RC1
#define STEPPER_STEP_WPU                  WPUCbits.WPUC1
#define STEPPER_STEP_OD                   ODCONCbits.ODCC1
#define STEPPER_STEP_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define STEPPER_STEP_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define STEPPER_STEP_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define STEPPER_STEP_GetValue()           PORTCbits.RC1
#define STEPPER_STEP_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define STEPPER_STEP_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define STEPPER_STEP_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define STEPPER_STEP_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define STEPPER_STEP_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define STEPPER_STEP_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)

// get/set baby_out_fsr_channel aliases
#define baby_out_fsr_channel_TRIS                 TRISDbits.TRISD1
#define baby_out_fsr_channel_LAT                  LATDbits.LATD1
#define baby_out_fsr_channel_PORT                 PORTDbits.RD1
#define baby_out_fsr_channel_WPU                  WPUDbits.WPUD1
#define baby_out_fsr_channel_OD                   ODCONDbits.ODCD1
#define baby_out_fsr_channel_ANS                  ANSELDbits.ANSELD1
#define baby_out_fsr_channel_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define baby_out_fsr_channel_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define baby_out_fsr_channel_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define baby_out_fsr_channel_GetValue()           PORTDbits.RD1
#define baby_out_fsr_channel_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define baby_out_fsr_channel_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define baby_out_fsr_channel_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define baby_out_fsr_channel_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define baby_out_fsr_channel_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define baby_out_fsr_channel_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define baby_out_fsr_channel_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define baby_out_fsr_channel_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set channel_AN2 aliases
#define channel_AN2_TRIS                 TRISDbits.TRISD2
#define channel_AN2_LAT                  LATDbits.LATD2
#define channel_AN2_PORT                 PORTDbits.RD2
#define channel_AN2_WPU                  WPUDbits.WPUD2
#define channel_AN2_OD                   ODCONDbits.ODCD2
#define channel_AN2_ANS                  ANSELDbits.ANSELD2
#define channel_AN2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define channel_AN2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define channel_AN2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define channel_AN2_GetValue()           PORTDbits.RD2
#define channel_AN2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define channel_AN2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define channel_AN2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define channel_AN2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define channel_AN2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define channel_AN2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define channel_AN2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set RE0 procedures
#define RE0_SetHigh()               do { LATEbits.LATE0 = 1; } while(0)
#define RE0_SetLow()                do { LATEbits.LATE0 = 0; } while(0)
#define RE0_Toggle()                do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define RE0_GetValue()              PORTEbits.RE0
#define RE0_SetDigitalInput()       do { TRISEbits.TRISE0 = 1; } while(0)
#define RE0_SetDigitalOutput()      do { TRISEbits.TRISE0 = 0; } while(0)
#define RE0_SetPullup()             do { WPUEbits.WPUE0 = 1; } while(0)
#define RE0_ResetPullup()           do { WPUEbits.WPUE0 = 0; } while(0)
#define RE0_SetAnalogMode()         do { ANSELEbits.ANSELE0 = 1; } while(0)
#define RE0_SetDigitalMode()        do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RE1 procedures
#define RE1_SetHigh()               do { LATEbits.LATE1 = 1; } while(0)
#define RE1_SetLow()                do { LATEbits.LATE1 = 0; } while(0)
#define RE1_Toggle()                do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define RE1_GetValue()              PORTEbits.RE1
#define RE1_SetDigitalInput()       do { TRISEbits.TRISE1 = 1; } while(0)
#define RE1_SetDigitalOutput()      do { TRISEbits.TRISE1 = 0; } while(0)
#define RE1_SetPullup()             do { WPUEbits.WPUE1 = 1; } while(0)
#define RE1_ResetPullup()           do { WPUEbits.WPUE1 = 0; } while(0)
#define RE1_SetAnalogMode()         do { ANSELEbits.ANSELE1 = 1; } while(0)
#define RE1_SetDigitalMode()        do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set PUMP_AIN1 aliases
#define PUMP_AIN1_TRIS                 TRISFbits.TRISF2
#define PUMP_AIN1_LAT                  LATFbits.LATF2
#define PUMP_AIN1_PORT                 PORTFbits.RF2
#define PUMP_AIN1_WPU                  WPUFbits.WPUF2
#define PUMP_AIN1_OD                   ODCONFbits.ODCF2
#define PUMP_AIN1_ANS                  ANSELFbits.ANSELF2
#define PUMP_AIN1_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define PUMP_AIN1_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define PUMP_AIN1_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define PUMP_AIN1_GetValue()           PORTFbits.RF2
#define PUMP_AIN1_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define PUMP_AIN1_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define PUMP_AIN1_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define PUMP_AIN1_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define PUMP_AIN1_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define PUMP_AIN1_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define PUMP_AIN1_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define PUMP_AIN1_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set PUMP_AIN2 aliases
#define PUMP_AIN2_TRIS                 TRISFbits.TRISF3
#define PUMP_AIN2_LAT                  LATFbits.LATF3
#define PUMP_AIN2_PORT                 PORTFbits.RF3
#define PUMP_AIN2_WPU                  WPUFbits.WPUF3
#define PUMP_AIN2_OD                   ODCONFbits.ODCF3
#define PUMP_AIN2_ANS                  ANSELFbits.ANSELF3
#define PUMP_AIN2_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define PUMP_AIN2_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define PUMP_AIN2_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define PUMP_AIN2_GetValue()           PORTFbits.RF3
#define PUMP_AIN2_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define PUMP_AIN2_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define PUMP_AIN2_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define PUMP_AIN2_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define PUMP_AIN2_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define PUMP_AIN2_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define PUMP_AIN2_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define PUMP_AIN2_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set PUMP_BIN2 aliases
#define PUMP_BIN2_TRIS                 TRISGbits.TRISG1
#define PUMP_BIN2_LAT                  LATGbits.LATG1
#define PUMP_BIN2_PORT                 PORTGbits.RG1
#define PUMP_BIN2_WPU                  WPUGbits.WPUG1
#define PUMP_BIN2_OD                   ODCONGbits.ODCG1
#define PUMP_BIN2_ANS                  ANSELGbits.ANSELG1
#define PUMP_BIN2_SetHigh()            do { LATGbits.LATG1 = 1; } while(0)
#define PUMP_BIN2_SetLow()             do { LATGbits.LATG1 = 0; } while(0)
#define PUMP_BIN2_Toggle()             do { LATGbits.LATG1 = ~LATGbits.LATG1; } while(0)
#define PUMP_BIN2_GetValue()           PORTGbits.RG1
#define PUMP_BIN2_SetDigitalInput()    do { TRISGbits.TRISG1 = 1; } while(0)
#define PUMP_BIN2_SetDigitalOutput()   do { TRISGbits.TRISG1 = 0; } while(0)
#define PUMP_BIN2_SetPullup()          do { WPUGbits.WPUG1 = 1; } while(0)
#define PUMP_BIN2_ResetPullup()        do { WPUGbits.WPUG1 = 0; } while(0)
#define PUMP_BIN2_SetPushPull()        do { ODCONGbits.ODCG1 = 0; } while(0)
#define PUMP_BIN2_SetOpenDrain()       do { ODCONGbits.ODCG1 = 1; } while(0)
#define PUMP_BIN2_SetAnalogMode()      do { ANSELGbits.ANSELG1 = 1; } while(0)
#define PUMP_BIN2_SetDigitalMode()     do { ANSELGbits.ANSELG1 = 0; } while(0)

// get/set PUMP_BIN1 aliases
#define PUMP_BIN1_TRIS                 TRISGbits.TRISG3
#define PUMP_BIN1_LAT                  LATGbits.LATG3
#define PUMP_BIN1_PORT                 PORTGbits.RG3
#define PUMP_BIN1_WPU                  WPUGbits.WPUG3
#define PUMP_BIN1_OD                   ODCONGbits.ODCG3
#define PUMP_BIN1_ANS                  ANSELGbits.ANSELG3
#define PUMP_BIN1_SetHigh()            do { LATGbits.LATG3 = 1; } while(0)
#define PUMP_BIN1_SetLow()             do { LATGbits.LATG3 = 0; } while(0)
#define PUMP_BIN1_Toggle()             do { LATGbits.LATG3 = ~LATGbits.LATG3; } while(0)
#define PUMP_BIN1_GetValue()           PORTGbits.RG3
#define PUMP_BIN1_SetDigitalInput()    do { TRISGbits.TRISG3 = 1; } while(0)
#define PUMP_BIN1_SetDigitalOutput()   do { TRISGbits.TRISG3 = 0; } while(0)
#define PUMP_BIN1_SetPullup()          do { WPUGbits.WPUG3 = 1; } while(0)
#define PUMP_BIN1_ResetPullup()        do { WPUGbits.WPUG3 = 0; } while(0)
#define PUMP_BIN1_SetPushPull()        do { ODCONGbits.ODCG3 = 0; } while(0)
#define PUMP_BIN1_SetOpenDrain()       do { ODCONGbits.ODCG3 = 1; } while(0)
#define PUMP_BIN1_SetAnalogMode()      do { ANSELGbits.ANSELG3 = 1; } while(0)
#define PUMP_BIN1_SetDigitalMode()     do { ANSELGbits.ANSELG3 = 0; } while(0)

// get/set PUMP_STBY aliases
#define PUMP_STBY_TRIS                 TRISGbits.TRISG4
#define PUMP_STBY_LAT                  LATGbits.LATG4
#define PUMP_STBY_PORT                 PORTGbits.RG4
#define PUMP_STBY_WPU                  WPUGbits.WPUG4
#define PUMP_STBY_OD                   ODCONGbits.ODCG4
#define PUMP_STBY_ANS                  ANSELGbits.ANSELG4
#define PUMP_STBY_SetHigh()            do { LATGbits.LATG4 = 1; } while(0)
#define PUMP_STBY_SetLow()             do { LATGbits.LATG4 = 0; } while(0)
#define PUMP_STBY_Toggle()             do { LATGbits.LATG4 = ~LATGbits.LATG4; } while(0)
#define PUMP_STBY_GetValue()           PORTGbits.RG4
#define PUMP_STBY_SetDigitalInput()    do { TRISGbits.TRISG4 = 1; } while(0)
#define PUMP_STBY_SetDigitalOutput()   do { TRISGbits.TRISG4 = 0; } while(0)
#define PUMP_STBY_SetPullup()          do { WPUGbits.WPUG4 = 1; } while(0)
#define PUMP_STBY_ResetPullup()        do { WPUGbits.WPUG4 = 0; } while(0)
#define PUMP_STBY_SetPushPull()        do { ODCONGbits.ODCG4 = 0; } while(0)
#define PUMP_STBY_SetOpenDrain()       do { ODCONGbits.ODCG4 = 1; } while(0)
#define PUMP_STBY_SetAnalogMode()      do { ANSELGbits.ANSELG4 = 1; } while(0)
#define PUMP_STBY_SetDigitalMode()     do { ANSELGbits.ANSELG4 = 0; } while(0)

// get/set RG6 procedures
#define RG6_SetHigh()               do { LATGbits.LATG6 = 1; } while(0)
#define RG6_SetLow()                do { LATGbits.LATG6 = 0; } while(0)
#define RG6_Toggle()                do { LATGbits.LATG6 = ~LATGbits.LATG6; } while(0)
#define RG6_GetValue()              PORTGbits.RG6
#define RG6_SetDigitalInput()       do { TRISGbits.TRISG6 = 1; } while(0)
#define RG6_SetDigitalOutput()      do { TRISGbits.TRISG6 = 0; } while(0)
#define RG6_SetPullup()             do { WPUGbits.WPUG6 = 1; } while(0)
#define RG6_ResetPullup()           do { WPUGbits.WPUG6 = 0; } while(0)
#define RG6_SetAnalogMode()         do { ANSELGbits.ANSELG6 = 1; } while(0)
#define RG6_SetDigitalMode()        do { ANSELGbits.ANSELG6 = 0; } while(0)

// get/set RG7 procedures
#define RG7_SetHigh()               do { LATGbits.LATG7 = 1; } while(0)
#define RG7_SetLow()                do { LATGbits.LATG7 = 0; } while(0)
#define RG7_Toggle()                do { LATGbits.LATG7 = ~LATGbits.LATG7; } while(0)
#define RG7_GetValue()              PORTGbits.RG7
#define RG7_SetDigitalInput()       do { TRISGbits.TRISG7 = 1; } while(0)
#define RG7_SetDigitalOutput()      do { TRISGbits.TRISG7 = 0; } while(0)
#define RG7_SetPullup()             do { WPUGbits.WPUG7 = 1; } while(0)
#define RG7_ResetPullup()           do { WPUGbits.WPUG7 = 0; } while(0)
#define RG7_SetAnalogMode()         do { ANSELGbits.ANSELG7 = 1; } while(0)
#define RG7_SetDigitalMode()        do { ANSELGbits.ANSELG7 = 0; } while(0)

// get/set STEPPER_MS2 aliases
#define STEPPER_MS2_TRIS                 TRISHbits.TRISH0
#define STEPPER_MS2_LAT                  LATHbits.LATH0
#define STEPPER_MS2_PORT                 PORTHbits.RH0
#define STEPPER_MS2_WPU                  WPUHbits.WPUH0
#define STEPPER_MS2_OD                   ODCONHbits.ODCH0
#define STEPPER_MS2_SetHigh()            do { LATHbits.LATH0 = 1; } while(0)
#define STEPPER_MS2_SetLow()             do { LATHbits.LATH0 = 0; } while(0)
#define STEPPER_MS2_Toggle()             do { LATHbits.LATH0 = ~LATHbits.LATH0; } while(0)
#define STEPPER_MS2_GetValue()           PORTHbits.RH0
#define STEPPER_MS2_SetDigitalInput()    do { TRISHbits.TRISH0 = 1; } while(0)
#define STEPPER_MS2_SetDigitalOutput()   do { TRISHbits.TRISH0 = 0; } while(0)
#define STEPPER_MS2_SetPullup()          do { WPUHbits.WPUH0 = 1; } while(0)
#define STEPPER_MS2_ResetPullup()        do { WPUHbits.WPUH0 = 0; } while(0)
#define STEPPER_MS2_SetPushPull()        do { ODCONHbits.ODCH0 = 0; } while(0)
#define STEPPER_MS2_SetOpenDrain()       do { ODCONHbits.ODCH0 = 1; } while(0)

// get/set STEPPER_MS1 aliases
#define STEPPER_MS1_TRIS                 TRISHbits.TRISH1
#define STEPPER_MS1_LAT                  LATHbits.LATH1
#define STEPPER_MS1_PORT                 PORTHbits.RH1
#define STEPPER_MS1_WPU                  WPUHbits.WPUH1
#define STEPPER_MS1_OD                   ODCONHbits.ODCH1
#define STEPPER_MS1_SetHigh()            do { LATHbits.LATH1 = 1; } while(0)
#define STEPPER_MS1_SetLow()             do { LATHbits.LATH1 = 0; } while(0)
#define STEPPER_MS1_Toggle()             do { LATHbits.LATH1 = ~LATHbits.LATH1; } while(0)
#define STEPPER_MS1_GetValue()           PORTHbits.RH1
#define STEPPER_MS1_SetDigitalInput()    do { TRISHbits.TRISH1 = 1; } while(0)
#define STEPPER_MS1_SetDigitalOutput()   do { TRISHbits.TRISH1 = 0; } while(0)
#define STEPPER_MS1_SetPullup()          do { WPUHbits.WPUH1 = 1; } while(0)
#define STEPPER_MS1_ResetPullup()        do { WPUHbits.WPUH1 = 0; } while(0)
#define STEPPER_MS1_SetPushPull()        do { ODCONHbits.ODCH1 = 0; } while(0)
#define STEPPER_MS1_SetOpenDrain()       do { ODCONHbits.ODCH1 = 1; } while(0)

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
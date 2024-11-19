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
        Device            :  PIC18F67K40
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set dummy aliases
#define dummy_TRIS                 TRISBbits.TRISB2
#define dummy_LAT                  LATBbits.LATB2
#define dummy_PORT                 PORTBbits.RB2
#define dummy_WPU                  WPUBbits.WPUB2
#define dummy_OD                   ODCONBbits.ODCB2
#define dummy_ANS                  ANSELBbits.ANSELB2
#define dummy_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define dummy_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define dummy_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define dummy_GetValue()           PORTBbits.RB2
#define dummy_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define dummy_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define dummy_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define dummy_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define dummy_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define dummy_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define dummy_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define dummy_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RE0 procedures
#define RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define RE0_GetValue()              PORTEbits.RE0
#define RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define RE0_SetPullup()             do { WPUEbits.WPUE0 = 1; } while(0)
#define RE0_ResetPullup()           do { WPUEbits.WPUE0 = 0; } while(0)
#define RE0_SetAnalogMode()         do { ANSELEbits.ANSELE0 = 1; } while(0)
#define RE0_SetDigitalMode()        do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RE1 procedures
#define RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define RE1_GetValue()              PORTEbits.RE1
#define RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define RE1_SetPullup()             do { WPUEbits.WPUE1 = 1; } while(0)
#define RE1_ResetPullup()           do { WPUEbits.WPUE1 = 0; } while(0)
#define RE1_SetAnalogMode()         do { ANSELEbits.ANSELE1 = 1; } while(0)
#define RE1_SetDigitalMode()        do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set AIN1 aliases
#define AIN1_TRIS                 TRISFbits.TRISF2
#define AIN1_LAT                  LATFbits.LATF2
#define AIN1_PORT                 PORTFbits.RF2
#define AIN1_WPU                  WPUFbits.WPUF2
#define AIN1_OD                   ODCONFbits.ODCF2
#define AIN1_ANS                  ANSELFbits.ANSELF2
#define AIN1_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define AIN1_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define AIN1_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define AIN1_GetValue()           PORTFbits.RF2
#define AIN1_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define AIN1_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define AIN1_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define AIN1_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define AIN1_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define AIN1_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define AIN1_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define AIN1_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set AIN2 aliases
#define AIN2_TRIS                 TRISFbits.TRISF3
#define AIN2_LAT                  LATFbits.LATF3
#define AIN2_PORT                 PORTFbits.RF3
#define AIN2_WPU                  WPUFbits.WPUF3
#define AIN2_OD                   ODCONFbits.ODCF3
#define AIN2_ANS                  ANSELFbits.ANSELF3
#define AIN2_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define AIN2_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define AIN2_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define AIN2_GetValue()           PORTFbits.RF3
#define AIN2_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define AIN2_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define AIN2_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define AIN2_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define AIN2_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define AIN2_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define AIN2_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define AIN2_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set BIN2 aliases
#define BIN2_TRIS                 TRISGbits.TRISG1
#define BIN2_LAT                  LATGbits.LATG1
#define BIN2_PORT                 PORTGbits.RG1
#define BIN2_WPU                  WPUGbits.WPUG1
#define BIN2_OD                   ODCONGbits.ODCG1
#define BIN2_ANS                  ANSELGbits.ANSELG1
#define BIN2_SetHigh()            do { LATGbits.LATG1 = 1; } while(0)
#define BIN2_SetLow()             do { LATGbits.LATG1 = 0; } while(0)
#define BIN2_Toggle()             do { LATGbits.LATG1 = ~LATGbits.LATG1; } while(0)
#define BIN2_GetValue()           PORTGbits.RG1
#define BIN2_SetDigitalInput()    do { TRISGbits.TRISG1 = 1; } while(0)
#define BIN2_SetDigitalOutput()   do { TRISGbits.TRISG1 = 0; } while(0)
#define BIN2_SetPullup()          do { WPUGbits.WPUG1 = 1; } while(0)
#define BIN2_ResetPullup()        do { WPUGbits.WPUG1 = 0; } while(0)
#define BIN2_SetPushPull()        do { ODCONGbits.ODCG1 = 0; } while(0)
#define BIN2_SetOpenDrain()       do { ODCONGbits.ODCG1 = 1; } while(0)
#define BIN2_SetAnalogMode()      do { ANSELGbits.ANSELG1 = 1; } while(0)
#define BIN2_SetDigitalMode()     do { ANSELGbits.ANSELG1 = 0; } while(0)

// get/set BIN1 aliases
#define BIN1_TRIS                 TRISGbits.TRISG3
#define BIN1_LAT                  LATGbits.LATG3
#define BIN1_PORT                 PORTGbits.RG3
#define BIN1_WPU                  WPUGbits.WPUG3
#define BIN1_OD                   ODCONGbits.ODCG3
#define BIN1_ANS                  ANSELGbits.ANSELG3
#define BIN1_SetHigh()            do { LATGbits.LATG3 = 1; } while(0)
#define BIN1_SetLow()             do { LATGbits.LATG3 = 0; } while(0)
#define BIN1_Toggle()             do { LATGbits.LATG3 = ~LATGbits.LATG3; } while(0)
#define BIN1_GetValue()           PORTGbits.RG3
#define BIN1_SetDigitalInput()    do { TRISGbits.TRISG3 = 1; } while(0)
#define BIN1_SetDigitalOutput()   do { TRISGbits.TRISG3 = 0; } while(0)
#define BIN1_SetPullup()          do { WPUGbits.WPUG3 = 1; } while(0)
#define BIN1_ResetPullup()        do { WPUGbits.WPUG3 = 0; } while(0)
#define BIN1_SetPushPull()        do { ODCONGbits.ODCG3 = 0; } while(0)
#define BIN1_SetOpenDrain()       do { ODCONGbits.ODCG3 = 1; } while(0)
#define BIN1_SetAnalogMode()      do { ANSELGbits.ANSELG3 = 1; } while(0)
#define BIN1_SetDigitalMode()     do { ANSELGbits.ANSELG3 = 0; } while(0)

// get/set STBY aliases
#define STBY_TRIS                 TRISGbits.TRISG4
#define STBY_LAT                  LATGbits.LATG4
#define STBY_PORT                 PORTGbits.RG4
#define STBY_WPU                  WPUGbits.WPUG4
#define STBY_OD                   ODCONGbits.ODCG4
#define STBY_ANS                  ANSELGbits.ANSELG4
#define STBY_SetHigh()            do { LATGbits.LATG4 = 1; } while(0)
#define STBY_SetLow()             do { LATGbits.LATG4 = 0; } while(0)
#define STBY_Toggle()             do { LATGbits.LATG4 = ~LATGbits.LATG4; } while(0)
#define STBY_GetValue()           PORTGbits.RG4
#define STBY_SetDigitalInput()    do { TRISGbits.TRISG4 = 1; } while(0)
#define STBY_SetDigitalOutput()   do { TRISGbits.TRISG4 = 0; } while(0)
#define STBY_SetPullup()          do { WPUGbits.WPUG4 = 1; } while(0)
#define STBY_ResetPullup()        do { WPUGbits.WPUG4 = 0; } while(0)
#define STBY_SetPushPull()        do { ODCONGbits.ODCG4 = 0; } while(0)
#define STBY_SetOpenDrain()       do { ODCONGbits.ODCG4 = 1; } while(0)
#define STBY_SetAnalogMode()      do { ANSELGbits.ANSELG4 = 1; } while(0)
#define STBY_SetDigitalMode()     do { ANSELGbits.ANSELG4 = 0; } while(0)

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
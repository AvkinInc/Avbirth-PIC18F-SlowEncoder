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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set STEPPER_STEP aliases
#define STEPPER_STEP_TRIS                 TRISBbits.TRISB4
#define STEPPER_STEP_LAT                  LATBbits.LATB4
#define STEPPER_STEP_PORT                 PORTBbits.RB4
#define STEPPER_STEP_WPU                  WPUBbits.WPUB4
#define STEPPER_STEP_ANS                  ANSELBbits.ANSB4
#define STEPPER_STEP_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define STEPPER_STEP_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define STEPPER_STEP_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define STEPPER_STEP_GetValue()           PORTBbits.RB4
#define STEPPER_STEP_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define STEPPER_STEP_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define STEPPER_STEP_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define STEPPER_STEP_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define STEPPER_STEP_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define STEPPER_STEP_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set STEPPER_DIR aliases
#define STEPPER_DIR_TRIS                 TRISBbits.TRISB5
#define STEPPER_DIR_LAT                  LATBbits.LATB5
#define STEPPER_DIR_PORT                 PORTBbits.RB5
#define STEPPER_DIR_WPU                  WPUBbits.WPUB5
#define STEPPER_DIR_ANS                  ANSELBbits.ANSB5
#define STEPPER_DIR_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define STEPPER_DIR_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define STEPPER_DIR_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define STEPPER_DIR_GetValue()           PORTBbits.RB5
#define STEPPER_DIR_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define STEPPER_DIR_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define STEPPER_DIR_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define STEPPER_DIR_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define STEPPER_DIR_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define STEPPER_DIR_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)

// get/set STEPPER_SLEEP aliases
#define STEPPER_SLEEP_TRIS                 TRISCbits.TRISC1
#define STEPPER_SLEEP_LAT                  LATCbits.LATC1
#define STEPPER_SLEEP_PORT                 PORTCbits.RC1
#define STEPPER_SLEEP_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define STEPPER_SLEEP_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define STEPPER_SLEEP_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define STEPPER_SLEEP_GetValue()           PORTCbits.RC1
#define STEPPER_SLEEP_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define STEPPER_SLEEP_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set SPI_CS aliases
#define SPI_CS_TRIS                 TRISCbits.TRISC2
#define SPI_CS_LAT                  LATCbits.LATC2
#define SPI_CS_PORT                 PORTCbits.RC2
#define SPI_CS_ANS                  ANSELCbits.ANSC2
#define SPI_CS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SPI_CS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SPI_CS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SPI_CS_GetValue()           PORTCbits.RC2
#define SPI_CS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SPI_CS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SPI_CS_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SPI_CS_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

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
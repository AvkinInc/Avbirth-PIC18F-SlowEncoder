/**
  TMR4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.c

  @Summary
    This is the generated driver implementation file for the TMR4 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR4.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr4.h"
#include "mcc.h"

/**
  Section: Global Variables Definitions
*/

void (*TMR4_InterruptHandler)(void);

/**
  Section: TMR4 APIs
*/

void TMR4_Initialize(void)
{
    // Set TMR4 to the options selected in the User Interface

    // T4CS FOSC/4; 
    T4CLKCON = 0x01;

    // T4PSYNC Not Synchronized; T4MODE Software control; T4CKPOL Rising Edge; T4CKSYNC Not Synchronized; 
    T4HLT = 0x00;

    // T4RSEL T4CKIPPS pin; 
    T4RST = 0x00;

    // T4PR 124; 
    T4PR = 0x7C;

    // TMR4 0; 
    T4TMR = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR5bits.TMR4IF = 0;

    // Enabling TMR4 interrupt.
    PIE5bits.TMR4IE = 1;

    // Set Default Interrupt Handler
    TMR4_SetInterruptHandler(TMR4_DefaultInterruptHandler);

    // T4CKPS 1:1; T4OUTPS 1:16; TMR4ON on; 
    T4CON = 0x8F;
}

void TMR4_ModeSet(TMR4_HLT_MODE mode)
{
   // Configure different types HLT mode
    T4HLTbits.MODE = mode;
}

void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T4RSTbits.RSEL = reset;
}

void TMR4_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 1;
}

void TMR4_StartTimer(void)
{
    TMR4_Start();
}

void TMR4_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 0;
}

void TMR4_StopTimer(void)
{
    TMR4_Stop();
}

uint8_t TMR4_Counter8BitGet(void)
{
    uint8_t readVal;

    readVal = TMR4;

    return readVal;
}

uint8_t TMR4_ReadTimer(void)
{
    return TMR4_Counter8BitGet();
}

void TMR4_Counter8BitSet(uint8_t timerVal)
{
    // Write to the Timer4 register
    TMR4 = timerVal;
}

void TMR4_WriteTimer(uint8_t timerVal)
{
    TMR4_Counter8BitSet(timerVal);
}

void TMR4_Period8BitSet(uint8_t periodVal)
{
   PR4 = periodVal;
}

void TMR4_LoadPeriodRegister(uint8_t periodVal)
{
   TMR4_Period8BitSet(periodVal);
}

void TMR4_ISR(void)
{
    static volatile unsigned int CountCallBack = 0;

    // clear the TMR4 interrupt flag
    PIR5bits.TMR4IF = 0;

    // callback function - called every 200th pass
    if (++CountCallBack >= TMR4_INTERRUPT_TICKER_FACTOR)
    {
        // ticker function call
    TMR4_CallBack();

        // reset ticker counter
        CountCallBack = 0;
    }
}

void TMR4_CallBack(void)
{
    // Add your custom callback code here
    // this code executes every TMR4_INTERRUPT_TICKER_FACTOR periods of TMR4
    if(TMR4_InterruptHandler)
    {
        TMR4_InterruptHandler();
    }
}

void TMR4_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR4_InterruptHandler = InterruptHandler;
}

void TMR4_DefaultInterruptHandler(void){
    // add your TMR4 interrupt custom code
    // or set custom function using TMR4_SetInterruptHandler()
    ADCC_StartConversion(baby_out_fsr_channel);
    TMR4_Start();
}

/**
  End of File
*/
/**
  EUSART4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart4.c

  @Summary
    This is the generated driver implementation file for the EUSART4 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for EUSART4.
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
#include "eusart4.h"


/**
  Section: EUSART4 APIs
*/
void EUSART4_Initialize(void)
{
    // Set the EUSART4 module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD4CON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN disabled; ADDEN disabled; SREN disabled; 
    RC4STA = 0x80;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX4STA = 0x24;

    // SP4BRGL 207; 
    SP4BRGL = 0xCF;

    // SP4BRGH 0; 
    SP4BRGH = 0x00;


}

bool EUSART4_is_tx_ready(void)
{
    return (bool)(PIR4bits.TX4IF && TX4STAbits.TXEN);
}

bool EUSART4_is_rx_ready(void)
{
    return PIR4bits.RC4IF;
}

bool EUSART4_is_tx_done(void)
{
    return TX4STAbits.TRMT;
}

uint8_t EUSART4_Read(void)
{
    while(!PIR4bits.RC4IF)
    {
    }

    
    if(1 == RC4STAbits.OERR)
    {
        // EUSART4 error - restart

        RC4STAbits.CREN = 0; 
        RC4STAbits.CREN = 1; 
    }

    return RC4REG;
}

void EUSART4_Write(uint8_t txData)
{
    while(0 == PIR4bits.TX4IF)
    {
    }

    TX4REG = txData;    // Write the data byte to the USART.
}





/**
  End of File
*/

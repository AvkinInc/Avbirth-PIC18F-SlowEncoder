/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F67K40
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATF = 0x00;
    LATB = 0x0F;
    LATG = 0x00;
    LATC = 0x00;
    LATH = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0xFC;
    TRISF = 0x83;
    TRISA = 0xCF;
    TRISG = 0x85;
    TRISB = 0xBF;
    TRISH = 0x0C;
    TRISC = 0xFC;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0x86;
    ANSELB = 0x40;
    ANSELE = 0x00;
    ANSELG = 0x25;
    ANSELF = 0x80;
    ANSELA = 0xC0;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUF = 0x00;
    WPUE = 0x00;
    WPUB = 0x0F;
    WPUG = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;
    WPUH = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONF = 0x00;
    ODCONA = 0x00;
    ODCONG = 0x00;
    ODCONB = 0x00;
    ODCONH = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;





   
    
	
    INT1PPSbits.INT1PPS = 0x09;   //RB1->EXT_INT:INT1;    
    INT3PPSbits.INT3PPS = 0x0B;   //RB3->EXT_INT:INT3;    
    RB6PPS = 0x12;   //RB6->EUSART4:TX4;    
    RE1PPS = 0x06;   //RE1->CCP2:CCP2;    
    RE0PPS = 0x05;   //RE0->CCP1:CCP1;    
    INT0PPSbits.INT0PPS = 0x08;   //RB0->EXT_INT:INT0;    
    INT2PPSbits.INT2PPS = 0x0A;   //RB2->EXT_INT:INT2;    
    RX2PPSbits.RX2PPS = 0x37;   //RG7->EUSART2:RX2;    
    RG6PPS = 0x0E;   //RG6->EUSART2:TX2;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/
/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c 

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F23K22
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "step/step.h"
#include "pumps/pumps.h"
#include "./EUSART_Helpers/EUSART_Helpers.h"

#define PIC18F_SW_VERSION_NUMBER 4
//send these commands to BLE
#define SENDING_PIC18F_SW_version_number_flag 0xEB
void update_PIC18F_software_version_number(void);
void send_number(void);

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptDisable(); // until init is done
    
    initPumps();
    
    // enable weak pullups
    INTCON2bits.RBPU = 0;
    
    // writing status updates to UART2
  //  setUartFunction(EUSART2_Write)
    
 //   WPUB = 0x26; // give temp weak pullup to encoder detect pin
    
    stepperSleep(true); // stepper motor starts asleep
    
    __delay_ms(100); // wait for BGM220 to be able to receive UART
    update_PIC18F_software_version_number();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // check for interrupt actions that need our attention
        // put reset_interruptAction() in the action case if you only want it to happen once
        switch(get_interruptAction()){
            case STEPPER_FORWARD_UNTIL_STOP_FULL: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(FORWARDS, Full);
                break;
            }case STEPPER_BACKWARD_UNTIL_STOP_FULL: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(BACKWARDS, Full);
                break;
            }case STEPPER_FORWARD_UNTIL_STOP_HALF: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(FORWARDS, Half);
                break;
            }case STEPPER_BACKWARD_UNTIL_STOP_HALF: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(BACKWARDS, Half);
                break;
            }case STEPPER_FORWARD_UNTIL_STOP_QUARTER: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(FORWARDS, Quarter);
                break;
            }case STEPPER_BACKWARD_UNTIL_STOP_QUARTER: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(BACKWARDS, Quarter);
                break;
            }case STEPPER_FORWARD_UNTIL_STOP_EIGHTH: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(FORWARDS, Eighth);
                break;
            }case STEPPER_BACKWARD_UNTIL_STOP_EIGHTH: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(BACKWARDS, Eighth);
                break;
            }case STEPPER_FORWARD_UNTIL_STOP_SIXTEENTH: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(FORWARDS, Sixteenth);
                break;
            }case STEPPER_BACKWARD_UNTIL_STOP_SIXTEENTH: {
                reset_interruptAction();
                set_INTERRUPT_STEPPER_BREAK_FLAG(false); // if it was stopped beforehand
                moveUntilZ(BACKWARDS, Sixteenth);
                break;
            }default: {
                break;
            }
        }
    }
}

void update_PIC18F_software_version_number(void){
    INTERRUPT_GlobalInterruptDisable();
    char numTimes = 4;

    start_over: 
    send_number();
    __delay_ms(300);
    if(--numTimes == 0){
        //increment down before comparing
        //we send the data three times so that it gets to BLE correctly
        INTERRUPT_GlobalInterruptEnable();
        return;
    }else{
        goto start_over;
    }
}

void send_number(void){
    EUSART2_Write(SENDING_PIC18F_SW_version_number_flag);
    __delay_ms(10); //stability
    EUSART2_Write(PIC18F_SW_VERSION_NUMBER);
    __delay_ms(10); //stability
}
/**
 End of File
*/
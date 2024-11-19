/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef STEP_H
#define	STEP_H

#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/interrupt_manager.h"
#include "../EUSART_Helpers/EUSART_Helpers.h"
#include "../encoder/encoder.h"
#include "../interrupt_additions/interrupt_additions.h"

//for use with stepper motor with these qualities:
//1 rotation = 0.05"(?) vertical movement (1.8 deg, 200 steps/rotation)
// our encder give 8 ticks per revolution
typedef enum {FORWARDS, BACKWARDS}direction; //0, 1
typedef enum {Full =  1, Half = 2, Quarter = 4, Eighth = 8, Sixteenth = 16}step_size; 

// send these over UART when the stepper motor has stopped moving
#define STEPPER_STOPPED_STOP_CMD 0x0C // sent at end of UART interrupt for stop command if stepper is awake
#define STEPPER_STOPPED_END_OF_CMD 0x0D // sent at end of Step() function if all steps were taken - not used anymore 
#define STEPPER_STOPPED_NEW_CMD 0x0E // sent at end of UART interrupt for new command if stepper is awake
#define STEPPER_STOPPED_END_OF_TRAVEL_CERVIX 0x0F // sent at end of INT0/INT1 interrupt for sensor trigger if stepper is awake (this is assumed - otherwise someone is just pressing the sensor)
#define STEPPER_STOPPED_END_OF_TRAVEL_MOTOR 0x10 // sent at end of INT0/INT1 interrupt for sensor trigger if stepper is awake (this is assumed - otherwise someone is just pressing the sensor)

void moveUntilZ(direction dir, step_size size);
void stepperSleep(bool in);
bool stepperIsAsleep(void);
void setStepSize(step_size size);
void setDirection(direction dir);

#endif /*STEP_H*/

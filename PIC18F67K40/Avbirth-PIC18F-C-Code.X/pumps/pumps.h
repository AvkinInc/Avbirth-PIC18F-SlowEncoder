// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PUMPS_H
#define	PUMPS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "../mcc_generated_files/mcc.h"

#define PWM_10 499 // 1023
#define PWM_9 450 // 920
#define PWM_8 400 // 820
#define PWM_7 350 // 715
#define PWM_6 300 // 615
#define PWM_5 250 // 510
#define PWM_4 200 // 410
#define PWM_3 150 // 140 // 305
#define PWM_2 100 // 205
#define PWM_1 50 // 100
#define PWM_0 0

#define PWM_HIGH PWM_10
#define PWM_MID PWM_7
#define PWM_LOW PWM_3
#define PWM_OFF PWM_0

typedef volatile struct { 
    uint16_t Pump1_PWM;
    uint16_t Pump2_PWM;
}pumps;

void initPumps(void);
uint16_t getPump1PWM(void);
uint16_t getPump2PWM(void);
void setPump1PWM(uint16_t pwm);
void setPump2PWM(uint16_t pwm);

#endif /*PUMPS_H*/

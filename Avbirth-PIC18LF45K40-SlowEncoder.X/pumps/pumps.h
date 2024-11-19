// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PUMPS_H
#define	PUMPS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "../mcc_generated_files/mcc.h"

// current settings: 99 = 100%

#define TC78H620FNG // we are using TC78H620FNG, not TB6612FNG

#ifdef TC78H620FNG
/*#define PWM_10 311 //499 // 1023
#define PWM_9 293 // 475 // 920
#define PWM_8 285 // 450 // 820
#define PWM_7 268 // 425 // 715
#define PWM_6 252 // 400 // 615
#define PWM_5 236 // 375 // 510
#define PWM_4 219 // 350 // 410
#define PWM_3 203 // 325 // 140 // 305
#define PWM_2 187 // 300 // 205
#define PWM_1 171 // 275 // 100
#define PWM_0 155 //250

#define PWM_10 999
#define PWM_9 967
#define PWM_8 929
#define PWM_7 892
#define PWM_6 854
#define PWM_5 817
#define PWM_4 779
#define PWM_3 742
#define PWM_2 704
#define PWM_1 667 
#define PWM_0 500
*/

// pwm goes from 0 to 99
#define PWM_10 0 // 99
#define PWM_9 3 // 97
#define PWM_8 6 // 94
#define PWM_7 9 // 91
#define PWM_6 12 // 88 //--> this and below cause problems!
#define PWM_5 14 // 86
#define PWM_4 17 // 83
#define PWM_3 20 // 80
#define PWM_2 23 // 77
#define PWM_1 25 //75 
#define PWM_0 50 // 50
#define PWM_OFF PWM_0
#define PWM_10_AMNIOTIC PWM_10
#define PWM_9_AMNIOTIC PWM_9
#define PWM_8_AMNIOTIC PWM_8
#define PWM_7_AMNIOTIC PWM_7
#define PWM_6_AMNIOTIC PWM_6
#define PWM_5_AMNIOTIC PWM_5
#define PWM_4_AMNIOTIC PWM_4
#define PWM_3_AMNIOTIC PWM_3
#define PWM_2_AMNIOTIC PWM_2
#define PWM_1_AMNIOTIC PWM_1
#define PWM_0_AMNIOTIC PWM_0
#define PWM_OFF_AMNIOTIC PWM_0
#define PWM_10_BLOOD PWM_10
#define PWM_9_BLOOD PWM_9
#define PWM_8_BLOOD PWM_8
#define PWM_7_BLOOD PWM_7
#define PWM_6_BLOOD PWM_6
#define PWM_5_BLOOD PWM_5
#define PWM_4_BLOOD PWM_4
#define PWM_3_BLOOD PWM_3
#define PWM_2_BLOOD PWM_2
#define PWM_1_BLOOD PWM_1
#define PWM_0_BLOOD PWM_0
#define PWM_OFF_BLOOD PWM_0
/*#define PWM_10_AMNIOTIC 0 // 311 //499 // 1023
#define PWM_9_AMNIOTIC 15 // 293 // 475 // 920
#define PWM_8_AMNIOTIC 29 // 285 // 450 // 820
#define PWM_7_AMNIOTIC 46 // 268 // 425 // 715
#define PWM_6_AMNIOTIC 62 // 252 // 400 // 615
#define PWM_5_AMNIOTIC 78 // 236 // 375 // 510
#define PWM_4_AMNIOTIC 94 // 219 // 350 // 410
#define PWM_3_AMNIOTIC 110 // 203 // 325 // 140 // 305
#define PWM_2_AMNIOTIC 125 // 187 // 300 // 205
#define PWM_1_AMNIOTIC 143 // 171 // 275 // 100
#define PWM_0_AMNIOTIC 155 //250
#define PWM_10_BLOOD 311 //499 // 1023
#define PWM_9_BLOOD 293 // 475 // 920
#define PWM_8_BLOOD 285 // 450 // 820
#define PWM_7_BLOOD 268 // 425 // 715
#define PWM_6_BLOOD 252 // 400 // 615
#define PWM_5_BLOOD 236 // 375 // 510
#define PWM_4_BLOOD 219 // 350 // 410
#define PWM_3_BLOOD 203 // 325 // 140 // 305
#define PWM_2_BLOOD 187 // 300 // 205
#define PWM_1_BLOOD 171 // 275 // 100
#define PWM_0_BLOOD 155 //250   
#define PWM_10_BLOOD 0 // 311 //499 // 1023
#define PWM_9_BLOOD 15 // 293 // 475 // 920
#define PWM_8_BLOOD 29 // 285 // 450 // 820
#define PWM_7_BLOOD 46 // 268 // 425 // 715
#define PWM_6_BLOOD 62 // 252 // 400 // 615
#define PWM_5_BLOOD 78 // 236 // 375 // 510
#define PWM_4_BLOOD 94 // 219 // 350 // 410
#define PWM_3_BLOOD 110 // 203 // 325 // 140 // 305
#define PWM_2_BLOOD 125 // 187 // 300 // 205
#define PWM_1_BLOOD 143 // 171 // 275 // 100
#define PWM_0_BLOOD 155 //250 */
#else // for TB6612FNG
/*#define PWM_10 499 // 1023
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
#define PWM_10_AMNIOTIC 499 // 1023
#define PWM_9_AMNIOTIC 450 // 920
#define PWM_8_AMNIOTIC 400 // 820
#define PWM_7_AMNIOTIC 350 // 715
#define PWM_6_AMNIOTIC 300 // 615
#define PWM_5_AMNIOTIC 250 // 510
#define PWM_4_AMNIOTIC 200 // 410
#define PWM_3_AMNIOTIC 150 // 140 // 305
#define PWM_2_AMNIOTIC 100 // 205
#define PWM_1_AMNIOTIC 50 // 100
#define PWM_0_AMNIOTIC 0
#define PWM_10_BLOOD 499 // 1023
#define PWM_9_BLOOD 450 // 920
#define PWM_8_BLOOD 400 // 820
#define PWM_7_BLOOD 350 // 715
#define PWM_6_BLOOD 300 // 615
#define PWM_5_BLOOD 250 // 510
#define PWM_4_BLOOD 200 // 410
#define PWM_3_BLOOD 150 // 140 // 305
#define PWM_2_BLOOD 100 // 205
#define PWM_1_BLOOD 50 // 100
#define PWM_0_BLOOD 0  */
#endif /*TC78H620FNG*/

typedef volatile struct { 
    uint16_t Blood_Pump_PWM;
    uint16_t Amniotic_Pump_PWM;
    bool Blood_On;
    bool Amniotic_On;
}pumps;

void initPumps(void);
void resetPumps(void);
void setBloodOn(bool in);
void setAmnioticOn(bool in);
void setBloodPumpPWM(uint16_t pwm);
void setAmnioticPumpPWM(uint16_t pwm);

#endif /*PUMPS_H*/

#include "./pumps.h"

#define Pump1_LoadDutyValue(x)  PWM1_LoadDutyValue(x) // CCP1, E0, PWMA
#define Pump2_LoadDutyValue(x)  PWM2_LoadDutyValue(x) // CCP2, E1, PWMB

static pumps Pumps;

void initPumps(void){
    TMR4_Start();
    PUMP_BIN1_SetHigh();
    PUMP_BIN2_SetLow();
    PUMP_AIN1_SetHigh();
    PUMP_AIN2_SetLow();
    PUMP_STBY_SetLow();
    Pumps.Pump1_PWM = PWM_OFF;
    Pumps.Pump2_PWM = PWM_OFF;
}

uint16_t getPump1PWM(void){
    return Pumps.Pump1_PWM;
}

uint16_t getPump2PWM(void){
    return Pumps.Pump2_PWM;
}

void setPump1PWM(uint16_t pwm){
    Pump1_LoadDutyValue(pwm);
    Pumps.Pump1_PWM = pwm;
    if(Pumps.Pump1_PWM == PWM_OFF){
        PUMP_AIN1_SetLow();
        if(Pumps.Pump2_PWM == PWM_OFF){
            // both pumps are off
            PUMP_STBY_SetLow();
        }
    }else{
        // pump 1 is on
        PUMP_AIN1_SetHigh();
        PUMP_STBY_SetHigh();
    }
}

void setPump2PWM(uint16_t pwm){
    Pump2_LoadDutyValue(pwm);
    Pumps.Pump2_PWM = pwm;
    if(Pumps.Pump2_PWM == PWM_OFF){
        PUMP_BIN1_SetLow();
        if(Pumps.Pump1_PWM == PWM_OFF){
            // both pumps are off
            PUMP_STBY_SetLow();
        }
    }else{
        // pump 2 is on
        PUMP_BIN1_SetHigh();
        PUMP_STBY_SetHigh();
    }
}
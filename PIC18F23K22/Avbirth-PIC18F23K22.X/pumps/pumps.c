#include "./pumps.h"
#include "../mcc_generated_files/mcc.h"

#define BloodPump_LoadDutyValue(x)  PWM4_LoadDutyValue(x) // CCP4, B0, PWMA - Blood
#define AmnioticPump_LoadDutyValue(x)  PWM5_LoadDutyValue(x) // CCP5, A4, PWMB - Amniotic
#define BloodPumpOn() do { PUMP_AIN2_SetHigh(); PUMP_AIN2_ALT_SetHigh(); } while(0)
#define BloodPumpOff() do { PUMP_AIN2_SetLow(); PUMP_AIN2_ALT_SetLow(); } while(0)
#define AmnioticPumpOn() PUMP_BIN2_SetHigh()
#define AmnioticPumpOff() PUMP_BIN2_SetLow()
#define PumpsEnable() PUMP_STBY_SetHigh()
#define PumpsDisable() PUMP_STBY_SetLow()
// AIN1/2 and PWMA are for blood
// BIN1/2 and PWMB are for amniotic

static pumps Pumps;

void initPumps(void){
    TMR2_StartTimer();
  //  PUMP_BIN1_SetHigh();
    AmnioticPumpOff();
  //  PUMP_AIN1_SetHigh();
  //  PUMP_AIN2_SetLow();
    PumpsDisable();
    Pumps.Blood_Pump_PWM = PWM_OFF;
    Pumps.Amniotic_Pump_PWM = PWM_OFF;
}

uint16_t getBloodPumpPWM(void){
    return Pumps.Blood_Pump_PWM;
}

uint16_t getAmnioticPumpPWM(void){
    return Pumps.Amniotic_Pump_PWM;
}

void setBloodPumpPWM(uint16_t pwm){
    BloodPump_LoadDutyValue(pwm);
    Pumps.Blood_Pump_PWM = pwm;
    if(Pumps.Blood_Pump_PWM == PWM_OFF){
        BloodPumpOff();
        if(Pumps.Amniotic_Pump_PWM == PWM_OFF){
            // both pumps are off
            PumpsDisable();
        }
    }else{
        // pump 1 is on
        BloodPumpOn();
        PumpsEnable();
    }
}

void setAmnioticPumpPWM(uint16_t pwm){
    AmnioticPump_LoadDutyValue(pwm);
    Pumps.Amniotic_Pump_PWM = pwm;
    if(Pumps.Amniotic_Pump_PWM == PWM_OFF){
        AmnioticPumpOff();
        if(Pumps.Blood_Pump_PWM == PWM_OFF){
            // both pumps are off
            PumpsDisable();
        }
    }else{
        // pump 2 is on
        AmnioticPumpOn();
        PumpsEnable();
    }
}
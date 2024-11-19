#include "./pumps.h"
#include "../mcc_generated_files/mcc.h"

#define BloodPump_LoadDutyValue(x)  PWM3_LoadDutyValue(x) // PWM3, A3, PWMB - Blood
#define AmnioticPump_LoadDutyValue(x)  PWM4_LoadDutyValue(x) // PWM4, D4, PWMA - Amniotic
#define BloodPumpOn() BIN1_SetHigh()
#define BloodPumpOff() BIN1_SetLow()
#define AmnioticPumpOn() AIN1_SetHigh()
#define AmnioticPumpOff() AIN1_SetLow()
#define PumpsEnable() STBY_SetHigh()
#define PumpsDisable() STBY_SetLow()
// BIN1/2 and PWMB are for blood
// AIN1/2 and PWMA are for amniotic

static pumps Pumps;

void initPumps(void){
    TMR2_StartTimer();
  //  PUMP_BIN1_SetHigh();
   // AmnioticPumpOff();
  //  PUMP_AIN1_SetHigh();
  //  PUMP_AIN2_SetLow();
    Pumps.Blood_On = false;
    Pumps.Amniotic_On = false;
    setBloodPumpPWM(PWM_OFF_BLOOD);
    setAmnioticPumpPWM(PWM_OFF_AMNIOTIC);
    setBloodOn(false);
    setAmnioticOn(false);
}

void resetPumps(void){
    // reset, since with TC78H620FNG low PWM values cause problems
    PumpsDisable();
    AmnioticPumpOff();
    BloodPumpOff();
   if(Pumps.Blood_On == true){ 
        BloodPumpOn();
        PumpsEnable();
    }
    if(Pumps.Amniotic_On == true){
        AmnioticPumpOn();
        PumpsEnable();
    }
}

void setBloodOn(bool in){
    Pumps.Blood_On = in;
    resetPumps();
}

void setAmnioticOn(bool in){
    Pumps.Amniotic_On = in;
    resetPumps();
}

void setBloodPumpPWM(uint16_t pwm){
    BloodPump_LoadDutyValue(pwm);
    Pumps.Blood_Pump_PWM = pwm;
}

void setAmnioticPumpPWM(uint16_t pwm){
    AmnioticPump_LoadDutyValue(pwm);
    Pumps.Amniotic_Pump_PWM = pwm;
} 
/*
void setBloodPumpPWM(uint16_t pwm){
    BloodPumpOff();
   // PumpsDisable();
    BloodPump_LoadDutyValue(pwm);
    Pumps.Blood_Pump_PWM = pwm;
    if(pwm != PWM_OFF_BLOOD){
        BloodPumpOn();
        PumpsEnable();
    }else{
        if(Pumps.Amniotic_Pump_PWM == PWM_OFF_AMNIOTIC){
            // both pumps are off
            PumpsDisable();
        }
    }
}

void setAmnioticPumpPWM(uint16_t pwm){
    AmnioticPumpOff();
  //  PumpsDisable();
    AmnioticPump_LoadDutyValue(pwm);
    Pumps.Amniotic_Pump_PWM = pwm;
    if(pwm != PWM_OFF_AMNIOTIC){
        AmnioticPumpOn();
        PumpsEnable();
    }else{
        if(Pumps.Blood_Pump_PWM == PWM_OFF_BLOOD){
            // both pumps are off
            PumpsDisable();
        }
    }
} */
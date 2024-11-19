#include "encoder.h"
#include "../mcc_generated_files/mcc.h"
#include "../step/step.h"

volatile static bool WAS_LOW_LAST_TIME = false;
volatile static uint16_t encoder_ticks = 0; // total ticks
//volatile static uint16_t encoder_ticks_in_timer0_period = 0; // is reset each time timer0 goes off
#undef VERBOSE

// no orange motor LED: motor is not moving/encoder is not working
// solid on LED: motor is stalled
// blinking orange LED: motor is running and encoder is ticking

// motor stalling is detected by either:
// ticks coming in too fast
// ticks coming in too slow (or not at all)

// set timer to 5 ms, then set the callback counter value based on the speed setting
// half steps: 20 ticks in 2 seconds - tick check speed: 0.1 seconds, 10 ms, counter = 2
// quarter steps: 10 ticks in 2 seconds - tick check speed: 0.2 seconds, 20 ms, counter = 4
// eighth steps: 5 ticks in 2 seconds - tick check speed: 0.4 seconds, 40 ms, counter = 8
// ** even though we dont use full or sixteenth steps in the application, have values for them anyway
// full steps: 40 ticks in 2 seconds - tick check speed: 0.05 seconds, 5 ms, counter = 1
// sixteenth steps: 2.5 ticks in 2 seconds - tick check speed: 0.8 seconds, 80 ms, counter = 16

/*
int timer0_interrupt_ticker_factor; 

void set_timer0_interrupt_ticker_factor(ticker_factor in){
    timer0_interrupt_ticker_factor = in;
}

ticker_factor get_timer0_interrupt_ticker_factor(void){
    return timer0_interrupt_ticker_factor;
}  */

// need to reset encoder_ticks when we hit our 0 point - motor limit switch
// void alertPinManagerMotorLimitSwitchTriggered(void){
void resetEncoderTicks(void){
    encoder_ticks = 0;
    EUSART2_Write(ENCODER_TICKS_RESET_CMD);
  //  EUSART1_Write(ENCODER_TICKS_DIV_4_CMD);
  //  EUSART1_Write(0); // encoder_ticks>>2);
#ifdef VERBOSE
    writeString("r");
    writeByte('\t');
    write4bytesHex(encoder_ticks);
    writeByte('\n');
#endif /* VERBOSE */
}

uint16_t getEncoderTicks(void){
    return encoder_ticks;
}
/*
void setStalling(bool in){
    if(stepperIsAsleep()){
        STALL_LED_SetLow(); // display
      //  ENCODER_LED_SetLow(); // display
        // ignore, this is just noise (stepper is not moving)
        // sometimes a jolt happens at power on
        // not sure if we actually need this
       return;
    }
    if(in){
        // stalling
        if(!STALL_LED_LAT){
            // this means we have not already detected the stall
            // sent UART alert
           // EUSART1_Write(ENCODER_DETECTED_STALL);   
        }
        STALL_LED_SetHigh(); 
    }else{
        // not stalling
        if(STALL_LED_LAT){
            // this means we have detected a stall previously
            // sent UART alert
          //  EUSART1_Write(ENCODER_DETECTED_END_OF_STALL);   
        }
        STALL_LED_SetLow(); 
    }
} 

uint16_t get_encoder_ticks_in_timer0_period(void){
    return encoder_ticks_in_timer0_period;
}

void reset_encoder_ticks_in_timer0_period(void){
    encoder_ticks_in_timer0_period = 0;
}  */

void encoder_IOC(void){
    if(stepperIsAsleep()){
        // ignore, this is just noise (stepper is not moving)
        // sometimes a jolt happens at power on
        // not sure if we actually need this
       return;
    }
    if(ENCODER_IN_GetValue()){
        if(WAS_LOW_LAST_TIME){
            GENERAL_LED_SetHigh();
            // we ticked over one position!
            // update encoder_ticks_in_timer0_period whether or not it is stalled
          //  encoder_ticks_in_timer0_period++;
           // if(true){ // !STALL_LED_LAT){
                // this means we have not detected a stall, log the encoder tick
                if(STEPPER_DIR_LAT){ // high: forwards/CW
                    encoder_ticks++;
#ifdef VERBOSE
                    writeByte('f');
                    writeByte('\t');
                    write2bytesHex(encoder_ticks);
                    writeByte('\n'); 
#endif /* VERBOSE */
                }else{ // high: backwards/CCW
                    if(encoder_ticks > 0){
                        encoder_ticks--;
                    }else{
                        encoder_ticks = 0;
                    }
#ifdef VERBOSE
                    writeByte('b');
                    writeByte('\t');
                    write2bytesHex(encoder_ticks);
                    writeByte('\n'); 
#endif /* VERBOSE */
                }
                if(((encoder_ticks%4) == 0) && encoder_ticks != 0){ 
                    // multiple of 4 and not 0 - the motor limit switch will tell us when we get to 0
                    // other wise when testing the board it will keep spamming 0 and overwhelm the app
                    // if there is not remainder, then we have changed by 4 or more places
                    EUSART2_Write(ENCODER_TICKS_DIV_4_CMD);
                    EUSART2_Write(encoder_ticks>>2);
                  //  ENCODER_LED_Toggle();
                }
           // }
        }
        WAS_LOW_LAST_TIME = false;
    }else{
        WAS_LOW_LAST_TIME = true;
        GENERAL_LED_SetLow();
    }
}

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ENCODER_H
#define	ENCODER_H
#include <stdint.h>
#include <stdbool.h>

#define ENCODER_TICKS_DIV_4_CMD 0xCC 
#define ENCODER_TICKS_RESET_CMD 0xCA 
// ^^ this says that the next command coming in from RX is the encoder value
// we div4 so it can go over the 8 bit UART line
// BLE chip updates the encoder ble characteristic with this value
//#define ENCODER_DETECTED_STALL 0xCF // send this when we detect a stall
//#define ENCODER_DETECTED_END_OF_STALL 0xD1 // send this when we detect the end of a stall

// this is the number of times timer0 ISR should fire before going to the callback
// timer period is set to 5.5ms (.5 ms more than 5ms, which is the time it takes to trigger the encoder at full steps)
/*typedef enum {
    ticker_factor_full =  1, // 5.5ms
    ticker_factor_half = 2, // 11ms
    ticker_factor_quarter = 4, // 22ms
    ticker_factor_eighth = 8, // 44ms
    ticker_factor_sixteenth = 16 // 88ms
}ticker_factor; */

//void set_timer0_interrupt_ticker_factor(ticker_factor in);
//ticker_factor get_timer0_interrupt_ticker_factor(void);
void resetEncoderTicks(void);
uint16_t getEncoderTicks(void);
//void setStalling(bool in);
//uint16_t get_encoder_ticks_in_timer0_period(void);
//void reset_encoder_ticks_in_timer0_period(void);
void encoderTrigger(void);
void sendEncoderValueToBGM(void); // default one
void sendEncoderValueToBGMx8(void); // fix for when the encoder is going 8 times slower 

#endif /*ENCODER_H*/
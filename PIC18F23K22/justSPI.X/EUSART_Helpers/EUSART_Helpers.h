// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EUSART_HELPERS_H
#define	EUSART_HELPERS_H
#include <stdint.h>

#define addToPrintALetter 0x37
#define addToPrintANumber 0x30

// call this function to expose the address of the uart write function
// ex: setUartFunction(EUSART2_Write);
void setUartFunction(void (*uart_write_local_function)());
    
// ex: writeByte(0x61); --> prints 'a'
void writeByte(uint8_t in);

// ex: write1byteHex(32) --> prints '0x20'
void write1byteHex(uint8_t in);

// ex: write2bytesHex(257) --> prints '0x0101'
void write2bytesHex(uint16_t in);

// ex: write4bytesHex(4034810618) --> prints '0xF07E52FA'
void write4bytesHex(unsigned long in);

// takes a pointer to a char, writes to EUSART2 until \0 is reached
// ex: writeString("Hello World");
void writeString(char message[]);

#endif /*EUSART_HELPERS_H*/
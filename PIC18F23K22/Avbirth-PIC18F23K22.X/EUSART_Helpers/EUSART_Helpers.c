#include "./EUSART_Helpers.h"
#include "../mcc_generated_files/mcc.h"
// https://www.javatpoint.com/function-pointer-as-argument-in-c

// #define uart_write(x) EUSART2_Write(x) 

// variable that is a pointer to a function that takes 1 parameter
void (*uart_write)(uint8_t);  

// need to call this to point it to a uart function
void setUartFunction(void (*uart_write_local_function)()){
    uart_write = uart_write_local_function;
}

void writeByte(uint8_t in){
    uart_write(in);
}

void write1byteHex(uint8_t in){
    uart_write('0');
    uart_write('x');
    if(((in>>4) & 0xF) > 9){ // highest nibble
        uart_write(((in>>4) & 0xF) + addToPrintALetter); 
    }else{
        uart_write(((in>>4) & 0xF) + addToPrintANumber);
    }
    if((in & 0x0F) > 9){ // lowest nibble
        uart_write((in & 0x0F) + addToPrintALetter); 
    }else{
        uart_write((in & 0x0F) + addToPrintANumber);
    }
}

void write2bytesHex(uint16_t in){
    uart_write('0');
    uart_write('x');
    if(((in>>12) & 0xF) > 9){ // highest nibble
        uart_write((in>>12) + addToPrintALetter); 
    }else{
        uart_write((in>>12) + addToPrintANumber);
    }
    if(((in>>8) & 0x0F) > 9){ // next nibble
        uart_write(((in>>8) & 0x0F) + addToPrintALetter); 
    }else{
        uart_write(((in>>8) & 0x0F) + addToPrintANumber);
    }
    if(((in>>4) & 0x00F) > 9){ // next nibble
        uart_write(((in>>4) & 0x00F) + addToPrintALetter); 
    }else{
        uart_write(((in>>4) & 0x00F) + addToPrintANumber);
    }
    if((in & 0x000F) > 9){ // lowest nibble
        uart_write((in & 0x000F) + addToPrintALetter); 
    }else{
        uart_write((in & 0x000F) + addToPrintANumber);
    }
}

void write4bytesHex(unsigned long in){
    uart_write('0');
    uart_write('x');
    if(((in>>28) & 0xF) > 9){ // highest nibble
        uart_write((in>>28) + addToPrintALetter); 
    }else{
        uart_write((in>>28) + addToPrintANumber);
    }
    if(((in>>24) & 0x0F) > 9){ // next nibble
        uart_write(((in>>24) & 0x0F) + addToPrintALetter); 
    }else{
        uart_write(((in>>24) & 0x0F) + addToPrintANumber);
    }
    if(((in>>20) & 0x00F) > 9){ // next nibble
        uart_write(((in>>20) & 0x00F) + addToPrintALetter); 
    }else{
        uart_write(((in>>20) & 0x00F) + addToPrintANumber);
    }
    if(((in>>16) & 0x000F) > 9){ // next nibble
        uart_write(((in>>16) & 0x000F) + addToPrintALetter); 
    }else{
        uart_write(((in>>16) & 0x000F) + addToPrintANumber);
    }
    if(((in>>12) & 0x0000F) > 9){ // next nibble
        uart_write(((in>>12) & 0x0000F) + addToPrintALetter); 
    }else{
        uart_write(((in>>12) & 0x0000F) + addToPrintANumber);
    }
    if(((in>>8) & 0x00000F) > 9){ // next nibble
        uart_write(((in>>8) & 0x00000F) + addToPrintALetter); 
    }else{
        uart_write(((in>>8) & 0x00000F) + addToPrintANumber);
    }
    if(((in>>4) & 0x000000F) > 9){ // next nibble
        uart_write(((in>>4) & 0x000000F) + addToPrintALetter); 
    }else{
        uart_write(((in>>4) & 0x000000F) + addToPrintANumber);
    }
    if((in & 0x0000000F) > 9){ // lowest nibble
        uart_write((in & 0x0000000F) + addToPrintALetter); 
    }else{
        uart_write((in & 0x0000000F) + addToPrintANumber);
    }
}

void writeString(char message[]){ //takes a pointer to a char, writes to EUSART2 until \0 is reached
    /* ex: parameter = "hello", message[] = "hello\0"
     * so length of message[] is one larger than we would expect
     * because of the null character ('\0') at the end of a string
     * We can check for '\0' to know we are at the end of the string
     */
    char *charIn;
    charIn = &message[0];
    while(*charIn != '\0'){ //checking the value of what is at the address of the pointer
        //not at the end yet
        //do stuff
        uart_write(*charIn); //writing the value of what is at the address of the pointer
        charIn++; //go to the next address
    }   
}


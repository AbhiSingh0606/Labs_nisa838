/*
 * display.c
 *
 * Created: 28/09/2026 11:53:48 pm
 *  Author: GGPC
 */ 

#include "display.h"
#include <avr/io.h>


const uint8_t seg_pattern[10] = {
	0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111  //9
};

const uint8_t digit_enable[4] = {1 << PD7, 1 << PD6, 1 << PD5, 1 << PD4};

// 0 = 1's, 1 = 10's, 2 = 100's, 3 = 1000's
static volatile uint8_t disp_characters[4] = {0, 0, 0, 0};

//The place value we're displaying
static volatile uint8_t disp_position = 0;

void init_display(void){
	DDRC |= 1 << PC3 | 1 << PC4 | 1 << PC5;              //Shift register pins as outputs
	DDRD |= 1 << PD4 | 1 << PD5 | 1 << PD6 | 1 << PD7;   //Digit enable pins as outputs
	PORTD |= 1 << PD4 | 1 << PD5 | 1 << PD6 | 1 << PD7;  //All digits off to start
}


void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	for (uint8_t i = 0; i < 4; i++){
		disp_characters[i] = seg_pattern[number % 10];   //Separate the digit
		number = number / 10;
	}
	
	if (decimal_pos >= 1 && decimal_pos <= 4){           //Add the decimal point
		disp_characters[4 - decimal_pos] |= 0b10000000;  //(Ds4 is index 0, Ds1 is index 3)
	}
}


void send_next_character_to_display(void){
	
	uint8_t p = disp_characters[disp_position]; // Pattern for the digit to show
	
	PORTC &= ~(1 << PC3 | 1 << PC5);            //SH_CP and SH_ST both low
   

	for (int8_t i = 7; i >= 0; i--){            //Each bit, starting with the MSB 
		if (p & (1 << i)){
			PORTC |= 1 << PC4;                  //SH_DS = 1
			} else {
			PORTC &= ~(1 << PC4);               //SH_DS = 0
		}
		PORTC |= 1 << PC3;                      //SH_CP high 
		PORTC &= ~(1 << PC3);                   // SH_CP low to shift the bit in
	}

	PORTD |= 1 << PD4 | 1 << PD5 | 1 << PD6 | 1 << PD7;   //Disable all digits

	PORTC |= 1 << PC5;                          //SH_ST high...
	PORTC &= ~(1 << PC5);                       //and low to latch the outputs
    
	PORTD &= ~digit_enable[disp_position];               //5. Enable the correct digit
    
    disp_position++;                                     //6. Next digit next time
    if (disp_position > 3){
	    disp_position = 0;
    }
}
    
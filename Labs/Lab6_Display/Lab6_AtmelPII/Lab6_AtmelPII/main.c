/*
 * Lab6_AtmelPII.c
 *
 * Created: 28/09/2026 11:43:46 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <avr/interrupt.h> 
#include <util/delay.h>

#include "display.h"

// function to configure TC0 to interrupt every ~10ms
void tc0_init_10ms_interrupt(void){
	TCCR0A = 0b00000010;    // set to 010 for CTC mode
	OCR0A = 77;             // OCR0A 77 to get ~10ms
	TIMSK0 = 0b00000010;    //Enable output compare match A interrupt
	TCCR0B = 0b00000100;    //Initialize with a prescaler of 256
}

//ISR for TIMER0 COMPA executes every ~10ms
ISR(TIMER0_COMPA_vect){
	send_next_character_to_display();
}

int main(void){
	uint16_t counter = 0;

	init_display();
	tc0_init_10ms_interrupt();
	sei();                                  //Enable global interrupts by setting I-bit

	while (1){
		seperate_and_load_characters(counter, 0);   //No decimal point
		_delay_ms(400);

		counter++;
		if (counter > 9999){
			counter = 0;
		}
	}
}
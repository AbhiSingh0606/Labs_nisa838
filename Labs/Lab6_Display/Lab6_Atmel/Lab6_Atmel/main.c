/*
 * Lab6_Atmel.c
 *
 * Created: 28/09/2026 10:47:08 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL   // change if your Proteus clock differs

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const uint8_t seg_pattern[10] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111  // 9
};

volatile uint8_t counter = 0;     // global count, 0-99
volatile uint8_t next_digit = 0;  // flag: 0 = update Ds1 (tens), 1 = update Ds2 (ones)

void show_digit(uint8_t n)
{
	uint8_t p = seg_pattern[n];
	PORTC = p & 0b00111111;
	
	// if g is needed
	if (p & 0b01000000) {
		PORTB |= (1 << PB4);
	} else {
		PORTB &= ~(1 << PB4);
	}
}

// function to configure TC0 to generate a interrupt every ~10ms
void tc0_init_10ms_interrupt(void){
	TCCR0A = 0b00000010;    //set to 010 for CTC mode
	OCR0A = 77;             //Loading OCR0A with 77 to get ~10ms
	TIMSK0 = 0b00000010;    //Enable output compare match A interrupt
	TCCR0B = 0b00000100;    //prescaler of 256
}

//ISR for TIMER0 COMPA executes every ~10ms
ISR(TIMER0_COMPA_vect){
	PORTB |= 1 << PB0 | 1 << PB1;           //Disable both digits
	
	if (next_digit == 0){
		show_digit(counter / 10);           //Segments for the tens digit
		PORTB &= ~(1 << PB0);               //Enable Ds1
		next_digit = 1;
		} else {
		show_digit(counter % 10);           //Segments for the ones digit
		PORTB &= ~(1 << PB1);               //Enable Ds2
		next_digit = 0;
	}
}


int main(void){
	DDRC = 0b00111111;                      //PC0-PC5 (a-f) as outputs
	DDRB |= 1 << PB0 | 1 << PB1 | 1 << PB4; //Ds1, Ds2 and g as outputs
	PORTB |= 1 << PB7;                      //Pull-up on the push button (pressed = 0)
	PORTB |= 1 << PB0 | 1 << PB1;           //Both digits off to start
	
	tc0_init_10ms_interrupt();              //Initialize TC0
	sei();                                  //Enable global interrupts
	
	uint8_t ticks = 0;
	
	while (1){
		_delay_ms(100);
		
		if (!(PINB & (1 << PB7))){          //Button pressed
			counter = 0;
			ticks = 0;
			} else if (++ticks == 10){          //10 x 100ms = 1s
			ticks = 0;
			counter = (counter + 1) % 100;
		}
	}
}

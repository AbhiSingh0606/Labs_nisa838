/*
 * display.h
 *
 * Created: 28/09/2026 11:54:10 pm
 *  Author: GGPC
 */ 


#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

//Configures the I/O pins connected to the shift register and the digit enables
void init_display(void);

//Splits 'number' (0-9999) into 4 digits and stores their segment patterns
//decimal_pos: 0 = no decimal point, 1-4 = decimal point on Ds1-Ds4
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos);

//Shows the next of the 4 digits on the display
void send_next_character_to_display(void);


#endif /* DISPLAY_H_ */
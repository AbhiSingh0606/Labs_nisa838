<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 3 Notes

Keep a digital log of your work using the readme file where appropriate.

# Pseudo Code for Pre-Lab

- You can use a simple algorithm that iterates through all the numbers up to 300, and checks if they can be exactly divided by numbers smaller than it using the modulo operator
- Here is an example algorithm you could use
> - Create an array that could store 62 numbers (note the variable type should allow storing integers up to 300)
> - Create a variable *i* to hold the position in the array where you will store next prime number and initialize this to 0
> - Create a variable *N* to hold the number we are going to check and see if it is a prime number (note the variable type should allow storing integers up to 300)
> - Create a counter variable *j* to iterate through numbers up to the number we want to check if it is a prime number (note the variable type should allow storing integers up to 300)
> - Create a variable *isPrime* that can be used as a flag to indicate its a prime number
> - In a 1st *for loop* increment *N* from 2 to 300 and within this loop
>   - Set the flag *isPrime*
>   - In a 2nd *for loop* increment *j* from 2 to N-1 and within this loop
>   - If *N % j* is 0 then *N* is not a prime number so clear *isPrime* and *break* the *for loop*
>   - If *isPrime* is set at the end of 2nd *for loop* then store *N* in the *i* position of the array and increment *i*
> - Continue with the 1st *for loop* until N reach 300 



Q 4.5: Program to send the character 3 every 0.5s:

#include <avr/io.h> #include <util/delay.h> #define UBRR_VALUE 12

void usart_init(uint16_t ubrr) { UBRR0H = (uint8_t)(ubrr >> 8); UBRR0L = (uint8_t)ubrr; UCSR0B = (1 << TXEN0); UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); }

void usart_transmit(uint8_t data) { while (!(UCSR0A & (1 << UDRE0))); UDR0 = data; }

int main(void) { usart_init(UBRR_VALUE); while (1) { usart_transmit('3'); _delay_ms(500); } }

Q 4.6: Program to send the number 345 every 0.5s using manual digit extraction:

int main(void) { usart_init(UBRR_VALUE); uint16_t number = 345; while (1) { uint8_t hundreds = (number / 100) % 10; uint8_t tens = (number / 10) % 10; uint8_t units = number % 10;

    usart_transmit(hundreds + 48);
    usart_transmit(tens + 48);
    usart_transmit(units + 48);
    usart_transmit(' ');
    _delay_ms(500);
}

}

Q 4.7: Steps for the full primes list program. Inside the while(1) loop, set up a for loop that iterates over the primes array. Steps within the loop: extract the individual characters of each prime number, call usart_transmit(character) as needed, call usart_transmit(character) for the comma and space as needed, and increment the loop counter (array index i).

Full program:

#include <avr/io.h> #include <util/delay.h> #include <stdbool.h> #define UBRR_VALUE 12 #define PRIMES_LEN 62

bool is_prime(int n) { if (n < 2) return false; for (int i = 2; i*i <= n; i++) if (n % i == 0) return false; return true; }

void usart_init(uint16_t ubrr) { UBRR0H = (uint8_t)(ubrr >> 8); UBRR0L = (uint8_t)ubrr; UCSR0B = (1 << TXEN0); UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); }

void usart_transmit(uint8_t data) { while (!(UCSR0A & (1 << UDRE0))); UDR0 = data; }

int main(void) { uint16_t primes[PRIMES_LEN]; uint8_t count = 0; for (int n = 2; n <= 300 && count < PRIMES_LEN; n++) { if (is_prime(n)) primes[count++] = n; }

usart_init(UBRR_VALUE);

while (1) {
    for (uint8_t i = 0; i < PRIMES_LEN; i++) {
        uint16_t num = primes[i];
        usart_transmit(((num / 100) % 10) + 48);
        usart_transmit(((num / 10) % 10) + 48);
        usart_transmit((num % 10) + 48);
        usart_transmit(',');
        usart_transmit(' ');
    }
    _delay_ms(2000);
}

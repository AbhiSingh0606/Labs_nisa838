<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 5 Notes

Keep a digital log of your work using the readme file where appropriate.
# Lab 5 - Timers and Interrupts

## Pre-Lab 1a

Compared with Lab 4, the Lab 5 Proteus circuit includes extra components used for timer and signal measurements.

The main additions are:

- A virtual terminal connected to TXD and RXD for UART communication.
- Simulated voltage and current signals, Vs and Is.
- Zero-crossing signals, Vzc and Izc.
- A variable resistor used to generate a DC test voltage.
- Additional signals connected to the oscilloscope for testing and measurement.

The LED is still connected to PB5, and the push button is connected to PB7.

---
# Part 1

## Q1.1

OCRnA and OCRnB are not required for every Timer0 setup.

They are mainly used when the timer needs to compare the value in TCNT0 with a programmed value. This is useful for modes such as:

- Compare match
- CTC
- PWM

For basic timer counting or overflow operation, the output compare registers may not be needed.

## Q1.2

Timer resolution is the amount of time represented by one timer count.

Timer range is the maximum amount of time the timer can count before overflowing and returning to zero.

Timer0 is an 8-bit timer, so it can count from:

0 to 255

This gives:

256 possible counts

## Q1.3

The prescaler divides the system clock before it reaches the timer.

Using a larger prescaler slows the timer down, meaning each timer count takes longer.

This allows the timer to measure longer periods of time before overflowing, but it also reduces the timer's timing resolution.

## Q1.4

The clock selection bits are:

CS02:0 = 100

### a) Prescaler

For Timer0:

CS02:0 = 100

This selects a prescaler of:

Prescaler = 256

### b) Timer0 resolution

System clock:

2 MHz

Timer clock:

2,000,000 / 256 = 7812.5 Hz

Timer resolution:

1 / 7812.5 = 128 us

Answer:

128 us

### c) Maximum Timer0 range

Timer0 is an 8-bit timer, giving 256 counts.

Maximum range:

256 x 128 us = 32768 us

Therefore:

Maximum range = 32.768 ms

## Q1.5

Timer0 is configured in CTC mode.

System clock:

2 MHz

Prescaler:

256

Timer resolution:

256 / 2,000,000 = 128 us

The required compare-match interval is:

9.984 ms

Number of timer counts:

9.984 ms / 128 us = 78 counts

Since counting starts from 0:

OCR0A = 78 - 1

OCR0A = 77

### a) TCCR0A

| Bit | COM0A1 | COM0A0 | COM0B1 | COM0B0 | - | - | WGM01 | WGM00 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |

WGM01 = 1 and WGM00 = 0 are used to select CTC mode.

TCCR0A:

0b00000010

### b) TCCR0B

| Bit | FOC0A | FOC0B | - | - | WGM02 | CS02 | CS01 | CS00 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |

CS02:0 = 100 selects a prescaler of 256.

TCCR0B:

0b00000100

### c) OCR0A

OCR0A:

77

Binary:

0b01001101

The resulting compare-match interval is:

(77 + 1) x 128 us = 9.984 ms

## Q1.6

The Timer0 Output Compare Match A flag is:

OCF0A

It is located in the TIFR0 register.

OCF0A is bit 1 of TIFR0.

---
# Part 2

## Q2.2

The LED toggles approximately every 10 ms.

This matches the Timer0 compare-match period of approximately 9.984 ms.

---
# Part 3

## Q3.2

Timer0 successfully generates interrupts and toggles the LED at the expected interval.

The LED waveform observed in Proteus confirms that the Timer0 compare-match interrupt is operating correctly.

## Q3.3

Timer0 generates an interrupt approximately every:

9.984 ms

A software counter is incremented each time the ISR runs.

After 10 interrupts, the LED is toggled.

9.984 ms x 10 = 99.84 ms

Therefore, the LED toggles approximately every:

100 ms

## Q3.4

Timer1 is a 16-bit timer, giving:

65536 counts

Using the largest prescaler of 1024:

Timer resolution:

1024 / 2,000,000 = 512 us

Maximum range:

65536 x 512 us = 33.554432 seconds

Therefore, the maximum Timer1 range is approximately:

33.55 seconds

---

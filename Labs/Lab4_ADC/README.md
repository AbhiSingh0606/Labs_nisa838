<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 4 Notes

Keep a digital log of your work using the readme file where appropriate.
# Pre-Lab

## QP.1

The DDRn register controls whether each pin on port n is used as an input or an output.

- 0 = input
- 1 = output

## QP.1a

Oscilloscope Channel A is connected to the LED signal on PB5.

Oscilloscope Channel B is connected to the push-button signal on PB7.

## QP.2

The LED is connected to PB5, which is physical pin 17 on the ATmega328P.

## QP.3

There is a short delay between the button input changing and the LED output responding because the microcontroller must read the input and execute the required instructions.

At a 2 MHz clock:

Clock period = 1 / 2,000,000

Clock period = 0.5 us

---

# Part 1

## Q1.1

### a) Channel Selection

Channel selection decides which analogue input is connected to the ADC. The ATmega328P has several ADC channels, so a multiplexer is used to select one channel at a time.

### b) Sample and Hold

Sample and hold takes the input voltage at a particular moment and keeps that value steady while the ADC performs the conversion.

### c) Successive Approximation

Successive approximation is the method used to find the digital value of the analogue voltage. The ADC tests the bits one at a time and compares its estimate with the input until it reaches the closest result.

### d) Reference Voltage

The reference voltage sets the voltage range used by the ADC. For example, if Vref is 5 V, the ADC measures voltages between approximately 0 V and 5 V.

### e) Sampling Rate

The sampling rate is how often the ADC takes a measurement. It is normally measured in samples per second or Hz.

### f) Resolution
a
Resolution describes how many digital values the ADC can produce.

The ATmega328P has a 10-bit ADC:

2^10 = 1024 levels

Therefore, the ADC result ranges from 0 to 1023.

## Q1.2

There are 8 ADC input channels, ADC0 through ADC7.

## Q1.3

Only one ADC channel can be converted at a time because all of the analogue inputs share a single ADC through a multiplexer.

## Q1.4

A normal ADC conversion takes 13 ADC clock cycles.

At an ADC clock of 125 kHz:

ADC clock period = 1 / 125000

ADC clock period = 8 us

Conversion time = 13 x 8 us

Conversion time = 104 us

Therefore, one normal ADC conversion takes approximately 104 us.

## Q1.5

The successive approximation stage takes most of the conversion time because the ADC has to determine the 10-bit result one bit at a time.

## Q1.6

ADC Count = (Vanalog / Vref) x 1024

For Vref = 5 V:

ADC Count = (Vanalog / 5) x 1024

The result is limited to the range 0 to 1023.

## Q1.7

Resolution = Vref / 1024

Resolution = 5 / 1024

Resolution = 0.00488 V

Therefore, one ADC count represents approximately 4.88 mV.

## Q1.8

The recommended ADC clock range for full 10-bit resolution is approximately 50 kHz to 200 kHz.

## Q1.9

Prescaler = System Clock / ADC Clock

Prescaler = 2 MHz / 125 kHz

Prescaler = 16

Therefore, a prescaler of 16 gives an ADC clock of 125 kHz.

---

# Part 2

## Q2.1

The ADC reference voltage can come from:

- AREF, using an external reference voltage
- AVCC
- The internal 1.1 V reference

For this lab, AVCC at approximately 5 V is used because the analogue signals are within the 0-5 V ADC input range.

## Q2.2

### ADMUX

REFS1:0 = 01

This selects AVCC as the reference voltage.

ADLAR = 0

This means the ADC result is right adjusted.

MUX3:0 = 0010

This selects ADC2.

### ADCSRA

ADEN = 1

This enables the ADC.

ADSC = 0

A conversion has not been started yet.

ADATE = 0

This selects normal single conversion operation.

ADIE = 0

ADC interrupts are disabled because polling is being used.

ADPS2:0 = 100

This gives a prescaler of 16.

ADC Clock = 2 MHz / 16

ADC Clock = 125 kHz

### ADCSRB

ADCSRB can be set to 0 because normal single ADC conversions are being used without auto triggering.

---

# Part 3

## Q3.1

To select ADC1 without changing the upper ADMUX settings:

ADMUX = (ADMUX & 0xF0) | (1 << MUX0);

The first part clears the channel selection bits and the second part selects ADC1.

## Q3.2

The ADSC bit in ADCSRA is set to 1 to start an ADC conversion.

## Q3.3

The conversion can be checked using:

- ADSC, which returns to 0 when the conversion finishes
- ADIF, which becomes 1 when the conversion finishes

## Q3.4

The ADC produces a 10-bit result, but each register can only store 8 bits.

Therefore, two registers are required.

ADCL stores the lower part of the ADC result.

ADCH stores the upper part of the ADC result.

---

# Part 4

## Q4.1

Pseudocode for adc_convert_mv(value):

1. Take the raw ADC value.
2. Multiply the value by 5000 mV.
3. Divide the result by 1024.
4. Return the calculated voltage in millivolts.

Formula:

Voltage (mV) = (ADC value x 5000) / 1024

## Q4.2

RV1 at 100%:

ADC ≈ 1023

RV1 at 50%:

ADC ≈ 512

RV1 at 0%:

ADC ≈ 0

## Q4.4

The voltage measured using the multimeter was close to the voltage calculated from the ADC value and displayed through PuTTY.

## Q4.6

Use the actual oscilloscope measurements from the lab for this question, including the measured amplitude, DC offset and phase difference.

---

# Part 5

## Q5.1

A normal ADC conversion takes 13 ADC clock cycles.

At 125 kHz:

ADC clock period = 1 / 125000

ADC clock period = 8 us

Time between consecutive ADC0 and ADC1 samples:

Delay = 13 x 8 us

Delay = 104 us

Therefore, consecutive ADC0 and ADC1 readings are separated by approximately 104 us.

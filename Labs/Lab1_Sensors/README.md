<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 1 Notes

Keep a digital log of your work using the readme file where appropriate.

Q1.1 :
I_L = 0.5A
V_L = 7V
P_L = 3.5W

Q1.2 :


PARAMETER        THEORITICAL VALUE        SIMULATED VALUE

IL                     0.5A                     0.5A

VL                     7V                        7V

PL                    3.5W                      3.5W

Comments: The results showed that the simulated values match the expected results.


Q1.3:
Parameter	          Value
Maximum Timestep	  100 µs (0.1 ms)   =T/20 = 2ms / 20 ​=0.1ms = 100 μs
Stop Time	          400 ms =200×T=200×2 ms=400 ms

Q1.4

Indcutor Time Constant = 4mH / 0.2 = ~20ms

Capacictor Time Constant = 25.3µF x 790 = ~20ms

therefore components whill be fully charged in 100ms, as 5 time constansts are needed to reach steady state.

# Assignment

## Question 2

### Q2.1 - P = VI

Maximum RMS load voltage: 15.4 Vrms
Minimum RMS load voltage: 12.6 Vrms
Maximum RMS load current: 0.595 Arms
Minimum RMS load current: 0.162 Arms

### Q2.2

| Parameter | Theoretical Value | Simulated Value |
|---|---|---|
| Load current (IL(rms)) | 0.500 A | 496.7 mA |
| Real Power (W) | 6.25 W | 6.1677 W |
| Reactive Power (VAR) | 3.15 VAR | 3.21 VAR |
| Apparent Power (VA) | 7 VA | 6.9538 VA |

### Q2.3

| Parameter | Theoretical Value | Simulated Value |
|---|---|---|
| Load current (IL(rms)) | 184.1 mA | 182.95 mA |
| Real Power (W) | 2.54 W | 2.5103 W |
| Reactive Power (VAR) | 0.43 VAR | 0.509 VAR |
| Apparent Power (VA) | 2.58 VA | 2.561 VA |

## Question 3

### Q3.1 - Maximum load to be measured

Imax = 7.5 / 12.6 = 0.595 A

P = i^2 * R
P = 0.2 W

R = 0.2 / (0.595)^2
R = 0.565 Ω

### Q3.2

XL = 2π(500)(0.004)
XL = 12.57 Ω

7.5 VA, 12.6 Vrms
|Z| = S / V^2 = 12.6^2 / 7.5 = 21.168 Ω
RL = sqrt(21.168^2 − 12.57^2) = 17.03 Ω

7.5 VA, 15.4 Vrms
|Z| = S / V^2 = 15.4^2 / 7.5 = 31.621 Ω
RL = sqrt(31.621^2 − 12.57^2) = 29.01 Ω

2.5 VA, 15.4 Vrms
|Z| = S / V^2 = 15.4^2 / 2.5 = 94.864 Ω
RL = sqrt(94.864^2 − 12.57^2) = 94.03 Ω

| VA | Vac(rms) | RL | IL(rms) | Vis(pk) Theo | Vis(pk) Sim | Pis Theo | Pis Sim |
|---|---|---|---|---|---|---|---|
| 7.5 VA | 12.6 V | 17.03 Ω | 0.595 A | 420.7 mV | 411.72189 mV | 177.0 mW | 181.93 mW |
| 7.5 VA | 15.4 V | 29.01 Ω | 0.487 A | 344.4 mV | 328.90956 mV | 118.6 mW | 113.64 mW |
| 2.5 VA | 15.4 V | 94.03 Ω | 0.162 A | 114.6 mV | 114.16204 mV | 13.1 mW | 12.877 mW |

### Q3.3 - Shunt resistor selection

| Parameter | Bigger Rs Value | Smaller Rs Value |
|---|---|---|
| SNR | High | Low |
| Dissipation (Pis) | High | Low |
| Size | Larger | Smaller |
| Cost | Higher | Lower |

I will be using a 0.5 ohm resistor. A shunt that's too small will have bad SNR, but one too high will risk exceeding the 200 mW power budget. As our calculated upper limit is 0.565 ohms, I think 0.5 ohm is a good value for our shunt resistor.



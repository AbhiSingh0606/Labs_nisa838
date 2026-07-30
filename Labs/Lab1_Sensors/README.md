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

Q1.5: 
Circuit with 12.5Ω Resistor
Parameter       Theoretical Value      Simulated Value
IL(RMS)            1.12A                     1.11
VL(RMS)            14V                       14V
Peak PL(t)          31.36W                   33
Pin                    15.68W                   -15

Circuit with 4mH Inductor
Parameter       Theoretical Value           Simulated Value
IL(RMS)              1.14A                       1.481A
VL(RMS)              13.993V                     13.91V
Peak PL(t)           31.2W                       33.431W 
Pin                  0.248W                      0.110W

Circuit with 25.3μF Capacitor
Parameter     Theoretical Value        Simulated Value
IL(RMS)            1.11A                    1.10A
VL(RMS)            13.964V                 18.58V
Peak PL(t)         31.0W                   38.20W
Pin               0.247W                    0.10W

q1.6: 
Reducing the maximum timestep from 100us to 1 us gets rid of the visible discretiisation at the wavefrom peaks producing a smooth sinusoid. The simulated RMS and power values also measured slightly closer to the theroirtcal predications. The tradeoff is a significant increase in simulation time and output file size, since the simulator must now compute approximately 100x more points across the same time window.

q1.7 
With the damping resistors removed, both the inudctive and capactivie circuits failed to reach steady-state within the 400ms simulation window - the wavefroms show a persistent offset/drift rather than a clean symmetric sinusoid. This confrims the theoretical predicition that ideal L and C elements however an infinite time constant, since there is no resistive path for the initial transient energy or Ltspices initial condtion mismatch to dissipate.

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


q 4.1
max source voltage is 15.4 V_rms

V_pk = 15.4 x sqr2 = 21.78 V
v_pk to v_pk = 43.56
vout = vin rb/(ra + rb)
2/43.56 = rb/(ra + rb)
43.56/2 = ra/rb + rb/rb
ra/rb = 20.78

ra = 100k
tb = 4.8k

everything allgins

Q 4.2
Voltage divider: Ra = 100k, Rb = 4.8k, so Rb/(Ra+Rb) = 4.8/104.8 = 0.0458

Case 1 — 7.5 VA @ 12.6 Vrms
RL = 17.03 ohms (from Part 3)
IL = 7.5/12.6 = 0.595 A
Vvs(pk) = Vac x √2 x Rb/(Ra+Rb) = 12.6 x 1.414 x 0.0458 = 816 mV, simulated value = 815.03859mV
Pvs = Vac^2/(Ra+Rb) = 12.6^2/104800 = 1.52 mW, simulated value = 1.4966mW

Case 2 — 7.5 VA @ 15.4 Vrms
RL = 29.01 ohms (from Part 3)
IL = 7.5/15.4 = 0.487 A
Vvs(pk) = 15.4 x 1.414 x 0.0458 = 998 mV, simulated value = 995.1323mV
Pvs = 15.4^2/104800 = 2.26 mW, simulated value = 2.2355mW

Case 3 — 2.5 VA @ 15.4 Vrms
RL = 94.03 ohms (from Part 3)
IL = 2.5/15.4 = 0.162 A
Vvs(pk) = 15.4 x 1.414 x 0.0458 = 998 mV, simulated value = 995.1323mV
Pvs = 15.4^2/104800 = 2.26 mW, simulated value = 2.2355mW

Yes, the 2 V peak-to-peak target is met. At the highest source voltage (15.4 V), the divider output is about 1 V peak, which is 2 V peak-to-peak — the right size for the ADC to read safely. The power wasted in the divider resistors is tiny (only about 2 mW) because the resistors are large and barely any current flows through them. The simulated values match my calculations, so the divider is stepping the voltage down correctly without wasting power.

q 4.3

Parameter | Ohms | Kilo-Ohms | Mega-Ohms
SNR | High | Medium | Low
Dissipation (Pvs) | High | Medium | Low
Sensitivity | Low | Medium | High



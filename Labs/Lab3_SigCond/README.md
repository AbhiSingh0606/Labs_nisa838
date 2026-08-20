<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 2 Notes

Keep a digital log of your work using the readme file where appropriate./
Q1.1 Done in book

Q1.2: The output is clipped because during the negative halfcycle of Vsense, the amplifier attempts t produce a negative output voltage, but it cannont output below 0 V. Therefore the negative portion of the waveforom is clipped near 0V.

Q1.3 From data sheet VOH = 3.5V. From observed in simulation VOH is approximately 3.49V

Q1.4 Minimum VOL from plot is approximately 0.7V

Part 2 Q2.1 Rs from Lab 1 Q3.1 – 0.565ohms R1 – 10kohms R2 – 21kohms (E12 would be 22kohms)

Q2.2 – Current Measurement Conditioning Results

Source VA	Vac (RMS)	RL (Ω)	IL (RMS)	Vis (pk) Theo	Vis (pk) Sim	Vio (pk) Theo	Vio (pk) Sim
7.5 VA	12.6 V	17.03	0.595 A	0.476 V	0.466 V	1.046 V	1.02 V
7.5 VA	15.4 V	29.01	0.487 A	0.389 V	0.380 V	0.856 V	0.835 V
2.5 VA	15.4 V	94.03	0.162 A	0.130 V	0.129 V	0.286 V	0.280 V
The theoretical and simulated results are very similar. The OpAmp output does not clip for any of the three load conditions, as Vio remains within the usable output voltage range of the LM324.

Q2.3: If the corresponding resistor pairs are not equal, the differential amplifier will have an inaccurate gain and reduced common-mode noise rejection. This introduces error/distortion into the output voltage, so the output will not accurately represent the difference between the two input signals.

Q2.4: Use a variable or switchable amplifier gain. At light loads, increase the differential amplifier gain so that the small Vis signal produces a larger Vio, improving the measurement resolution. At higher loads, use a lower gain to prevent the OpAmp output from clipping.

Part 3 Q3.1:

Ra = 100 kΩ
Rb = 4.87 kΩ
Rth = Ra || Rb = 4.64 kΩ
R1a = 5.6 kΩ
R1b = 10 kΩ
R2 = 10 kΩ
Differential amplifier gain ≈ 1
Q3.2 – Theoretical vs Simulated Results

Source VA	Vac(rms)	RL (Ω)	IL(rms) (A)	Vvo(pk) Theo (V)	Vvo(pk) Sim (V)
7.5 VA	12.6 V	17.03	0.595	0.848	0.85
7.5 VA	15.4 V	29.01	0.487	1.037	1.04
2.5 VA	15.4 V	94.03	0.162	1.037	1.03
Comments: The theoretical and simulated results are very similar. The OpAmp output does not clip for any of the tested conditions, as Vvo remains within the usable LM324 output range.

Q3.3: Vvs has an offset because the voltage divider is connected to the differential amplifier, which loads the divider. The 2.1 V DC reference connected through the amplifier resistor network affects the voltage at Vvs, introducing a DC component. Therefore, Vvs is no longer centred around 0 V and has a DC offset.

Q3.4 – Differential Amplifier Resistor Selection

Reasons not to use very small resistor values (e.g. Ω):

High current draw.
Increased power consumption.
Excessive loading of the signal source.
May require the OpAmp to supply too much output current.
Reasons not to use very large resistor values (e.g. MΩ):

Input bias currents can cause larger voltage errors.
More susceptible to noise and interference.
Parasitic capacitance can have a greater effect on the circuit.
Q3.5 – Replacement OpAmp Parameters

Parameter	Max and/or Min Specification
Single rail supply voltage	Min rating < 5 V < Max rating
Input common-mode voltage range	Must include the full required input voltage range
Output voltage swing	VOL must be sufficiently low and VOH sufficiently high for the required output range
Output current capability	Maximum output current must be greater than the load current required
Gain-bandwidth product	Minimum bandwidth should be comfortably greater than the 500 Hz signal frequency
Input offset voltage	Maximum offset voltage should be as small as possible to minimise measurement error
Part 4 Q4.1 Transfer function Vfilter/VOpAmp = 1/1sRfCf Cf and Rf = 10nF & 1.59kohms

Q4.2 done in book

Q4.3 done in book

Q4.4: A cut-off frequency closer to 500Hz results in: stronger attenuation of high-frequency noise, but also greater attenuation and phase shift of the desired 500 Hz signal, causing measurement error.

A cut-off frequency closer to 100kHz results in: less attenuation and phase shift of the desired 500 Hz signal, but poorer rejection of the 100 kHz noise, allowing more noise to reach the ADC.

Q5.1: Assumptions:

Load current is approximately constant at 50 mA.
The smoothing capacitor discharges approximately linearly between charging peaks.
Half-wave rectification gives a ripple frequency of 500 Hz.
Diode and other non-ideal effects are neglected in the theoretical calculation.
Theoretical ΔVin approximately 2.13 V Simulated ΔVin appoximately 1.65 V

Q5.2: Graphs drawn in book Ireg looks like short-duration bursts because: The smoothing capacitor supplies the load for most of the AC cycle. The diode only conducts near the positive peaks of the AC voltage when the source voltage becomes high enough to recharge the capacitor. Therefore, current flows in short charging pulses rather than continuously.

Q5.3: When RL was reduced to 50 ohms, the increased load current caused the regulator to struggle to maintain a constant 5 V output. Reducing Rin allowed the regulator to maintain the 5 V output, but caused significantly larger current spikes to be drawn from the AC source.

Q5.4: Advantages of a half-wave rectifier: Simple circuit requiring only one diode. Lower cost and fewer components. Only one diode voltage drop, reducing conduction losses. Suitable for low-power applications where low ripple is not critical.

Disadvantages of a half-wave rectifier: Uses only one half of the AC waveform, so it is less efficient than a full-wave rectifier. Produces more output voltage ripple. Requires a larger smoothing capacitor to achieve the same ripple as a full-wave rectifier. Provides less average DC current and poorer performance for higher-current loads. Full-wave rectification would recharge the smoothing capacitor twice per AC cycle, giving a smoother and more stable DC supply.

Q5.5:

# Saltwater (ORP/Conductivity-Based) Concentration Detector

Overview

This project implements a low-cost saltwater concentration estimation system using an Arduino-based analog sensor input. The system reads an analog voltage signal, converts it into an electrical representation of solution behavior, estimates salinity concentration using a logarithmic calibration model, and provides LED-based range classification.

The project demonstrates:

* Analog electrochemical sensing
* Logarithmic calibration modeling
* Embedded signal processing
* Threshold-based classification
* Real-time hardware feedback

⸻

Hardware Setup

Components

* Arduino (Uno or compatible)
* Analog ORP / conductivity sensor probe (or equivalent analog saltwater sensor)
* 3 LEDs
* Jumper wires + breadboard

⸻

Pin Assignments

Component	Arduino Pin
Sensor Input	A0
LED 1	8
LED 2	9
LED 3	10

⸻

System Operation

1. Analog Signal Acquisition

The system reads an analog voltage representing electrochemical activity in the solution:

analogRead(A0)

ADC range:

* 0 → 1023 (0–5V equivalent)

⸻

2. Voltage Conversion

The raw ADC reading is converted into millivolts:

V = \frac{ADC}{1023} \times 5.0 \times 1000

float activeVoltageValue = (activeVoltage / 1023.0) * 5.0 * 1000;

This produces a scaled voltage signal used for calibration.

⸻

3. Concentration Estimation Model

Salt concentration is estimated using a logarithmic regression model:

C = 4307.17 \cdot \ln(V) - 214.041

concentration = 4307.17 * log(activeVoltageValue) - 214.041;

This reflects the nonlinear relationship between ion concentration and sensor response.

⸻

4. LED Classification System

The system maps estimated concentration into qualitative ranges:

LED	Condition	Interpretation
LED 1	concentration < 2320	Low salinity
LED 2	1571 ≤ concentration ≤ 3706	Medium salinity
LED 3	2606 ≤ concentration ≤ 4735	High salinity

Only one LED is activated at a time.

⸻

Software Structure

Main Loop

1. Read analog sensor value
2. Convert to voltage
3. Compute concentration via logarithmic model
4. Print diagnostic output
5. Update LED status
6. Repeat every 2 seconds

⸻

Function: WritetoLED()

Controls LED output based on concentration thresholds.

⸻

Serial Output

The system outputs real-time diagnostics via serial monitor:

* Raw voltage (mV equivalent)
* Estimated salt concentration

Baud rate:

9600

⸻

Engineering Concepts Demonstrated

* Electrochemical sensing principles
* Analog-to-digital conversion
* Logarithmic regression calibration
* Empirical modeling of nonlinear systems
* Embedded decision systems (threshold classification)
* Low-cost environmental sensing

⸻

Limitations

* Calibration model is empirically derived and sensor-dependent
* No temperature compensation
* No filtering or noise reduction applied
* Overlapping LED thresholds may cause ambiguous classification zones

⸻

Potential Improvements

* Add moving average filter for signal stabilization
* Introduce temperature compensation
* Recalibrate using known salinity standards
* Replace fixed regression with multi-point curve fitting
* Log data for long-term trend analysis
* Upgrade output to quantitative display (LCD/OLED)

⸻

Applications

* Water quality monitoring
* Environmental sensing prototypes
* Agricultural irrigation monitoring
* Aquatic system analysis
* Low-cost conductivity estimation systems

⸻

Summary

This system demonstrates a practical embedded approach to chemical concentration estimation using analog electrical sensing and logarithmic calibration modeling, with real-time classification via microcontroller-driven output indicators.

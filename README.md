# Magnetic-Sensor-Arduino-Project
Overview
This project focuses on the design and implementation of a sensor aimed at remotely detecting power-frequency magnetic fields (50Hz/60Hz), particularly those emanating from high-tension lines and substations. The system quantifies magnetic field intensity in Gauss (G) units using a linear Hall Effect sensor and an Arduino microcontroller.

System Components
Microcontroller: Arduino Uno
Sensor: SS49E Linear Hall Effect Sensor
Display: 16x2 LCD with I2C Interface (PCF8574T)
Software: Arduino IDE & Proteus Design Suite (for simulation)

How It Works
The system operates on the principle of the Hall Effect. The SS49E sensor provides an output voltage proportional to the magnetic flux density.
Null Voltage: At 0 Gauss, the sensor outputs approx $2.5V$.
Sensitivity: The sensor has a sensitivity of $1.4mV/G$.
Processing: The Arduino reads the analog voltage, subtracts the null offset, and applies the sensitivity factor to calculate the field strength.

Important Findings: Measurement Limitations
During the testing phase, it was observed that the sensor was unable to accurately measure magnetic flux directly under high-tension transmission lines. Analysis of Results:
Resolution Issue: The Arduino Uno ADC has a resolution of $\approx 4.9mV$. Since the SS49E sensitivity is only $1.4mV/G$, the sensor cannot detect changes smaller than $\approx 3.5$ Gauss.
Field Strength: Magnetic fields from power lines at ground level are typically measured in milliGauss (mG). This signal was significantly below the "noise floor" of the SS49E sensor.
Conclusion: While the device works perfectly for detecting strong permanent magnets, a high-gain Op-Amp stage or a more sensitive induction coil sensor would be required for environmental power-line monitoring.

Getting Started
Open the Simulation/ folder to view the circuit in Proteus.
Upload the code in the Code/ folder to your Arduino.
Check the Final Report.pdf for the full mathematical derivation and research references.

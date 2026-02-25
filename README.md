# Magnetic-Sensor-Arduino-Project
---

## 📝 Overview
This project focuses on the design and implementation of a sensor aimed at remotely detecting power-frequency magnetic fields (50Hz/60Hz), particularly those emanating from high-tension lines and substations.

The objective was to quantify magnetic field intensity in **Gauss (G)** units using a linear Hall Effect sensor and an Arduino microcontroller to identify potential hazards in industrial and residential environments.

## System Components
* **Microcontroller:** Arduino Uno
* **Sensor:** SS49E Linear Hall Effect Sensor
* **Display:** 16x2 LCD with I2C Interface
* **Software:** Arduino IDE & Proteus Design Suite

---

## How It Works
The system operates on the principle of the **Hall Effect**. The SS49E sensor provides an output voltage proportional to the magnetic flux density.

1. **Null Voltage:** At 0 Gauss, the sensor outputs approximately $2.5V$.
2. **Sensitivity:** The sensor has a sensitivity of $1.4mV/G$.
3. **Calculation:** The Arduino subtracts the null offset ($V_{null}$) and applies the sensitivity factor to calculate the field strength.

---

## Important Findings: Measurement Limitations
During testing, the device was **unable to accurately measure magnetic flux** directly under high-tension transmission lines. 

### Why did it not work for power lines?
* **Resolution Issue:** The Arduino Uno ADC has a resolution of $\approx 4.9mV$ per unit. Since the SS49E sensitivity is only $1.4mV/G$, the sensor cannot detect changes smaller than $\approx 3.5$ Gauss.
* **Field Strength:** Magnetic fields from power lines at ground level are typically measured in **milliGauss (mG)**. This signal was significantly below the "noise floor" of the SS49E sensor.
* **Conclusion:** While the device works perfectly for detecting strong permanent magnets, a high-gain Op-Amp stage or an induction coil sensor is required for environmental power-line monitoring.

---

## Getting Started
1. Open the `Simulation/` folder to view the circuit in Proteus.
2. Upload the code in the `Code/` folder to your Arduino.
3. Check the `Documentation/Final Report.pdf` for full mathematical derivations.

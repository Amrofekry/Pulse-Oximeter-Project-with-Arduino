# Pulse Oximeter Project with Arduino

## Overview

This project utilizes an Arduino UNO and the MAX30100 pulse oximeter sensor to measure heart rate and blood oxygen saturation levels. The results are displayed on an LCD module with an I2C interface. This project also includes a custom heart icon on the LCD to indicate heartbeat detection.

## Components Used

- **Arduino UNO**: The microcontroller board used to process sensor data.
- **MAX30100 Pulse Oximeter Sensor**: Measures heart rate and blood oxygen saturation (SpO2) levels using infrared light technology.
- **LCD Module with I2C Interface**: Displays heart rate and SpO2 levels.
- **Jumper Wires**: For connecting components.
- **Breadboard**: For building and testing the circuit.

## MAX30100 Sensor Details

The MAX30100 pulse oximeter sensor includes a red light, an infrared light, and a light receiver. It measures:
1. **Heart Rate**: Using the reflection of red and infrared light through the skin.
2. **SpO2 Levels**: Calculated based on light absorption characteristics of oxygenated and deoxygenated hemoglobin.

## Circuit Diagra

![Picture1](https://github.com/user-attachments/assets/f59005e2-d564-49ad-97f6-49ba642345cf)

![Picture2](https://github.com/user-attachments/assets/f6998e88-1cf5-4154-991c-a5c33127bc2d)



## Connections

- **MAX30100 Sensor**
  - VCC to Arduino 5V
  - GND to Arduino GND
  - SDA to Arduino A4 (SDA)
  - SCL to Arduino A5 (SCL)

- **LCD Module (I2C)**
  - VCC to Arduino 5V
  - GND to Arduino GND
  - SDA to Arduino A4 (SDA)
  - SCL to Arduino A5 (SCL)

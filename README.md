# Arduino Nano-Based Solar Tracker with Servo and LDR Powered by Solar Panel and Battery

## Project Overview
This project utilizes an **Arduino Nano** and a **servo motor** to create a simple solar tracker that follows the movement of the sun. The system uses **Light Dependent Resistors (LDRs)** to detect sunlight intensity, allowing the servo to adjust the position of a solar panel for maximum energy capture. The tracker is powered by a **battery** with a **charging system** that uses the solar panel itself.

## Features
- **Sunlight tracking** using LDR sensors to optimize solar panel alignment.
- **Battery-powered system** with charging support through the solar panel.
- **Servo motor control** to adjust solar panel angle for maximum energy absorption.
- Compact design using **Arduino Nano** for portability and efficiency.

## Hardware Requirements
- **Arduino Nano**
- **Servo Motor** (e.g., SG90 or similar)
- **2x Light Dependent Resistors (LDR)**
- **Resistors** (10k ohms recommended for LDR voltage divider)
- **Solar Panel** (for charging the battery)
- **Rechargeable Battery** (e.g., Li-ion or lead-acid)
- **Battery Charging Module** (e.g., TP4056 for Li-ion)
- Jumper wires
- Breadboard

## Software Requirements
- **Arduino IDE** (with the Servo library pre-installed)

## Circuit Diagram
(Include a circuit diagram showing the connections between the LDRs, Arduino Nano, servo motor, solar panel, and battery charging module.)

## Setup Instructions
### Step 1: Wiring the Circuit
1. **LDR Setup**:
   - Create two **voltage dividers** using the **LDRs** and resistors.
   - Connect one end of each LDR to **5V** on the Arduino Nano.
   - Connect the other end to an **analog pin** (e.g., **A0** and **A1**).
   - Connect resistors (10k ohms) from the LDR pins to **GND**.

2. **Servo Motor Setup**:
   - Connect the **signal pin** of the servo to a **PWM pin** on the Arduino Nano (e.g., **D9**).
   - Connect the **VCC** and **GND** of the servo to the Arduino's **5V** and **GND** pins.

3. **Solar Panel and Battery**:
   - Connect the **solar panel** to the **charging module** (input side).
   - Connect the **battery** to the charging module (output side) to ensure the system runs off the stored energy.
   - Make sure the solar panel provides adequate charging voltage for the battery used.

### Step 2: Arduino Sketch
1. Open the Arduino IDE and create a new sketch.
2. Copy the following code into the Arduino IDE:

```cpp
#include <Servo.h>

Servo myservo;  // Create servo object
int ldrLeft = A0;  // Left LDR connected to A0
int ldrRight = A1;  // Right LDR connected to A1
int threshold = 50;  // Sensitivity threshold for LDR difference

void setup() {
  myservo.attach(9);  // Servo connected to pin 9
  Serial.begin(9600);
}

void loop() {
  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  int difference = leftValue - rightValue;

  if (abs(difference) > threshold) {
    if (difference > 0) {
      myservo.write(myservo.read() - 1);  // Move servo to the left
    } else {
      myservo.write(myservo.read() + 1);  // Move servo to the right
    }
  }

  delay(100);  // Small delay to prevent jitter
}
```
### Step 3: Flash the Code
1. Connect the **Arduino Nano** to your computer via USB.
2. Open the **Arduino IDE**, select the correct board (**Arduino Nano**) and the corresponding COM port.
3. Verify the code by clicking the **checkmark icon** (Verify button) in the Arduino IDE.
4. If there are no errors, click the **arrow icon** (Upload button) to upload the code to the Arduino Nano.

### Step 4: Usage
- Once the system is powered on, the **LDRs** will start measuring the light intensity from both directions.
- The **servo motor** will automatically adjust the solar panel's position by comparing the light intensity detected by the two LDRs. 
- As the sun moves across the sky, the tracker will continuously adjust the panel to ensure optimal sunlight exposure for maximum energy efficiency.
- The solar panel powers the system while simultaneously charging the **battery**, ensuring the device remains operational even when sunlight is not present.

### Step 5: Powering the System
- The solar panel charges the **battery** via the charging module, so make sure to use a solar panel that matches the power needs of your system.
- The battery will supply power to the **Arduino Nano** and the servo motor during periods of low sunlight or at night.

## Future Enhancements
- **Dual-Axis Solar Tracker**: Upgrade the system to control two axes (vertical and horizontal) using two servo motors for more precise sun tracking.
- **Battery Monitoring**: Implement a battery level monitoring system to track the charge level and optimize charging based on real-time solar input.
- **Data Logging**: Add a data logging feature to store sunlight tracking information, energy efficiency, or solar panel performance over time.
- **Weather Adaptation**: Integrate weather sensors to adjust the tracking mechanism in response to cloud cover or other conditions.

## Troubleshooting
- **Servo Motor Not Moving**: 
  - Check the servo wiring to ensure proper connections to the Arduino Nano. 
  - Ensure the **servo power supply** is adequate, as servos can require higher current.
- **Inconsistent or Erratic Movements**: 
  - Adjust the **threshold value** in the code to fine-tune the light sensitivity difference between the LDRs.
  - Ensure the LDRs are placed at proper angles to detect light changes accurately.
- **Power Issues**: 
  - Verify the battery and solar panel connections. 
  - Ensure the charging module is functioning correctly and delivering adequate power to the system.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

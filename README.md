# Industrial Conveyor Belt Sorting System

This project implements an automated industrial conveyor belt sorting system. The core control logic is driven by a Finite State Machine (FSM) designed in Verilog for FPGA synthesis, while the sensor and actuator interfacing is handled by an Arduino microcontroller. The complete system architecture was simulated and verified using Xilinx Vivado and Proteus VSM.

## Features
* **Hardware-Accelerated Control:** Core sorting logic handled by a Verilog FSM.
* **Microcontroller Interfacing:** Arduino-based integration for object detection sensors and motor drivers.
* **Automated Sorting:** Distinguishes between standard and defective/target objects and routes them using a sorting arm.
* **Simulation-Ready:** Includes logic ready for Vivado simulation and Proteus circuit environments.

## Tech Stack
* **Hardware Description Language:** Verilog
* **EDA & Simulation:** Xilinx Vivado, Proteus VSM
* **Microcontroller:** Arduino (C++)

---

## Verilog (Vivado)

**System States (Verilog FSM):**
1. **IDLE:** Belt is stationary, waiting for system activation.
2. **SCAN:** Belt moves, system scans for incoming objects via IR/proximity sensors.
3. **ACCEPT:** Object passes quality check; belt continues normal operation.
4. **REJECT:** Object fails check; sorting arm activates to divert the object.

**Simulation Waveform & Results:** 
The waveform below demonstrates the FSM transitioning through the operational states based on sensor inputs, validating the logic and timing of the system.

![Vivado Simulation Waveform](Screenshot%202026-10-19%20104013.png)

---

## Proteus IDE

> *Note: The Arduino controller code given is the code for the Arduino Uno used in the Proteus IDE.*

**Proteus Simulation Component List:** 
The following devices and instruments are required to replicate the simulation environment based on the Proteus workspace:

* **Microcontroller:**
  * ARDUINO_UNO (Arduino Uno R3)
* **Motor Driver:**
  * L298N (L298N Motor Driver Module)
* **Sensors & Inputs:**
  * IR_SENSOR (IR Proximity Sensor)
  * DEFECT_SENSOR (Simulated Quality/Defect Sensor)
  * LOGIC TOGGLE (Used for manual sensor triggering during simulation)
* **Actuators & Outputs:**
  * MOTOR (DC Motor representing the conveyor belt)
  * SERVO (Servo Motor used for the sorting arm)
  * BUZZER (Reject Buzzer audio indicator)
* **Displays & Instruments:**
  * LCD1602 (LCD 16x2 Screen)
  * VIRTUAL TERMINAL (Instrument used for monitoring serial data output)

**Circuit Schematic:**
![Proteus Simulation Circuit](watermarked_img_11345888750878785268.png)

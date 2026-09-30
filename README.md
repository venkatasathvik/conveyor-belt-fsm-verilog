# Industrial Conveyor Belt Sorting System

This project implements an automated industrial conveyor belt sorting system. The core control logic is driven by a Finite State Machine (FSM) designed in Verilog for FPGA synthesis, while the sensor and actuator interfacing is handled by an Arduino microcontroller. The complete system architecture was simulated and verified using Xilinx Vivado and Proteus VSM.

## Features
- **Hardware-Accelerated Control:** Core sorting logic handled by a Verilog FSM.
- **Microcontroller Interfacing:** Arduino-based integration for object detection sensors and motor drivers.
- **Automated Sorting:** Distinguishes between standard and defective/target objects and routes them using a sorting arm.
- **Simulation-Ready:** Includes logic ready for Vivado simulation and Proteus circuit environments.

## Tech Stack
- **Hardware Description Language:** Verilog
- **EDA & Simulation:** Xilinx Vivado, Proteus VSM
- **Microcontroller:** Arduino (C++)


## Verilog (vivado)

System States (Verilog FSM) :-- 

1. `IDLE`: Belt is stationary, waiting for system activation.
2. `SCAN`: Belt moves, system scans for incoming objects via IR/proximity sensors.
3. `ACCEPT`: Object passes quality check; belt continues normal operation.
4. `REJECT`: Object fails check; sorting arm activates to divert the object.



## Proteus Ide 

-- the arduino controler code given is the code for the arduino uno used in the proteus ide

Proteus Simulation Component List :--
The following devices and instruments are required to replicate the simulation environment based on the Proteus workspace[cite: 2]:

* **Microcontroller:**
  * `ARDUINO_UNO` (Arduino Uno R3)[cite: 2]
* **Motor Driver:**
  * `L298N` (L298N Motor Driver Module)[cite: 2]
* **Sensors & Inputs:**
  * `IR_SENSOR` (IR Proximity Sensor)[cite: 2]
  * `DEFECT_SENSOR` (Simulated Quality/Defect Sensor)[cite: 2]
  * `LOGIC TOGGLE` (Used for manual sensor triggering during simulation)[cite: 2]
* **Actuators & Outputs:**
  * `MOTOR` (DC Motor representing the conveyor belt)[cite: 2]
  * `SERVO` (Servo Motor used for the sorting arm)[cite: 2]
  * `BUZZER` (Reject Buzzer audio indicator)[cite: 2]
* **Displays & Instruments:**
  * `LCD1602` (LCD 16x2 Screen)[cite: 2]
  * `VIRTUAL TERMINAL` (Instrument used for monitoring serial data output)[cite: 2]

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

## System States (Verilog FSM)
1. `IDLE`: Belt is stationary, waiting for system activation.
2. `SCAN`: Belt moves, system scans for incoming objects via IR/proximity sensors.
3. `ACCEPT`: Object passes quality check; belt continues normal operation.
4. `REJECT`: Object fails check; sorting arm activates to divert the object.

## Repository Structure
- `/src/verilog/` - Contains the Verilog FSM and testbench files.
- `/src/arduino/` - Contains the Arduino C++ firmware for sensor/actuator control.

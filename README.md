# conveyor-belt-fsm-verilog
# Industrial Conveyor Belt Sorting System

A digital sorting controller designed to automate industrial material handling. The core logic is driven by a multi-state Mealy/Moore Finite State Machine (FSM) to maintain high-throughput synchronous operation.

### Tools & Technologies
* **Hardware Description Language:** Verilog HDL
* **Synthesis & Simulation:** Xilinx Vivado
* **Hardware Interaction Simulation:** Proteus VSM (interfaced with Arduino Uno)

###  System Architecture
* **FSM Controller:** Implements precise state memory logic to manage sorting pathways based on sensor inputs.
* **Datapath:** Optimized combinational logic depth and register resource utilization to prevent processing bottlenecks.
* **Hardware Interfacing:** Real-world hardware interaction and sensor polling modeled in Proteus using an Arduino Uno to validate physical timing.

###  Verification & Testing
* **RTL Testbenches:** Developed custom behavioral testbenches in Vivado to verify timing constraints, edge cases, and state transitions.
* **Waveform Analysis:** Achieved zero functional race conditions under simulation. *(Note: Insert a screenshot of your Vivado timing waveforms here)*
* **Schematic Integration:** *(Note: Insert a screenshot of your Proteus simulation schematic here)*

###  Setup Instructions
1. Clone this repository.
2. Open the project directory in Xilinx Vivado.
3. Run the behavioral simulation to view the testbench waveforms.
4. Open the `.pdsprj` file in Proteus to view the hardware interaction simulation.

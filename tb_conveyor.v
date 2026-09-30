`timescale 1ns / 1ps

module tb_conveyor_fsm();

    // Inputs
    reg clk;
    reg rst;
    reg object_detected;
    reg is_defective;

    // Outputs
    wire belt_motor;
    wire sorter_arm;

    // Instantiate the Unit Under Test (UUT)
    conveyor_fsm uut (
        .clk(clk), 
        .rst(rst), 
        .object_detected(object_detected), 
        .is_defective(is_defective), 
        .belt_motor(belt_motor), 
        .sorter_arm(sorter_arm)
    );

    // Clock generation: 10ns period (100 MHz)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Test Sequence
    initial begin
        // Initialize Inputs
        rst = 1;
        object_detected = 0;
        is_defective = 0;

        // Wait 20 ns for global reset to finish
        #20;
        rst = 0;
        #10;
        
        $display("--- Starting Conveyor FSM Simulation ---");

        // Test Case 1: No object on belt
        // Expected: State remains IDLE, belt_motor=0, sorter_arm=0
        $display("Time=%0t: Test Case 1 - No Object", $time);
        #20;
        
        // Test Case 2: Standard object detected
        // Expected: State transitions IDLE -> SCAN -> ACCEPT. belt_motor=1, sorter_arm=0
        $display("Time=%0t: Test Case 2 - Standard Object Detected", $time);
        object_detected = 1;
        is_defective = 0;
        #30; // Wait for state transitions
        
        // Object leaves the sensor area
        // Expected: State transitions ACCEPT -> IDLE. belt_motor=0, sorter_arm=0
        object_detected = 0;
        #20;
        
        // Test Case 3: Defective object detected
        // Expected: State transitions IDLE -> SCAN -> REJECT. belt_motor=1, sorter_arm=1
        $display("Time=%0t: Test Case 3 - Defective Object Detected", $time);
        object_detected = 1;
        is_defective = 1;
        #30; // Wait for state transitions
        
        // Defective object leaves the sensor area
        // Expected: State transitions REJECT -> IDLE. belt_motor=0, sorter_arm=0
        object_detected = 0;
        is_defective = 0;
        #20;

        $display("--- Simulation Complete ---");
        $finish;
    end
    
    // Monitor changes in signals and print them to the Vivado TCL console
    initial begin
        $monitor("Time=%0t | rst=%b | obj_det=%b | def=%b || belt_motor=%b | sorter_arm=%b", 
                 $time, rst, object_detected, is_defective, belt_motor, sorter_arm);
    end

endmodule

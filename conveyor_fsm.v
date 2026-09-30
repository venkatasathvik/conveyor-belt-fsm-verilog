`timescale 1ns / 1ps

module conveyor_fsm (
    input clk,
    input rst,
    input object_detected, // From Arduino/Sensor
    input is_defective,    // From Arduino/Sensor
    output reg belt_motor,
    output reg sorter_arm
);

    // State Encodings
    parameter IDLE   = 2'b00;
    parameter SCAN   = 2'b01;
    parameter ACCEPT = 2'b10;
    parameter REJECT = 2'b11;

    reg [1:0] current_state, next_state;

    // State Transition (Synchronous)
    always @(posedge clk or posedge rst) begin
        if (rst)
            current_state <= IDLE;
        else
            current_state <= next_state;
    end

    // Next State Logic (Combinational)
    always @(*) begin
        case (current_state)
            IDLE: begin
                if (object_detected)
                    next_state = SCAN;
                else
                    next_state = IDLE;
            end
            
            SCAN: begin
                if (is_defective)
                    next_state = REJECT;
                else if (!is_defective && object_detected)
                    next_state = ACCEPT;
                else
                    next_state = IDLE;
            end
            
            ACCEPT: begin
                if (!object_detected) // Object has passed
                    next_state = IDLE;
                else
                    next_state = ACCEPT;
            end
            
            REJECT: begin
                if (!object_detected) // Object has been diverted
                    next_state = IDLE;
                else
                    next_state = REJECT;
            end
            
            default: next_state = IDLE;
        endcase
    end

    // Output Logic
    always @(*) begin
        case (current_state)
            IDLE: begin
                belt_motor = 0;
                sorter_arm = 0;
            end
            SCAN: begin
                belt_motor = 1;
                sorter_arm = 0;
            end
            ACCEPT: begin
                belt_motor = 1;
                sorter_arm = 0;
            end
            REJECT: begin
                belt_motor = 1;
                sorter_arm = 1; // Activate diversion mechanism
            end
            default: begin
                belt_motor = 0;
                sorter_arm = 0;
            end
        endcase
    end

endmodule

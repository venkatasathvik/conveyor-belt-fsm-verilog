// Pin Definitions
const int irSensorPin = 2;       // Object detection sensor
const int qualitySensorPin = 3;  // Determines if object is defective (e.g., color/metal sensor)
const int beltMotorPin = 8;      // To L298N Motor Driver
const int sorterArmPin = 9;      // To Servo or Solenoid mechanism

// FSM Signals to/from FPGA (if running in hardware-in-the-loop)
const int fpgaDefectiveSignal = 4;
const int fpgaDetectedSignal = 5;

void setup() {
  Serial.begin(9600);
  
  // Configure Sensors
  pinMode(irSensorPin, INPUT);
  pinMode(qualitySensorPin, INPUT);
  
  // Configure Actuators/Outputs
  pinMode(beltMotorPin, OUTPUT);
  pinMode(sorterArmPin, OUTPUT);
  pinMode(fpgaDefectiveSignal, OUTPUT);
  pinMode(fpgaDetectedSignal, OUTPUT);

  // Initialize outputs
  digitalWrite(beltMotorPin, LOW);
  digitalWrite(sorterArmPin, LOW);
}

void loop() {
  bool objectDetected = digitalRead(irSensorPin) == HIGH;
  bool isDefective = digitalRead(qualitySensorPin) == HIGH;

  // Send signals to Verilog FSM (simulated or physical)
  digitalWrite(fpgaDetectedSignal, objectDetected);
  digitalWrite(fpgaDefectiveSignal, isDefective);

  // Local fallback logic for Proteus simulation visualization
  if (objectDetected) {
    digitalWrite(beltMotorPin, HIGH); // Run belt
    
    if (isDefective) {
      Serial.println("Defective object detected! Activating sorter.");
      digitalWrite(sorterArmPin, HIGH); // Divert
      delay(1000);                      // Keep arm extended for 1 sec
    } else {
      Serial.println("Standard object. Passing through.");
      digitalWrite(sorterArmPin, LOW);
    }
  } else {
    digitalWrite(beltMotorPin, LOW);  // Stop belt when empty
    digitalWrite(sorterArmPin, LOW);
  }
  
  delay(100); // Polling delay
}

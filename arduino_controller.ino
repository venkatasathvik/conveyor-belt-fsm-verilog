#include <LiquidCrystal.h>
#include <Servo.h>

// --- Pin Definitions based on Proteus Schematic ---

// Sensors
const int irSensorPin = 2;       // Connected to IR Proximity Sensor (LOGIC TOGGLE)[cite: 2]
const int defectSensorPin = 3;   // Connected to Quality/Defect Sensor (TOGGLE)[cite: 2]

// Actuators
const int beltMotorIN1 = 8;      // Connected to L298N Motor Driver[cite: 2]
const int beltMotorIN2 = 9;      // Connected to L298N Motor Driver[cite: 2]
const int servoPin = 10;         // Connected to Sorter Arm (Servo)[cite: 2]
const int buzzerPin = 11;        // Connected to Reject Buzzer[cite: 2]

// LCD Display (RS, E, D4, D5, D6, D7) mapped to Analog Pins A0-A5[cite: 2]
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Servo Object
Servo sorterArm;

void setup() {
  // Initialize Serial Communication for Virtual Terminal[cite: 2]
  Serial.begin(9600);
  
  // Configure Input Pins
  pinMode(irSensorPin, INPUT);
  pinMode(defectSensorPin, INPUT);
  
  // Configure Output Pins
  pinMode(beltMotorIN1, OUTPUT);
  pinMode(beltMotorIN2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Attach and initialize Servo[cite: 2]
  sorterArm.attach(servoPin);
  sorterArm.write(0); // Set to default resting position

  // Initialize LCD1602[cite: 2]
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("SYSTEM ACTIVE");
  
  // Initial Terminal Output[cite: 2]
  Serial.println("--- CONVEYOR SYSTEM ACTIVE ---");
  Serial.println();
}

void loop() {
  bool objectDetected = digitalRead(irSensorPin) == HIGH;
  bool isDefective = digitalRead(defectSensorPin) == HIGH;

  if (objectDetected) {
    // Run Belt Motor (Forward)[cite: 2]
    digitalWrite(beltMotorIN1, HIGH);
    digitalWrite(beltMotorIN2, LOW);

    // Terminal Output Matching Image[cite: 2]
    Serial.println("Object Detected: YES");

    if (isDefective) {
      // Terminal Output Matching Image[cite: 2]
      Serial.println("Defective: YES [REJECT]");
      Serial.println("Activating Sorting Arm...");
      Serial.println();
      
      // LCD Update
      lcd.setCursor(0, 1);
      lcd.print("Status: REJECT  ");

      // Trigger Buzzer and move Servo to divert[cite: 2]
      digitalWrite(buzzerPin, HIGH);
      sorterArm.write(90); 
      
      delay(1500); // Hold arm and buzzer for 1.5 seconds to sort object
      
      // Reset Actuators
      digitalWrite(buzzerPin, LOW);
      sorterArm.write(0);
    } else {
      // Standard Object Logic
      Serial.println("Defective: NO  [PASS]");
      Serial.println();
      
      // LCD Update
      lcd.setCursor(0, 1);
      lcd.print("Status: PASS    ");
      
      // Ensure Buzzer and Arm remain off[cite: 2]
      digitalWrite(buzzerPin, LOW);
      sorterArm.write(0);
      
      delay(1000); // Delay to allow object to pass
    }
  } else {
    // Stop Belt Motor when empty[cite: 2]
    digitalWrite(beltMotorIN1, LOW);
    digitalWrite(beltMotorIN2, LOW);
    
    // Default Status
    lcd.setCursor(0, 1);
    lcd.print("Waiting...      ");
    
    digitalWrite(buzzerPin, LOW);
    sorterArm.write(0);
  }
  
  delay(200); // Basic polling delay for stability
}

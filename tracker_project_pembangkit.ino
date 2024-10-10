#include <Servo.h>

// Pin definitions for the LDRs
const int ldrTopLeft = A0;
const int ldrBottomLeft = A1;
const int ldrTopRight = A2;
const int ldrBottomRight = A3;

// Servo objects
Servo horizontalServo;
Servo verticalServo;

// Servo pin definitions
const int horizontalServoPin = 7;
const int verticalServoPin = 9;

// Servo position variables
int horizontalServoPos = 90; // Start position at 90 degrees
int verticalServoPos = 90;   // Start position at 90 degrees

// Threshold for LDR value difference
const int threshold = 5;

void setup() {
  // Attach the servo objects to the respective pins
  horizontalServo.attach(horizontalServoPin);
  verticalServo.attach(verticalServoPin);
  
  // Set the initial position of the servos
  horizontalServo.write(horizontalServoPos);
  verticalServo.write(verticalServoPos);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the LDR values
  int topLeftValue = analogRead(ldrTopLeft);
  int bottomLeftValue = analogRead(ldrBottomLeft);
  int topRightValue = analogRead(ldrTopRight);
  int bottomRightValue = analogRead(ldrBottomRight);

  // Calculate average values for each axis
  int avgLeft = (topLeftValue + bottomLeftValue) / 2;
  int avgRight = (topRightValue + bottomRightValue) / 2;
  int avgTop = (topLeftValue + topRightValue) / 2;
  int avgBottom = (bottomLeftValue + bottomRightValue) / 2;

  // Print LDR values to the serial monitor (optional)
  Serial.print("Top Left: "); Serial.print(topLeftValue);
  Serial.print(" | Bottom Left: "); Serial.print(bottomLeftValue);
  Serial.print(" | Top Right: "); Serial.print(topRightValue);
  Serial.print(" | Bottom Right: "); Serial.println(bottomRightValue);

  // Adjust horizontal servo position
  if (abs(avgLeft - avgRight) > threshold) {
    if (avgLeft > avgRight) {
      horizontalServoPos = min(horizontalServoPos + 1, 135);
    } else {
      horizontalServoPos = max(horizontalServoPos - 1, 45);
    }
  }

  // Adjust vertical servo position
  if (abs(avgTop - avgBottom) > threshold) {
    if (avgTop > avgBottom) {
      verticalServoPos = min(verticalServoPos + 1, 180);
    } else {
      verticalServoPos = max(verticalServoPos - 1, 0);
    }
  }

  // Write new positions to the servos
  horizontalServo.write(horizontalServoPos);
  verticalServo.write(verticalServoPos);

  // Small delay to allow servos to move smoothly
  delay(10);
}

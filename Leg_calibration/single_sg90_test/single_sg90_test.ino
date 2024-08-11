#include <Servo.h>

Servo myServo;  // Create a Servo object

void setup() {
  myServo.attach(12);  // Attach the servo to pin 12
  Serial.begin(9600);
  Serial.println("Servo Test");
}

void loop() {
  // Move the servo to 0 degrees
  myServo.write(0);
  Serial.println("Servo at 0 degrees");
  delay(1000);  // Wait for 1 second

  // Move the servo to 90 degrees
  myServo.write(90);
  Serial.println("Servo at 90 degrees");
  delay(1000);  // Wait for 1 second

  // Move the servo to 180 degrees
  myServo.write(180);
  Serial.println("Servo at 180 degrees");
  delay(1000);  // Wait for 1 second
}

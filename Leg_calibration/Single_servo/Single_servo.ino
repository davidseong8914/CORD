#include <Servo.h>

Servo servo;
int angle;

void setup() {
  servo.attach(2);
  servo.write(5);
}

void loop() 
{ 
  // angle = 171;
  // servo.write(angle);
  // delay(10);

}


// #include <Servo.h>  // Include the Servo library
// Servo myservo;

// void setup() {
//   Serial.begin(9600);
//   // initialize digital pin LED_BUILTIN as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
//   myservo.attach(8);  // Attach the servo to pin 9

// }

// // the loop function runs over and over again forever
// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//   delay(50);                      // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//   delay(50);                      // wait for a second

//   for (int pos = 70; pos <= 150; pos += 10) {
//     myservo.write(pos);  // Set the servo position
//     delay(200);           // Wait 15 ms for the servo to reach the position
//   }

//   delay(100);  // Wait for .1 second
//   // Move the servo smoothly from 180 to 0 degrees
//   for (int pos = 70; pos >= 150; pos -= 10) {
//     myservo.write(pos);  // Set the servo position
//     delay(200);           // Wait 15 ms for the servo to reach the position

//   }
// }

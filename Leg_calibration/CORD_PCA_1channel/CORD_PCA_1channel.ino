// one channel tester

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Initialize the PCA9685 board
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); // Default address 0x40

// Servo pulse length limits
#define SERVOMIN  125 // Minimum pulse length count (out of 4096)
#define SERVOMAX  625 // Maximum pulse length count (out of 4096)

// Function to map degree angles to PCA9685 pulse width
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing PCA9685...");

  pwm.begin();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates

  Serial.println("PCA9685 Initialized.");
  
  // Set servo on channel 8 to 90 degrees as a starting position
  // pwm.setPWM(8, 0, angleToPulse(35));
  delay(1000);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second


  pwm.setPWM(7, 0, angleToPulse(75));
  pwm.setPWM(6, 0, angleToPulse(75));
  pwm.setPWM(8, 0, angleToPulse(75));
  delay(500);


  pwm.setPWM(7, 0, angleToPulse(115));
  pwm.setPWM(6, 0, angleToPulse(115));
  pwm.setPWM(8, 0, angleToPulse(115));
  delay(500);

}


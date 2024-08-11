#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // Minimum pulse length count (out of 4096)
#define SERVOMAX  600 // Maximum pulse length count (out of 4096)

// Servo channels for calibration
uint8_t servoChannels[] = {1, 2};

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Calibration");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}

void loop() {
  // Iterate over each servo for calibration
  for (int i = 0; i < sizeof(servoChannels); i++) {
    uint8_t servo = servoChannels[i];
    Serial.print("Calibrating Servo: ");
    Serial.println(servo);
    
    // Move the servo from min to max
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      pwm.setPWM(servo, 0, pulselen);
      delay(10);
    }

    // Hold position for a moment
    delay(1000);

    // Move the servo from max to min
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
      pwm.setPWM(servo, 0, pulselen);
      delay(10);
    }

    // Hold position for a moment
    delay(1000);
  }
}

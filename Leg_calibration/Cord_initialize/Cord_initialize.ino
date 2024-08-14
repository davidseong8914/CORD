#include <Servo.h> 

// initialize servos
Servo leg1;
Servo leg2;
Servo leg3;
Servo leg4;
Servo leg5;
Servo leg6;
Servo leg7;
Servo leg8;

// Define initial angles for each leg
int initialAngles[8] = {165, 36, 165, 5, 30, 165, 10, 174};

// Define standby angles for each leg (0~3) add 45, (4~7) add 110 angle (leg 8 subtract extra 5)
int standbyAngles[8] = {125, 76, 125, 45, 135, 60, 115, 64};

// Function to gradually move a servo to a target angle
void moveServoSmooth(Servo &servo, int startAngle, int endAngle) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      servo.write(angle);
      delay(15);  // Adjust the delay for speed (smaller value = faster movement)
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      servo.write(angle);
      delay(15);  // Adjust the delay for speed (smaller value = faster movement)
    }
  }
}

void setup() {
  // Blink LED 3 times to check if the program is running
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }

  // Attach servo to corresponding pin
  leg1.attach(2);
  leg1.write(initialAngles[0]);

  leg2.attach(3);
  leg2.write(initialAngles[1]);

  leg3.attach(4);
  leg3.write(initialAngles[2]);

  leg4.attach(5);
  leg4.write(initialAngles[3]);

  leg5.attach(6);
  leg5.write(initialAngles[4]);

  leg6.attach(7);
  leg6.write(initialAngles[5]);

  leg7.attach(8);
  leg7.write(initialAngles[6]);

  leg8.attach(9);
  leg8.write(initialAngles[7]);

  delay(300);

  // Move servos for legs 1 to 4 to the standby positions
  int maxSteps = 0;
  for (int i = 0; i < 4; i++) {
    int steps = abs(standbyAngles[i] - initialAngles[i]);
    if (steps > maxSteps) {
      maxSteps = steps;
    }
  }

  for (int step = 0; step <= maxSteps; step++) {
    if (step <= abs(standbyAngles[0] - initialAngles[0])) {
      leg1.write(map(step, 0, abs(standbyAngles[0] - initialAngles[0]), initialAngles[0], standbyAngles[0]));
    }
    if (step <= abs(standbyAngles[1] - initialAngles[1])) {
      leg2.write(map(step, 0, abs(standbyAngles[1] - initialAngles[1]), initialAngles[1], standbyAngles[1]));
    }
    if (step <= abs(standbyAngles[2] - initialAngles[2])) {
      leg3.write(map(step, 0, abs(standbyAngles[2] - initialAngles[2]), initialAngles[2], standbyAngles[2]));
    }
    if (step <= abs(standbyAngles[3] - initialAngles[3])) {
      leg4.write(map(step, 0, abs(standbyAngles[3] - initialAngles[3]), initialAngles[3], standbyAngles[3]));
    }
    delay(15);  // Adjust the delay for speed (smaller value = faster movement)
  }

  // Move servos for legs 5 to 8 to the standby positions
  maxSteps = 0;
  for (int i = 4; i < 8; i++) {
    int steps = abs(standbyAngles[i] - initialAngles[i]);
    if (steps > maxSteps) {
      maxSteps = steps;
    }
  }

  for (int step = 0; step <= maxSteps; step++) {
    if (step <= abs(standbyAngles[4] - initialAngles[4])) {
      leg5.write(map(step, 0, abs(standbyAngles[4] - initialAngles[4]), initialAngles[4], standbyAngles[4]));
    }
    if (step <= abs(standbyAngles[5] - initialAngles[5])) {
      leg6.write(map(step, 0, abs(standbyAngles[5] - initialAngles[5]), initialAngles[5], standbyAngles[5]));
    }
    if (step <= abs(standbyAngles[6] - initialAngles[6])) {
      leg7.write(map(step, 0, abs(standbyAngles[6] - initialAngles[6]), initialAngles[6], standbyAngles[6]));
    }
    if (step <= abs(standbyAngles[7] - initialAngles[7])) {
      leg8.write(map(step, 0, abs(standbyAngles[7] - initialAngles[7]), initialAngles[7], standbyAngles[7]));
    }
    delay(15);  // Adjust the delay for speed (smaller value = faster movement)
  }
}

void loop() {
}

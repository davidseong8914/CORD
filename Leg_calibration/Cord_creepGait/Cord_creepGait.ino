#include <Servo.h>

Servo leg1;
Servo leg2;
Servo leg3;
Servo leg4;
Servo leg5;
Servo leg6;
Servo leg7;
Servo leg8;

// reduce 10 angles each for better gait
int standAngles[8] = {135, 66, 135, 35, 125, 70, 105, 74};

void stand(Servo servos[], int standAngles[], int numServos) {
  bool movementComplete = false;

  int upperInitial[4] = {servos[0].read(), servos[1].read(), servos[2].read(), servos[3].read()};
  int lowerInitial[4] = {servos[4].read(), servos[5].read(), servos[6].read(), servos[7].read()};

  int upperStand[4] = {standAngles[0], standAngles[1], standAngles[2], standAngles[3]};
  int lowerStand[4] = {standAngles[4], standAngles[5], standAngles[6], standAngles[7]};
  

  // Slowly move upper legs to stand position
  for (int step = 0; step <= 100; step++) {
    for (int i = 0; i < 4; i++) {
      int angle = map(step, 0, 100, upperInitial[i], upperStand[i]);
      servos[i].write(angle);
    }
    delay(20);  // Adjust this delay to control the speed of movement
  }

  // Slowly move lower legs to stand position
  for (int step = 0; step <= 100; step++) {
    for (int i = 0; i < 4; i++) {
      int angle = map(step, 0, 100, lowerInitial[i], lowerStand[i]);
      servos[i+4].write(angle);
    }
    delay(20);  // Adjust this delay to control the speed of movement
  }

}

// Function to move a single leg (both upper and lower segments)
void moveLeg(Servo &upperLeg, Servo &lowerLeg, bool upperClosertoZero, bool lowerClosertoZero, int currentUpper, int currentLower) {

  // move lower leg up
  if (lowerClosertoZero) {
    lowerLeg.write(currentLower + 20);
  } else {
    lowerLeg.write(currentLower - 20);
  }

  delay(200);

  // move upper leg forward
  if (upperClosertoZero) {
    upperLeg.write(currentUpper + 10);
  } else {
    upperLeg.write(currentUpper - 10);
  }

  delay(200);

  // move lower leg down
  lowerLeg.write(currentLower);

  delay(200);

  // move upper leg to original position
  upperLeg.write(currentUpper);

  delay(200);

}

void setup() {
    // Attach each servo to its corresponding pin
    leg1.attach(2);
    leg2.attach(3);
    leg3.attach(4);
    leg4.attach(5);
    leg5.attach(6);
    leg6.attach(7);
    leg7.attach(8);
    leg8.attach(9);

    delay(1000);

    Servo servos[8] = {leg1, leg2, leg3, leg4, leg5, leg6, leg7, leg8};
    stand(servos, standAngles, 8);

    // Implement the crawl gait
    for (int step = 0; step < 3; step++) {

      // Move legs 4 and 8 (right back leg)
      moveLeg(leg4, leg8, true, true, standAngles[3], standAngles[7]);

      // Move legs 2 and 6 (right front leg)
      moveLeg(leg2, leg6, true, true, standAngles[1], standAngles[5]);

      // Move legs 3 and 7 (left back leg)
      moveLeg(leg3, leg7, false, false, standAngles[2], standAngles[6]);

      // Move legs 1 and 5 (left front leg)
      moveLeg(leg1, leg5, false, false, standAngles[0], standAngles[4]);

    }

    // Return to initial standby position
    for (int i = 0; i < 8; i++) {
      servos[i].write(standAngles[i]);
    }
    
}

void loop() {
    // Nothing to do in loop
}
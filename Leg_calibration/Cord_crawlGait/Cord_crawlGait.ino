#include <Servo.h>

// initialize the servos
Servo leg1;
Servo leg2;
Servo leg3;
Servo leg4;
Servo leg5;
Servo leg6;
Servo leg7;
Servo leg8;

// CORD's initial angles

// leg1: 170
// leg2: 31
// leg3: 165
// leg4: 0
// leg5: 25
// leg6: 170
// leg7: 17
// leg8: 179

// legs 1~4: 35 degree rotation for standing position
// legs 5~8: 100 degree rotation for standing position (+ minor adjustments)

// initialize standing angles
int standAngles[8] = {135, 66, 130, 35, 125, 70, 105, 74};

// Make CORD stand up
void stand(Servo servos[], int standAngles[], int numServos) {
  bool movementComplete = false;

  // initialize the initial angles of the servos
  int upperInitial[4] = {servos[0].read(), servos[1].read(), servos[2].read(), servos[3].read()};
  int lowerInitial[4] = {servos[4].read(), servos[5].read(), servos[6].read(), servos[7].read()};

  // initialize the stand angles of the servos
  int upperStand[4] = {standAngles[0], standAngles[1], standAngles[2], standAngles[3]};
  int lowerStand[4] = {standAngles[4], standAngles[5], standAngles[6], standAngles[7]};
  

// upper leg stand
  while (!movementComplete) {
    movementComplete = true;
    for (int i = 0; i < 4; i++) {
      if (upperInitial[i] < upperStand[i]) {
        upperInitial[i]++;
        servos[i].write(upperInitial[i]);
        movementComplete = false;
      } else if (upperInitial[i] > upperStand[i]) {
        upperInitial[i]--;
        servos[i].write(upperInitial[i]);
        movementComplete = false;
      }
    }
    delay(20);
  }

  movementComplete = false;

  // lower leg stand
  while (!movementComplete) {
    movementComplete = true;
    for (int i = 0; i < 4; i++) {
      if (lowerInitial[i] < lowerStand[i]) {
        lowerInitial[i]++;
        servos[i].write(lowerInitial[i]);
        movementComplete = false;
      } else if (lowerInitial[i] > lowerStand[i]) {
        lowerInitial[i]--;
        servos[i].write(lowerInitial[i]);
        movementComplete = false;
      }
    }
    delay(20);
  }

}

// Moving 1 leg (upper and lower) - crawl gait
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
    // leg move order: 4 -> 2 -> 3 -> 1
    // repeat for n times
    int n = 3;
    for (int step = 0; step < n; step++) {

      // Move legs 4 and 8 (right back leg)
      moveLeg(leg4, leg8, true, true, standAngles[3], standAngles[7]);

      // Move legs 2 and 6 (right front leg)
      moveLeg(leg2, leg6, true, true, standAngles[1], standAngles[5]);

      // Move legs 3 and 7 (left back leg)
      moveLeg(leg3, leg7, false, false, standAngles[2], standAngles[6]);

      // Move legs 1 and 5 (left front leg)
      moveLeg(leg1, leg5, false, false, standAngles[0], standAngles[4]);

    }

    // Return to initial standing position
    for (int i = 0; i < 8; i++) {
      servos[i].write(standAngles[i]);
    }
    
}

void loop() {
}
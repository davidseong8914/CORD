#include <Servo.h>

Servo leg1;
Servo leg2;
Servo leg3;
Servo leg4;
Servo leg5;
Servo leg6;
Servo leg7;
Servo leg8;

// Standing leg angles
// int standbyAngles[8] = {125, 76, 125, 45, 135, 60, 115, 64};

// reduce 10 angles each for better gait
int standAngles[8] = {135, 66, 135, 35, 125, 70, 105, 74}

void stand(Servo servos[], int standAngles[], int numServos) {
  bool movementComplete = false;

  int upperInitial[4] = {servos[0].read(), servos[1].read(), servos[2].read(), servos[3].read()}
  int lowerInitial[4] = {servos[4].read(), servos[5].read(), servos[6].read(), servos[4].read()}

  int upperStand[4] = {standAngles[0], standAngles[1], standAngles[2], standAngles[3]}
  int lowerStand[4] = {standAngles[4], standAngles[5], standAngles[5], standAngles[6]}
  

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

  // lower leg stand
  while (!movementComplete) {
    movementcomplete = true;
    for (int i = 0; i < 4; i++) {
      if (lowerInitial[i] < lowerStand[i]) {
        lowerInitial[i]++;
        servos[i+4].write(lowerInitial[i]);
        moementComplete = false;
      } else if (lowerInitial[i] > lowerStand[i]) {
        lowerInitial[i]--;
        servos[i+4].write(lowerInitial[i]);
        movementComplete = false;
      }
    }
    delat(20);
  }

}

// Function to move a single leg (both upper and lower segments)
void moveLeg(Servo &upperLeg, Servo &lowerLeg, bool closerToZero) {
    // Raise the leg by adjusting from the standby angle
    upperLeg.write(standbyAngleUpper + xAdjustmentUpper);
    lowerLeg.write(standbyAngleLower + xAdjustmentLower);
    delay(300); 
    
    // Move the leg forward
    upperLeg.write(standbyAngleUpper + stepAngleUpper);
    lowerLeg.write(standbyAngleLower + stepAngleLower);
    delay(300);
    
    // Lower the leg back to the adjusted standby position
    upperLeg.write(standbyAngleUpper + xAdjustmentUpper);
    lowerLeg.write(standbyAngleLower + xAdjustmentLower);
    delay(300);
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

    Servo servos[8] = {leg1, leg2, leg3, leg4, leg5, leg6, leg7, leg8}
    stand(servos, standAngles, 8)

    // Implement the crawl gait
    for (int step = 0; step < 3; step++) {
        // Move Leg 1 and 5 (left front leg)
        moveLeg(leg1, leg5, standbyAngles[0], standbyAngles[4], 30, 10, 15, 5);
        
        // Move Leg 2 and 6 (right front leg)
        moveLeg(leg2, leg6, standbyAngles[1], standbyAngles[5], 30, 10, 15, 5);
        
        // Move Leg 3 and 7 (left back leg)
        moveLeg(leg3, leg7, standbyAngles[2], standbyAngles[6], 30, 10, 15, 5);
        
        // Move Leg 4 and 8 (right back leg)
        moveLeg(leg4, leg8, standbyAngles[3], standbyAngles[7], 30, 10, 15, 5);
    }

    // Return to initial standby position
    leg1.write(standbyAngles[0]);
    leg2.write(standbyAngles[1]);
    leg3.write(standbyAngles[2]);
    leg4.write(standbyAngles[3]);
    leg5.write(standbyAngles[4]);
    leg6.write(standbyAngles[5]);
    leg7.write(standbyAngles[6]);
    leg8.write(standbyAngles[7]);
}

void loop() {
    // Nothing to do in loop
}
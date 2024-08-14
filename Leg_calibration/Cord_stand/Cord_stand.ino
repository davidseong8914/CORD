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
int standbyAngles[8] = {125, 76, 125, 45, 135, 60, 115, 64};

// Function to gradually move a set of servos to their target angles equally
void moveServosSmoothly(Servo servos[], int currentAngles[], int targetAngles[], int numServos) {
    bool movementComplete = false;

    while (!movementComplete) {
        movementComplete = true;  // Assume all movements are complete

        for (int i = 0; i < numServos; i++) {
            if (currentAngles[i] < targetAngles[i]) {
                currentAngles[i]++;
                servos[i].write(currentAngles[i]);
                movementComplete = false;
            } else if (currentAngles[i] > targetAngles[i]) {
                currentAngles[i]--;
                servos[i].write(currentAngles[i]);
                movementComplete = false;
            }
        }
        delay(20);  // Adjust motor movement speed
    }
}

void setup() {
    // Attach servo to corresponding pin
    leg1.attach(2);
    leg2.attach(3);
    leg3.attach(4);
    leg4.attach(5);
    leg5.attach(6);
    leg6.attach(7);
    leg7.attach(8);
    leg8.attach(9);

    // Read and assign current leg angles
    int currentAngles1[4] = {leg1.read(), leg2.read(), leg3.read(), leg4.read()};
    int currentAngles2[4] = {leg5.read(), leg6.read(), leg7.read(), leg8.read()};

    // Legs 1~4: Upper Legs
    // Legs 5~8: Lower Legs
    Servo servos1[4] = {leg1, leg2, leg3, leg4};
    Servo servos2[4] = {leg5, leg6, leg7, leg8};

    // Target angles for each leg group
    int targetAngles1[4] = {standbyAngles[0], standbyAngles[1], standbyAngles[2], standbyAngles[3]};
    int targetAngles2[4] = {standbyAngles[4], standbyAngles[5], standbyAngles[6], standbyAngles[7]};

    // Stretch upper legs (45 degrees)
    moveServosSmoothly(servos1, currentAngles1, targetAngles1, 4);

    // Stretch lower legs (110 degrees)
    moveServosSmoothly(servos2, currentAngles2, targetAngles2, 4);
}

void loop() {
}

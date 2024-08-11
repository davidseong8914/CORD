#include <Adafruit_PWMServoDriver.h>

// Initialize the PCA9685 board
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40); // Default address 0x40

// Servo pulse length limits
#define SERVOMIN  125 // Minimum pulse length count (out of 4096)
#define SERVOMAX  625 // Maximum pulse length count (out of 4096)

// Initial positions for each leg
int initialPositions[8] = {90, 90, 90, 90, 90, 90, 90, 90};

// Function to map degree angles to PCA9685 pulse width
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60); // Analog servos run at ~60 Hz updates

  // Initialize servos to specified angles
  for (int i = 8; i < 16; i++) {
    board1.setPWM(i, 0, angleToPulse(initialPositions[i]));
  }
}

void loop() {
}



// // // this used to work
// #include <Adafruit_PWMServoDriver.h>
// Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);       // called this way, it uses the default address 0x40   

// #define SERVOMIN  125                                                 // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  625                                                 // this is the 'maximum' pulse length count (out of 4096)

// void setup() {
//   Serial.begin(9600);
//   Serial.println("16 channel Servo test!");
//   board1.begin();
//   board1.setPWMFreq(60);                  // Analog servos run at ~60 Hz updates
// }

// void loop() 
//   { for(int i=8; i<12; i++)
//       { board1.setPWM(i, 0, angleToPulse(0) );}
//     delay(1000);
    
//     for( int angle =80; angle<120; angle +=10)
//       { for(int i=0; i<8; i++)
//           { board1.setPWM(i, 0, angleToPulse(angle) );}
//       }
//     delay(100);
//   }

// int angleToPulse(int ang)                             //gets angle in degree and returns the pulse width
//   {  int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
//      Serial.print("Angle: ");Serial.print(ang);
//      Serial.print(" pulse: ");Serial.println(pulse);
//      return pulse;
//   }


# Cheap and Opensource Robot Dog (CORD)
Project to enable starter roboticists to build a cheap, easy quadruped robot.

### CORD v1.0 :
#### 1. Goal
Build a robot dog using only sg90 servos and an Arduino.

#### 2. Recipe
1. 8x SG90 servos
2. Arduino (Uno or Nano)
3. 3D printed parts (150 x 150 x 150 printer printable)
4. 2x 18650 Lipo (3.7V, 3500mAh)
   1. (Power souce to connect to V_in and Gnd of Arduino)
5. Breadboard power rail
6. lots and lots of wires

#### 3. Render
Designed with Fusion 360
![alt text](Renders/CORD_render.png)
<!-- ![alt text](Renders/CORD.jpg) -->


#### 4. Structure

```cpp
leg 5         leg 6
|                |
|                |
|-| leg 1      |-| leg 2
  |            |
  |____________|
  |            |
  |    BODY    |
  |____________|
  | leg 3      | leg 4
  |            |
|-|            |-| 
|                |
|                |
leg 7      leg 8
```

#### 5. Instructions
1. Acquire required components
2. Print, put together 3D print parts
3. Calibrate legs
   1. Configure resting servo angles
   2. Cord_initialize.ino
   3. Cord_stand.ino
   4. Cord_crawlGait.ino
4. Develop new gait algorithms & functions!

#### 6. CORD v1.0
![alt text](Renders/CORD_real.jpg)

#### 7. Moving Forward:
Possible Additions:
1. MG90s: Higher torque servos (13.6g;2.2kg/cm;10/27.59\$)
   1. SG90 (9g;1.6kg/cm;10/18.99\$)
2. PCA9685: Servo Driver (scalable and organized servo control)
3. LM2596: Step Down Converter 
   1. Limitation: Output current limited to 2000mAh
4. Arduino Nano: Reduce size 
5. Arduino Ultrasonic Sensor: Obstacle avoidance
6. Trot gait, creep gait
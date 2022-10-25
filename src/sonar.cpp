// #include <Arduino.h>

// float distance1 = 0;
// float distance2 = 0;
// float distance3 = 0;

// /*
// HCSR04(trigger, echo, temperature, distance)
// trigger     - trigger pin
// echo        - echo pin
// temperature - ambient temperature, in C
// distance    - maximun measuring distance, in cm
// */
// HCSR04 ultrasonicSensor_01(4, 25, 20, 300);
// HCSR04 ultrasonicSensor_02(4, 33, 20, 300);
// HCSR04 ultrasonicSensor_03(4, 32, 20, 300);

// void setup() {
//     Serial.begin(921600);

//     ultrasonicSensor_01.begin();  // set trigger as output & echo pin as input
//     ultrasonicSensor_02.begin();  // set trigger as output & echo pin as input
//     ultrasonicSensor_03.begin();  // set trigger as output & echo pin as input
// }

// void loop() {
//     distance1 = ultrasonicSensor_01.getMedianFilterDistance();  // pass 3 measurements through median filter, better result on moving obstacles
//     distance2 = ultrasonicSensor_02.getMedianFilterDistance();  // pass 3 measurements through median filter, better result on moving obstacles
//     distance3 = ultrasonicSensor_03.getMedianFilterDistance();  // pass 3 measurements through median filter, better result on moving obstacles

//     Serial.print(F("1: "));
//     Serial.print(distance1, 1);

//     Serial.print(F(" 2: "));
//     Serial.print(distance2, 1);

//     Serial.print(F(" 3: "));
//     Serial.print(distance3, 1);

//     Serial.println("");

//     delay(50);  // serial refresh rate
// }

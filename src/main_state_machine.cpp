// #include <Arduino.h>
// #include <HCSR04.h>

// // Motor A connections
// #define IN1 5
// #define IN2 18
// // Motor B connections
// #define IN3 19
// #define IN4 21

// float distanceLeft = 0;
// float distanceMiddle = 0;
// float distanceRight = 0;

// HCSR04 ultrasonicSensorLeft(27, 13, 20, 300);
// HCSR04 ultrasonicSensorMiddle(27, 12, 20, 300);
// HCSR04 ultrasonicSensorRight(27, 14, 20, 300);

// void setup() {
//     Serial.begin(921600);

//     ultrasonicSensorLeft.begin();    // set trigger as output & echo pin as input
//     ultrasonicSensorMiddle.begin();  // set trigger as output & echo pin as input
//     ultrasonicSensorRight.begin();   // set trigger as output & echo pin as input

//     // Set all the motor control pins to outputs
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);
//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);

//     // Turn off motors - Initial state
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);

//     delay(2000);

//     Serial.println("Fisished setup");
// }

// void loop() {
//     distanceLeft = ultrasonicSensorLeft.getMedianFilterDistance();
//     distanceMiddle = ultrasonicSensorMiddle.getMedianFilterDistance();
//     distanceRight = ultrasonicSensorRight.getMedianFilterDistance();

//     Serial.print(F("1: "));
//     Serial.print(distanceLeft, 1);

//     Serial.print(F(" 2: "));
//     Serial.print(distanceMiddle, 1);

//     Serial.print(F(" 3: "));
//     Serial.print(distanceRight, 1);

//     Serial.println("");

//     static unsigned long ylwMillis = millis();
//     static unsigned long delayDuration = 2000;
//     static unsigned long idleStart;
//     static unsigned long rotatingStart;

//     enum class State : uint8_t {
//         IDLE,
//         FORWARD,
//         ROTATING,
//     };

//     static State currentState = State::IDLE;

//     switch (currentState) {
//         case State::IDLE:
//             if (millis() - idleStart >= 2000) {
//                 currentState = State::FORWARD;
//             }

//             break;

//         case State::FORWARD:
//             if (distanceLeft > 10 && distanceMiddle > 10 && distanceRight > 10) {
//                 digitalWrite(IN1, HIGH);
//                 digitalWrite(IN2, LOW);
//                 digitalWrite(IN3, HIGH);
//                 digitalWrite(IN4, LOW);
//                 return;

//             } else {
//                 currentState = State::ROTATING;
//                 rotatingStart = millis();
//             }

//             break;

//         case State::ROTATING:
//             if (millis() - rotatingStart >= 2000)
//                 if (random(0, 2) == 1) {
//                     digitalWrite(IN1, HIGH);
//                     digitalWrite(IN2, LOW);
//                     digitalWrite(IN3, LOW);
//                     digitalWrite(IN4, HIGH);
//                 } else {
//                     digitalWrite(IN1, LOW);
//                     digitalWrite(IN2, HIGH);
//                     digitalWrite(IN3, HIGH);
//                     digitalWrite(IN4, LOW);
//                 }
//             break;

//         default:
//             break;
//     }

//     if (distanceLeft > 10 && distanceMiddle > 10 && distanceRight > 10) {
//         digitalWrite(IN1, HIGH);
//         digitalWrite(IN2, LOW);
//         digitalWrite(IN3, HIGH);
//         digitalWrite(IN4, LOW);
//         return;
//     }

//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);
// }

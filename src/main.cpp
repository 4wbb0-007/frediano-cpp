#include <Arduino.h>
#include <HCSR04.h>

// Motor A connections
#define IN1 5
#define IN2 18
// Motor B connections
#define IN3 19
#define IN4 21

float distance1 = 0;
float distance2 = 0;
float distance3 = 0;

HCSR04 ultrasonicSensor_01(27, 13, 20, 300);
HCSR04 ultrasonicSensor_02(27, 12, 20, 300);
HCSR04 ultrasonicSensor_03(27, 14, 20, 300);

void printDistances() {
    distance1 = ultrasonicSensor_01.getMedianFilterDistance();
    distance2 = ultrasonicSensor_02.getMedianFilterDistance();
    distance3 = ultrasonicSensor_03.getMedianFilterDistance();

    Serial.print(F("1: "));
    Serial.print(distance1, 1);

    Serial.print(F(" 2: "));
    Serial.print(distance2, 1);

    Serial.print(F(" 3: "));
    Serial.print(distance3, 1);

    Serial.println("");
}

// This function lets you control spinning direction of motors
void directionControl() {
    // printDistances();
    // // Turn on motor A & B
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(2000);

    // printDistances();

    // // Now change motor directions
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(2000);

    // printDistances();

    // // Turn off motors
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void setup() {
    Serial.begin(921600);
    Serial.println("Setup");

    ultrasonicSensor_01.begin();  // set trigger as output & echo pin as input
    ultrasonicSensor_02.begin();  // set trigger as output & echo pin as input
    ultrasonicSensor_03.begin();  // set trigger as output & echo pin as input

    // Set all the motor control pins to outputs
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Turn off motors - Initial state
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    Serial.println("Looped");
    printDistances();
    directionControl();
    delay(100);
}


#include <Arduino.h>
#include <HCSR04.h>
#include <WiFiManager.h>

// Motor A connections
#define IN1 17
#define IN2 18
// Motor B connections
#define IN3 19
#define IN4 21

#define TEMPERATURE_SENSOR 26

float distanceLeft = 0;
float distanceMiddle = 0;
float distanceRight = 0;

HCSR04 ultrasonicSensorLeft(27, 13, 20, 300);
HCSR04 ultrasonicSensorMiddle(27, 12, 20, 300);
HCSR04 ultrasonicSensorRight(27, 14, 20, 300);

void setup() {
    Serial.begin(921600);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Turn off motors - Initial state
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    digitalWrite(TEMPERATURE_SENSOR, LOW);

    ultrasonicSensorLeft.begin();
    ultrasonicSensorMiddle.begin();
    ultrasonicSensorRight.begin();

    WiFi.mode(WIFI_STA);
    WiFiManager wm;

    bool res;

    res = wm.autoConnect("Frediano");  // password protected ap

    if (!res) {
        Serial.println("Failed to connect");
        ESP.restart();
    } else {
        Serial.println("connected to WIFI");
    }

    delay(2000);

    Serial.println("Fisished setup");
}

void turnLeft() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void turnRight() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void loop() {
    int minimumDistance = 20;

    float temperatureValue = analogRead(TEMPERATURE_SENSOR);
    float volts = temperatureValue / 1024;
    float celcius = (volts - 0.5) * 100 - 5;

    Serial.print("Temperature: ");
    Serial.println(celcius);

    ultrasonicSensorLeft.setTemperature(celcius);
    ultrasonicSensorMiddle.setTemperature(celcius);
    ultrasonicSensorRight.setTemperature(celcius);

    distanceLeft = ultrasonicSensorLeft.getMedianFilterDistance();
    distanceMiddle = ultrasonicSensorMiddle.getMedianFilterDistance();
    distanceRight = ultrasonicSensorRight.getMedianFilterDistance();

    Serial.print(F("1: "));
    Serial.print(distanceLeft, 1);

    Serial.print(F(" 2: "));
    Serial.print(distanceMiddle, 1);

    Serial.print(F(" 3: "));
    Serial.print(distanceRight, 1);

    Serial.println("");

    if (distanceMiddle <= minimumDistance || distanceRight <= minimumDistance) {
        turnLeft();
        return;
    }

    if (distanceLeft <= minimumDistance) {
        turnRight();
        return;
    }

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

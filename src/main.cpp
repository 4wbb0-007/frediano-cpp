
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

float distance1 = 0;
float distance2 = 0;
float distance3 = 0;

HCSR04 ultrasonicSensor1(27, 13, 20, 300);
HCSR04 ultrasonicSensor2(27, 12, 20, 300);
HCSR04 ultrasonicSensor3(27, 14, 20, 300);

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

    ultrasonicSensor1.begin();
    ultrasonicSensor2.begin();
    ultrasonicSensor3.begin();

    // WiFi.mode(WIFI_STA);
    // WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    // wm.resetSettings();

    // res = wm.autoConnect("Frediano");  // password protected ap

    // if (!res) {
    //     Serial.println("Failed to connect");
    //     // ESP.restart();
    // } else {
    //     Serial.println("connected...yeey :)");
    // }

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

    ultrasonicSensor1.setTemperature(celcius);
    ultrasonicSensor2.setTemperature(celcius);
    ultrasonicSensor3.setTemperature(celcius);

    distance1 = ultrasonicSensor1.getMedianFilterDistance();
    distance2 = ultrasonicSensor2.getMedianFilterDistance();
    distance3 = ultrasonicSensor3.getMedianFilterDistance();

    Serial.print(F("1: "));
    Serial.print(distance1, 1);

    Serial.print(F(" 2: "));
    Serial.print(distance2, 1);

    Serial.print(F(" 3: "));
    Serial.print(distance3, 1);

    Serial.println("");

    if (distance2 <= minimumDistance || distance3 <= minimumDistance) {
        turnLeft();
        return;
    }

    if (distance1 <= minimumDistance) {
        turnRight();
        return;
    }

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

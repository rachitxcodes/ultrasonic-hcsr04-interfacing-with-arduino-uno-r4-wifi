#include <Arduino.h>
#define triggerPin 9
#define echoPin 10
void setup() {
// write your initialization code here
    Serial.begin(9600);
    pinMode(triggerPin, INPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
// write your code here
}
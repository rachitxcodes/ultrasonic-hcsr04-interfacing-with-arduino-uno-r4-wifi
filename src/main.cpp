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
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;
    Serial.println("Distance: ");
    Serial.println(distance);
    Serial.println(" cm");
    delay(1000);

}
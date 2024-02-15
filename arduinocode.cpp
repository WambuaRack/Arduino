#include <Arduino.h>
#include <Servo.h>

Servo myServo;
int trigPin = 10;   // Trig pin for ultrasonic sensor
int echoPin = 11;   // Echo pin for ultrasonic sensor
int servoPin = 9;   // PWM pin for servo motor
int obstacleDistance = 20;  // Distance in centimeters to consider as an obstacle

void setup() {
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  // Add this line if you want to use Serial for debugging
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance: ");
  Serial.println(distance);  // Print distance to Serial for debugging

  if (distance <= obstacleDistance) {
    myServo.write(90); // Stop the servo motor
  } else {
    myServo.write(0); // Continue moving the servo motor
  }

  // Add any additional code or delay as needed
}
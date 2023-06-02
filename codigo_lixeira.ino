// Código projeto da lixeira móvel
#include <VarSpeedServo.h>
VarSpeedServo servo_6;

int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int servo_6_pin = 6;

void setup()
{
  Serial.begin(9600);
  servo_6.attach(servo_6_pin);
  servo_6.write(0, 255, true);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(5, 12);
  Serial.println(distancia);
  if (distancia <= 30) {
    servo_6.write(90, 50, true);
  } else {
    servo_6.write(5, 50, true);
  }
  delay(10); // Delay a little bit to improve simulation performance
}

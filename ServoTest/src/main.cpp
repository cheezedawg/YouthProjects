#include <Arduino.h>
#include <Servo.h>

#define SERVO_GPIO 4
#define SERVO_STOP 90
#define SERVO_FORWARD 0
#define SERVO_BACKWARD 180

Servo s;
uint servoSpeed;

void setup() {
  Serial.begin(9600);
  while (! Serial) {
    delay(1);
  }
  Serial.println("Initialize");
  
  s.attach(SERVO_GPIO);
  servoSpeed = 0;
}


void loop() {
  s.write(servoSpeed);
  Serial.println(servoSpeed);
  servoSpeed = servoSpeed + 10;
  delay(1000);
}

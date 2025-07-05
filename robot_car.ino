#include <Servo.h>

#include <Ultrasonic.h>

Servo s = Servo();

Ultrasonic u = Ultrasonic(9, 7);

int pin4 = 10;
int pin3 = 11;
int pin2 = 12;
int pin1 = 13;

char Value;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  s.attach(8);
}

void loop() {
  char x = Serial.read();
  delay(10);
  Serial.println(x);

  if (x == '1') {
    s.write(90);
    delay(200);
    int distance = u.distanceRead(100);
    delay(100);
    if (distance < 10) {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
    }
  }
  if (x == '2') {
    s.write(30);
    delay(200);
    int distance = u.distanceRead(10);
    delay(100);
    if (distance < 10) {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      delay(500);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
    s.write(90);
  }

  if (x == '3') {
    s.write(90);
    delay(200);
    int distance = u.distanceRead(10);
    delay(100);
    if (distance < 10) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
    }
  }
  if (x == '4') {
    s.write(170);
    delay(200);
    int distance = u.distanceRead(10);
    delay(100);
    if (distance < 10) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      delay(500);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
    s.write(90);
  }

  if (x == '5') {
    s.write(90);
    delay(200);
    int distance = u.distanceRead(10);
    delay(100);
    if (distance < 10) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
  }
}

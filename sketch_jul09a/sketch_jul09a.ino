#include <Servo.h>

Servo myservo0;
Servo myservo1;
String inputString = "";

void setup() {
  Serial.begin(9600);
  myservo0.attach(9);
  myservo1.attach(8);
  myservo0.write(0);
  myservo1.write(0);
}

void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      if (inputString == "RUN") {
        runPumpSequence();
      }
      inputString = "";
    } else {
      inputString += inChar;
    }
  }
}

void runPumpSequence() {
  myservo0.write(180);
  myservo1.write(0);
  delay(1500);

  myservo0.write(0);
  myservo1.write(0);
  delay(800);

  myservo0.write(0);
  myservo1.write(180);
  delay(800);

  myservo0.write(0);
  myservo1.write(0);
  delay(1500);
}

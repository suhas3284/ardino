#include <Servo.h>

Servo myservo0;
String inputString = "";

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
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
  myservo0.write(0);
  delay(5000);

  myservo0.write(180);
  delay(5000);

  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);                       // wait for a second
  digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);
}

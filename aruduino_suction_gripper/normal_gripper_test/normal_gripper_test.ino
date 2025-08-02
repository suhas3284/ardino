void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the suction pump on
  delay(5000);                      
  digitalWrite(13, LOW);    // turn the air valve on
  delay(5000);                                                         
}

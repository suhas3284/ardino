void setup() {
  pinMode(13, OUTPUT);       // Relay control pin
  digitalWrite(13, HIGH);    // Start with relay OFF (air vent active)
  Serial.begin(9600);        // Begin serial communication
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();  // Remove trailing newline or whitespace

    if (command == "RUN") {
      digitalWrite(13, LOW);  // Activate relay: suction pump ON
      Serial.println("SUCTION ON");
    }
    else if (command == "STOP") {
      digitalWrite(13, HIGH);   // Deactivate relay: air vent active (NC)
      Serial.println("SUCTION OFF, VENT ON");
    }
  }
}

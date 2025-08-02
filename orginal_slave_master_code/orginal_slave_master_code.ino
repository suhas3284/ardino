String inputString = "";
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      if (inputString == "RUN")} {
        while (i < 5) {
        digitalWrite(13, HIGH);   // turn the suction pump on
        delay(5000);                      
        digitalWrite(13, LOW);    // turn the air valve on
        delay(5000); 
      }
      inputString = "";{
      }else 
      inputString += inChar;
    }
 }

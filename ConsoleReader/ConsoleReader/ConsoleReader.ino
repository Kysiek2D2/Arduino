#define greenDiode 11
#define redDiode 13
String receivedString = "";

void setup() {
  Serial.begin(9600);
  pinMode(greenDiode, OUTPUT);
  pinMode(redDiode, OUTPUT);

  digitalWrite(greenDiode, LOW);
  digitalWrite(redDiode, LOW);
}

void loop() {
  if(Serial.available() > 0 ){ //check if Arduino received message
    receivedString = Serial.readStringUntil('\n'); //read until end of the line
    Serial.println("Received command: " + receivedString);
    Serial.println(receivedString=="green");
    if(receivedString=="green"){
      digitalWrite(redDiode, LOW);
      delay(1000);
      digitalWrite(greenDiode, HIGH);
    }
    else if(receivedString.equalsIgnoreCase("red")){
      digitalWrite(greenDiode, LOW);
      delay(1000);
      digitalWrite(redDiode, HIGH);
    }
    else {
      Serial.println("WRONG COMMAND!");
      delay(120);
    }

  }
}

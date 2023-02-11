int receivedValue = 0;
int pinD = 8;
float voltage = 0.0;
int triggerValue = 0;

void setup() {
  pinMode(pinD, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  receivedValue = analogRead(A5);
  voltage = receivedValue * (5.0 / 1024.0);
  triggerValue = analogRead(A4);

  Serial.println("Received value: " + String(receivedValue)
                 + ", which is " + String(voltage) + " in volts. Trigger value is set to :" + String(triggerValue));

  if (receivedValue < triggerValue) {
    digitalWrite(pinD, HIGH);
  } else {
    digitalWrite(pinD, LOW);
  }
  delay(1000);
}

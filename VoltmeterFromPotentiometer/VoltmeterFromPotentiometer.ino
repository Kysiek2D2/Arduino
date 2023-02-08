#define diode 2

int receivedValue = 0;
float voltage = 0.0;      

void setup() {
  Serial.begin(9600);
  pinMode(diode, OUTPUT);
}

void loop() {
  receivedValue = analogRead(A5); //read voltage on A5 analog-in
  voltage = receivedValue * (5.0/1024.0);
  Serial.println(voltage); //voltage reading from potencjomentr, for curiosity
  delay(200); //small delay to make programm more stable

  digitalWrite(diode, HIGH);
  delay(receivedValue);
  digitalWrite(diode, LOW);
  delay(receivedValue);
}
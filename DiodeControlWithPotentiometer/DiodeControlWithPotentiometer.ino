int const _pin2 = 2, _pin3 = 3, _pin4 = 4, _pin5 = 5, _pin6 = 6;
float receivedValue = 0;
int mappedValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(_pin2, OUTPUT);
  pinMode(_pin3, OUTPUT);
  pinMode(_pin4, OUTPUT);
  pinMode(_pin5, OUTPUT);
  pinMode(_pin6, OUTPUT);
}

void loop() {
  receivedValue = analogRead(A5);
  Serial.println(receivedValue);
  mappedValue = map(receivedValue, 0, 1023, 1, 5);

  if (mappedValue == 1) {
    digitalWrite(_pin2, HIGH);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
  } else if (mappedValue == 2) {
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, HIGH);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
  } else if (mappedValue == 3) {
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, HIGH);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
  } else if (mappedValue == 4) {
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, HIGH);
    digitalWrite(_pin6, LOW);
  } else {
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, HIGH);
  }
  delay(50);  //delay to make program more stable
}

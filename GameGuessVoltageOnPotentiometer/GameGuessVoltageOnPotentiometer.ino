int greenDiode = 10, yellowDiode = 11, redDiode = 12;
int potentiometerRead = 0;
float currentVoltage = 0.0;
int guessedVoltage = 0;
float guessTolerance = 1.0;
int chancesRemaining = 3;
boolean isAnswerCorrect = false;

void setup() {
  pinMode(greenDiode, OUTPUT);
  pinMode(yellowDiode, OUTPUT);
  pinMode(redDiode, OUTPUT);
  setDiodes(3);
  Serial.begin(9600);
}

void loop() {

  while (guessedVoltage == 0) {
    Serial.println("Please guess...");
    guessedVoltage = Serial.readStringUntil('\n').toInt();
    delay(50);
  }

  Serial.println("You guessed " + String(guessedVoltage));

  potentiometerRead = analogRead(A5);

  currentVoltage = potentiometerRead * (5.0 / 1024.0);

  isAnswerCorrect = guessedVoltage * 1.0 <= (currentVoltage + guessTolerance)
                    and guessedVoltage * 1.0 >= (currentVoltage - guessTolerance);

  Serial.println("+: " + String(currentVoltage + guessTolerance) + ",-: " + String((currentVoltage - guessTolerance)));

  if (isAnswerCorrect) {
    Serial.println("CORRECT! Voltage was: " + String(currentVoltage));
    if (!chancesRemaining >= 3) chancesRemaining++;
  } else {
    Serial.println("WRONG! Voltage was: " + String(currentVoltage));
    if (!chancesRemaining <= 0) chancesRemaining--;
  }

  setDiodes(chancesRemaining);
  guessedVoltage = 0;
  isAnswerCorrect = false;
  delay(50);
}

void setDiodes(int chancesLeft) {
  digitalWrite(greenDiode, HIGH);
  digitalWrite(yellowDiode, HIGH);
  digitalWrite(redDiode, HIGH);

  switch (chancesLeft) {
    case 0:
      digitalWrite(redDiode, LOW);
    case 1:
      digitalWrite(yellowDiode, LOW);
    case 2:
      digitalWrite(greenDiode, LOW);
    case 3:
      break;
  }
}

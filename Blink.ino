/**
Project build from: 
https://docs.arduino.cc/built-in-examples/basics/Blink
http://wortal.majsterkowicza.pl/2012/07/kurs-arduino-cz-1-poczatki-czyli-miganie-dioda/
**/

//int outputPin = LED_BUILTIN; //this is for Led that is build-in Arduino board
int outputPin = 8;
int delayTimeInMs = 500;

void setup() {
  // put your setup code here, to run once:
  //pin 8 will be our output
  pinMode(outputPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //diode ON
  digitalWrite(outputPin, HIGH);
  //wait for ...
  delay(delayTimeInMs);    
  //diode OFF
  digitalWrite(outputPin, LOW);
  //wait for ...
  delay(delayTimeInMs);
}

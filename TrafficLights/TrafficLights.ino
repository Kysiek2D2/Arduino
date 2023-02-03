int const RED = 13, ORANGE = 12, GREEN = 11, BUTTON=7;
int orangeLightOnInMs = 3000;
bool changeSequence;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(ORANGE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);

  digitalWrite(RED, LOW);
  digitalWrite(ORANGE, LOW);
  digitalWrite(GREEN, HIGH);

  changeSequence = false;
}

void loop() {
  while(digitalRead(BUTTON)==HIGH){
    changeSequence=true;
  }
  if(changeSequence==true and digitalRead(GREEN)==HIGH){
    digitalWrite(GREEN, LOW);
    digitalWrite(ORANGE, HIGH);
    delay(orangeLightOnInMs);
    digitalWrite(ORANGE, LOW);
    digitalWrite(RED, HIGH);   
    changeSequence=false;
  }
  if(changeSequence==true and digitalRead(GREEN)==LOW){
    digitalWrite(ORANGE,HIGH);
    delay(orangeLightOnInMs);
    digitalWrite(RED, LOW);
    digitalWrite(ORANGE, LOW);
    digitalWrite(GREEN, HIGH);
    changeSequence=false;
  }
}


 


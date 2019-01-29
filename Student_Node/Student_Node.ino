const int ledPin = A0;
const int buttonPin = 4;
int buttonState;
char incomingByte;
char studentNum = '5'; // this should be the same as your ATMY
bool isDataSent = false;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);
}

void loop() {
  queue();
  attend();
}

void attend() {
    if(Serial1.available() > 0) {
      incomingByte = Serial1.read();
      Serial1.print(incomingByte);
      Serial.print(incomingByte);
          if(incomingByte == studentNum) {
          digitalWrite(ledPin, HIGH);
    } 
      if (incomingByte != studentNum) {
          digitalWrite(ledPin, LOW);
    }
 //     if(Serial.available() > 0) {
 //           Serial.print(incomingByte);
 //   }
  }
}


void queue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && isDataSent == false) {
//    Serial1.println(studentNum);
//    Serial1.println(studentNum);
//    Serial1.println(studentNum);
    Serial1.println(studentNum);
    Serial.println(studentNum);
    isDataSent = true;
  }
  if ( buttonState == LOW) {
    isDataSent = false;
  }
}

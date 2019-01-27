const int ledPin = A0;
const int buttonPin = 4;
int buttonState;
char incomingByte;
char studentNum = '5'; // this should be the same as your ATMY
bool myTurn = false;
bool isDataSent = false;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
//  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);
}

void loop() {
  queue();
  attend();
//  if (myTurn == true) {
    Serial.println(incomingByte);
}

void attend() {
    if(Serial1.available() > 0) {
      incomingByte = Serial1.read();
          if(incomingByte == studentNum) {
          digitalWrite(ledPin, HIGH);
    } 
      if (incomingByte == '0') {
          digitalWrite(ledPin, LOW);
    }
      if(Serial.available() > 0) {
            Serial.print(incomingByte);
    }
//    if(incomingByte == '1'){
//      myTurn = true;
//    }
//    if(incomingByte == '0'){
//      myTurn = false;
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
//    delay(1);
//    Serial1.println('X');
    isDataSent = true;
  }
  else if ( buttonState == LOW) {
    isDataSent = false;
  }
}

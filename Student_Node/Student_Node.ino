const int ledPin = A0;
const int buttonPin = 4;
int buttonState;
int incomingByte;
int studentNum = 6; // set your radio number to this 
bool myTurn = false;
bool isDataSent = false;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
  queue();
  attend();
  if (myTurn == true) {
    digitalWrite(ledPin, HIGH);
    } else {
    digitalWrite(ledPin, LOW);
    }
}

void attend() {
    if(Serial1.available() > 0) {
      incomingByte = Serial1.read();
    if(incomingByte == '1'){
      myTurn = true;
    }
    if(incomingByte == '0'){
      myTurn = false;
    }
  }
}

void queue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && isDataSent == false) {
    Serial1.println(studentNum);
    Serial.println(studentNum);
    isDataSent = true;
  }
  else if ( buttonState == HIGH) {
    isDataSent = false;
  }
}

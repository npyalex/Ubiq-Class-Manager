#define ledPin A0
#define buttonPin 4

const char studentNum = '4'; // this should be your radio's ATMY

int buttonState;
char incomingByte = 0;
bool isDataSent = false;

void setup() {
  // Serial Connections
  Serial1.begin(9600);
  Serial.begin(9600);
  // Pin Assignment
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
    //Serial.print(incomingByte);
    if (incomingByte == studentNum) { digitalWrite(ledPin, HIGH); } 
    else if (incomingByte != studentNum) { digitalWrite(ledPin, LOW); }
  }
}


void queue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && isDataSent == false) {
    while(Serial1.read() != 'Y'){Serial1.println(studentNum); delay(200);}
    isDataSent == true;
  } else if (buttonState == HIGH ){
    isDataSent == false;
  }
}

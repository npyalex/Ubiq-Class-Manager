const int ledPin = A0;
const int buttonPin = 4;
int buttonState;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
  queue();
  attend();
  }

void attend() {
    if(Serial1.available() > 0) {
      incomingByte = Serial1.read()();
    if(incomingByte == '1'){
      digitalWrite(ledPin, HIGH);
    }
    if(incomingByte == '0'){
      digitalWrite(ledPin, LOW);
    }
  }
}

void queue() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial1.print('H');
  }
}

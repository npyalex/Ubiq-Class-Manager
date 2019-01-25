int ledPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode (ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0) {
    incomingByte = Serial1.read()();
    if(incomingByte == '1'){
      digitalWrite
    }
  }
}

#define ledPin A0
#define buttonPin 4

int buttonState;
char incomingByte;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);
}

void loop() {
  if(Serial1.available() > 0) {
    incomingByte = Serial1.read();
    // Olivia
    if(incomingByte == '6') {
      //setDestination( '2' );
      delay(1500);
      Serial1.println(1);
      delay(1500);
      Serial1.println(0);
    }
    // Nick
    if(incomingByte == '1') {
      //setDestination( '2' );
      delay(1500);
      Serial1.println(1);
      delay(1500);
      Serial1.println(0);
    }
  }
}

/*void setDestination( String addr ) {
  String destinationAddress = "ATDH" + addr + "\r" ;
  
  Serial1.print("+++");
  char thisByte = 0;
  while (thisByte != '\r') {
    if (Serial1.available() > 0){
      thisByte = Serial1.read();
    }
  }
  Serial1.print("ATDH0, DLFFFF\r");
  Serial1.print(destinationAddress);  
  Serial1.print("ATCN\r");
  Serial.println("Changed Address to " + addr);
}*/

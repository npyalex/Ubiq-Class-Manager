#define buttonPin 4

int buttonState;
bool isButtonPressed = false;
char incomingByte;
int queue[50];
int place = 0;

void setup() {
  // Serial Connections
  Serial1.begin(9600);
  Serial.begin(9600);
  // Pin Assignment
  pinMode (buttonPin, INPUT_PULLUP);
  // Initialize queue
  for (int i = 0 ; i < 50 ; i++){
    queue[i] = 0;
  }
}

void loop() {
  // Check for users and add them to queue
  if(Serial1.available() > 0) {
    incomingByte = Serial1.read();
    // Olivia
    if(incomingByte == '6') {
      Serial1.print('Y');
      // only add them if they aren't the last person on the queue
      if ( queue[place-1] != 6 ) {      
        queue[place] = 6;
        Serial.println(queue[place]);
        place++;
      }
    }
    // Nick
    else if(incomingByte == '5') {
      Serial1.print('Y');
      // only add them if they aren't the last person on the queue
      if ( queue[place-1] != 5 ) {      
        queue[place] = 5;
        Serial.println(queue[place]);
        place++;
      }
    }
    // Carissa
    else if(incomingByte == '4') {
      Serial1.print('Y');
      // only add them if they aren't the last person on the queue
      if ( queue[place-1] != 4 ) {      
        queue[place] = 4;
        Serial.println(queue[place]);
        place++;
      }
    }
  }

  // Turn on the LED of the person who should talk
  if ( digitalRead(buttonPin) == LOW && isButtonPressed == false) {
    isButtonPressed = true;
    char x;
    if ( queue[0] == 4){
      x = '4';
      Serial1.print(x);
      Serial.println(x);
      for ( int i = 0 ; i < 50 ; i++){
        queue[i] = queue[i+1];
      }
      while (Serial1.read() !=  '4') { delay(100); }
    } else if ( queue[0] == 5 ){
      x = '5';
      Serial1.print(x);
      Serial.println(x);
      for ( int i = 0 ; i < 50 ; i++){
        queue[i] = queue[i+1];
      }
    } else if ( queue[0] == 6) {
      x = '6';
      Serial1.print(x);
      Serial.println(x);
      for ( int i = 0 ; i < 50 ; i++){
        queue[i] = queue[i+1];
      }
    } else {
      place = 0;
      x = '0';
      Serial1.print(x);
      Serial.println("no one in queue");
    }
    delay(500);
  } else if ( digitalRead(buttonPin) == HIGH ) {
    isButtonPressed = false;
  }
}

#define buttonPin 4

int buttonState;
char incomingByte;

int number = 0;
int queue[50];

bool isButtonPressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  
  pinMode (buttonPin, INPUT_PULLUP);

  for (int i = 0 ; i < 50 ; i++){
    queue[i] = 0;
  }
}

void loop() {
  if(Serial1.available() > 0) {
    incomingByte = Serial1.read();
    // Olivia
    if(incomingByte == '6') {
      //Serial.print(number);
      //Serial.println("Olivia");
      queue[number] = 6;
      
      Serial.println(queue[number]);
      number++;
      /*Serial1.println(6);
      delay(1000);*/
    }
    // Nick
    else if(incomingByte == '5') {
      //Serial.print(number);
      //Serial.println("Nick");
      queue[number] = 5;
      
      Serial.println(queue[number]);
      number++;
      /*Serial1.println(5);
      delay(1000);*/
    }
    // Carissa
    else if(incomingByte == '4') {
      //Serial.print(number);
      //Serial.println("Carisa");
      queue[number] = 4;
      
      Serial.println(queue[number]);
      number++;
      /*Serial1.println(4);
      delay(1500);*/
    }
  }
  if ( digitalRead(buttonPin) == LOW && isButtonPressed == false) {
    Serial1.print('0');
    delay(500);
    char x;
    if ( queue[0] == 4){
      x = '4';
    } else if ( queue[0] == 5 ){
      x = '5';
    } else if ( queue[0] == 6) {
      x = '6';
    } else {
      x = '0';
    }
    Serial.print(x);
    Serial1.print(x);
    isButtonPressed = true;

    for ( int i = 0 ; i < 50 ; i++){
      queue[i] = queue[i+1];
    }
    delay(500);
  } else if ( digitalRead(buttonPin) == HIGH ) {
    isButtonPressed = false;
  }
}

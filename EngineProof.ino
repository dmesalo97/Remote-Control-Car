char DataBT;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup(){
  
  Serial.begin(9600);  
  
  //Set digital pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Set state of pins all to low
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop(){

   if (Serial.available()){
    
      DataBT = Serial.read(); //Get next character from bluetooth module
      //Forward
      if (DataBT == 'F'){
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          delay(150);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
        }
      //Backward
      if (DataBT == 'B'){
          digitalWrite(IN1, HIGH);
          digitalWrite(IN4, HIGH);
          delay(120);
          digitalWrite(IN1, LOW);
          digitalWrite(IN4, LOW);
        }
      //Stop
      if (DataBT == 'S'){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
        }
      //Turn left
      if (DataBT == 'L'){
          digitalWrite(IN3, HIGH);
          delay(120);
          digitalWrite(IN3, LOW);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
        }
      //Turn right
      if (DataBT == 'R'){
          digitalWrite(IN2, HIGH);
          delay(120);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
        }
    }
  
    delay(10);
  
  
}

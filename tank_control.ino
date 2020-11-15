int backpin1 = 7;
int forwardpin1 = 6;
int backpin2 = 5;
int forwardpin2 = 4;
char incoming_value = " ";
int mspeed = 110;
int rspeed = 10;
int lspeed = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(backpin1,OUTPUT);
  pinMode(forwardpin1,OUTPUT);
  pinMode(backpin2,OUTPUT);
  pinMode(forwardpin2,OUTPUT);
  pinMode(rspeed,OUTPUT);
  pinMode(lspeed,OUTPUT);
  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incoming_value = Serial.read();
    Serial.print(incoming_value);
    Serial.print("\n");

    if(incoming_value == '1'){
     //right side forward
      analogWrite(rspeed,mspeed);
      digitalWrite(backpin1,HIGH);
      digitalWrite(forwardpin1,LOW);
      
    }
    if(incoming_value == '2'){
      //right side backward
      analogWrite(rspeed,mspeed);
      digitalWrite(backpin1,LOW);
      digitalWrite(forwardpin1,HIGH);
    }
    if(incoming_value == '3'){
      //left side forward
      analogWrite(lspeed,mspeed);
      digitalWrite(backpin2,HIGH);
      digitalWrite(forwardpin2,LOW);
    }
    if(incoming_value == '4'){
      //left side backward
      analogWrite(lspeed,mspeed);
      digitalWrite(backpin2,LOW);
      digitalWrite(forwardpin2,HIGH);
    }
    if(incoming_value == '5'){
      //right side stop
      analogWrite(rspeed,0);
      digitalWrite(backpin1,LOW);
      digitalWrite(forwardpin1,LOW);
    }
    if(incoming_value == '6'){
      //left side stop
      analogWrite(lspeed,0);
      digitalWrite(backpin2,LOW);
      digitalWrite(forwardpin2,LOW);
    }
  }
}


int x;
const int stepPin1 = 3;
const int dirPin1 = 4;
const int stepPin2 = 5;
const int dirPin2 = 6;
const int enableMotor1 = 7;
const int enableMotor2 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enableMotor1,OUTPUT); 
  pinMode(enableMotor1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());
  x = Serial.readString().toInt();
  if(x == 1) {
    Serial.print('U');
    digitalWrite(dirPin1,HIGH);
    digitalWrite(enableMotor1,LOW);
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500);    
  }
  if(x == 2) {
    Serial.print('D');
    digitalWrite(dirPin1,LOW);
    digitalWrite(enableMotor1,LOW);
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500);
  }
  if(x == 3) {
    Serial.print('R');
    digitalWrite(dirPin2,HIGH);
    digitalWrite(enableMotor2,LOW);
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500);
    
  }
  if(x == 4) {
    Serial.print('L');
    digitalWrite(dirPin2,LOW);
    digitalWrite(enableMotor2,LOW);
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500);
  }
  if(x == 0) {
    Serial.print('S');
    digitalWrite(enableMotor1,HIGH);
    digitalWrite(enableMotor2,HIGH);
  }
//  Serial.print(x + 1);
}

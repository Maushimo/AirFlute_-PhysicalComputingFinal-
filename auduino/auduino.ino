const int tempSensorPin = A0;
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int tempSensorVal = analogRead(tempSensorPin); 
  int ldr1Val = analogRead(ldrPin1);
  int ldr2Val = analogRead(ldrPin2);
  int ldr3Val = analogRead(ldrPin3);

  int all = ldr1Val+ldr2Val+ldr3Val;
  
  float tempVoltage = (tempSensorVal/1024.0) * 5.0;
  float temp = (tempVoltage - .5) * 100;
  
  Serial.println(all); //val
  delay(50);
}


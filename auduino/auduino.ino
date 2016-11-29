const int sensorPin = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  //Serial.print(" Sensor Value: ");
  //Serial.print(sensorVal);
  //Serial.print("\n");

  float voltage = (sensorVal/1024.0) * 5.0;
  //Serial.print(" Volts: ");
  //Serial.print(voltage);
  //Serial.print("\n");

  float temp = (voltage - .5) * 100;
  //Serial.print(" temp (C): ");
  Serial.println(temp); //val
  //Serial.print("\n");
  delay(50);
}


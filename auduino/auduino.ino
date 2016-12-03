/* Set analog pins */
const int tempSensorPin = A0;
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;

// Average temperature of the room... used in calibration
float tempAverage;

void setup(){
  Serial.begin(9600); //Set data rate for serial

  /* Calibrate BLOWEY */
  int tempSensorVal = analogRead(tempSensorPin); 
  float tempVoltage = (tempSensorVal/1024.0) * 5.0;
  float temp = (tempVoltage - .5) * 100;
  float tempValues[5]; //5 values for checking average should be fine... right?

  //for loop that equates all values in the array to temp values the sensor picks up
  for(int i = 0; i < 5; i++){
    tempValues[i] = temp;
    delay(10); //give it a bit of delay to give some time between measurements
  }

  //good ol' primary school maths
  tempAverage = (tempValues[0] + tempValues[1] + tempValues[2] + tempValues[3] + tempValues[4])/5;

}

void loop(){
  /* Temperature sensor (BLOWEY) stuff */
  int tempSensorVal = analogRead(tempSensorPin); 
  float tempVoltage = (tempSensorVal/1024.0) * 5.0;
  float temp = (tempVoltage - .5) * 100;
  temp = temp - tempAverage;

  /* LDR (HOLEY) stuff */
  int ldr1Val = analogRead(ldrPin1)*0.5;
  int ldr2Val = analogRead(ldrPin2)*1.5;
  int ldr3Val = analogRead(ldrPin3);

  int allLdr = (ldr1Val+ldr2Val+ldr3Val);

  Serial.print(temp);
  Serial.print(" ");
  Serial.print(allLdr);
  Serial.print(" ");
  Serial.print("\r");
  delay(50);
}


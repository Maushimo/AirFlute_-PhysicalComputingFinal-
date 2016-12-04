/* Set analog pins */
const int tempSensorPin = A0;
int tempSensorVal;
  
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;

/* Calibration Variables */
// variable to calibrate low value
int tempSensorLow = 1023;

// variable to calibrate high value
int tempSensorHigh = 0;

// Average temperature of the room... used in calibration
float tempAverage;

void setup(){
  Serial.begin(9600); //Set data rate for serial

  /* Calibrate BLOWEY */
  while (millis() < 5000) {
    // record the maximum sensor value
    tempSensorVal = analogRead(tempSensorPin);
    if (tempSensorVal > tempSensorHigh) {
      tempSensorHigh = tempSensorVal;
    }
    // record the minimum sensor value
    if (tempSensorVal < tempSensorLow) {
      tempSensorLow = tempSensorVal;
    }
  }

}

void loop(){
  /* Temperature sensor (BLOWEY) stuff */
  tempSensorVal = analogRead(tempSensorPin);
  int blow = map(tempSensorVal, tempSensorLow, tempSensorHigh, 0, 25);
  
  /* LDR (HOLEY) stuff */
  int ldr1Val = analogRead(ldrPin1)*0.5;
  int ldr2Val = analogRead(ldrPin2)*1.5;
  int ldr3Val = analogRead(ldrPin3);

  int allLdr = (ldr1Val+ldr2Val+ldr3Val);

  Serial.print(blow);
  Serial.print(" ");
  Serial.print(allLdr);
  Serial.print(" ");
  Serial.print("\r");
  delay(50);
}


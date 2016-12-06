/* ====Set analog pins==== */
const int tempSensorPin = A0;
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;

/* ====Calibration Variables==== */

/* Temp Sensor Values */
int tempSensorVal;
// variable to calibrate low value
int tempSensorLow = 1023;
// variable to calibrate high value
int tempSensorHigh = 0;

/* LDR Values */
int ldr1Val;
int ldr1Low = 1023;
int ldr1High = 0;

int ldr2Val;
int ldr2Low = 1023;
int ldr2High = 0;

int ldr3Val;
int ldr3Low = 1023;
int ldr3High = 0;

//Light PINs
const int greenLEDPin = 10;
const int blueLEDPin = 9;
const int redLEDPin = 11;

void setup() {
  Serial.begin(9600); //Set data rate for serial

  //LED pin setup
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  /* Calibrate BLOWEY */
  while (millis() < 5000) {

    /* TEMP SENSOR CALIBRATION */
    // record the maximum sensor value
    tempSensorVal = analogRead(tempSensorPin);
    if (tempSensorVal > tempSensorHigh) {
      tempSensorHigh = tempSensorVal;
    }
    // record the minimum sensor value
    if (tempSensorVal < tempSensorLow) {
      tempSensorLow = tempSensorVal;
    }

    /* LDR CALIBRATION */
    ldr1Val = analogRead(ldrPin1);
    if(ldr1Val > ldr1High){
      ldr1High = ldr1Val;
    }
    if(ldr1Val < ldr1Low){
      ldr1Low = ldr1Val;
    }

    ldr2Val = analogRead(ldrPin2);
    if(ldr2Val > ldr2High){
      ldr2High = ldr2Val;
    }
    if(ldr2Val < ldr2Low){
      ldr2Low = ldr2Val;
    }

    ldr3Val = analogRead(ldrPin3);
    if(ldr3Val > ldr3High){
      ldr3High = ldr3Val;
    }
    if(ldr3Val < ldr3Low){
      ldr3Low = ldr3Val;
    }
    
  }
}

void loop() {
  /* Temperature sensor (BLOWEY) stuff */
  tempSensorVal = analogRead(tempSensorPin);
  int blow = map(tempSensorVal, tempSensorLow, tempSensorHigh, 0, 50);

  /* LDR (HOLEY) stuff */
  int ldr1Val = analogRead(ldrPin1);
  int ldr2Val = analogRead(ldrPin2);
  int ldr3Val = analogRead(ldrPin3);

  int note1 = (map(ldr1Val, ldr1Low, ldr1High, 50, 100))*0.5;
  int note2 = (map(ldr2Val, ldr2Low, ldr2High, 50, 100));
  int note3 = (map(ldr3Val, ldr3Low, ldr3High, 50, 100))*1.5;

  //combined value used to pass in frequency data to max
  int allLdr = (note1 + note2 + note3);

  //LED brightness
  int blueBrightness = ldr1Val/8;
  int greenBrightness = ldr2Val/8;
  int redBrightness = ldr3Val/8;

  //LED values
  int blueLedVal = (ldr1Val/2)+redBrightness;
  int greenLedVal = (ldr2Val/2)+greenBrightness;
  int redLedVal = (ldr3Val/2)+blueBrightness;

  //Write values to LEDs
  analogWrite(redLEDPin, redLedVal);
  analogWrite(greenLEDPin, greenLedVal);
  analogWrite(blueLEDPin, blueLedVal);

  Serial.print(blow);
  Serial.print(" ");
  Serial.print(abs(allLdr));
  Serial.print(" ");
  Serial.print("\r");
  delay(50);
}


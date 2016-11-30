const int sensorPin = A0;
float baselineTemp = .0;

//Note values
int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");

  //Convert volt to temp
  float temp = (voltage - .5) * 100;
  Serial.print(temp);

  //Set notes to temperature margins
  if (temp < baselineTemp-2) {
    tone(8, notes[0]);
  }
  else if (temp >= baselineTemp + 1 && temp < baselineTemp + 3) {
    tone(8, notes[1]);
  }
  else if (temp >= baselineTemp + 3 && temp < baselineTemp + 5) {
    tone(8, notes[2]);
  }
  else if (temp >= baselineTemp + 5) {
    tone(8, notes[3]);
  }
  else {
    noTone(8);
  }
  delay(10);
}

#define TDS_PIN 34

float tdsValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(TDS_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);

  tdsValue = (133.42 * voltage * voltage * voltage 
              - 255.86 * voltage * voltage 
              + 857.39 * voltage) * 0.5;

  if (tdsValue < 0) tdsValue = 0;

  Serial.print("TDS Value: ");
  Serial.print(tdsValue, 2);
  Serial.println(" ppm");

  if (tdsValue < 300) {
    Serial.println("Taste: Not Salty");
  }
  else if (tdsValue >= 300 && tdsValue <= 600) {
    Serial.println("Taste: Slightly Salty");
  }
  else if (tdsValue > 600 && tdsValue <= 900) {
    Serial.println("Taste: Moderately Salty");
  }
  else {
    Serial.println("Taste: Very Salty");
  }

  Serial.println("------------------------");
  delay(2000);
}

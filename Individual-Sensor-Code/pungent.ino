#define PUNGENT_PIN 34

float pungentValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(PUNGENT_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);

  pungentValue = voltage * 10.0;

  if (pungentValue < 0) pungentValue = 0;
  if (pungentValue > 10) pungentValue = 10;

  Serial.print("Pungency Level: ");
  Serial.println(pungentValue, 2);

  if (pungentValue < 3.0) {
    Serial.println("Taste: Not Pungent");
  }
  else if (pungentValue >= 3.0 && pungentValue <= 5.5) {
    Serial.println("Taste: Slightly Pungent");
  }
  else if (pungentValue > 5.5 && pungentValue <= 8.0) {
    Serial.println("Taste: Moderately Pungent");
  }
  else {
    Serial.println("Taste: Very Pungent");
  }

  Serial.println("------------------------");
  delay(2000);
}

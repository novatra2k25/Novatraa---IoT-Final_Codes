#define ASTRINGENT_PIN 34

float astringentValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(ASTRINGENT_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);


  astringentValue = voltage * 10.0;

  if (astringentValue < 0) astringentValue = 0;
  if (astringentValue > 10) astringentValue = 10;

  Serial.print("Astringency Level: ");
  Serial.println(astringentValue, 2);

  if (astringentValue < 3.0) {
    Serial.println("Taste: Not Astringent");
  }
  else if (astringentValue >= 3.0 && astringentValue <= 5.5) {
    Serial.println("Taste: Slightly Astringent");
  }
  else if (astringentValue > 5.5 && astringentValue <= 8.0) {
    Serial.println("Taste: Moderately Astringent");
  }
  else {
    Serial.println("Taste: Very Astringent");
  }

  Serial.println("------------------------");
  delay(2000);
}

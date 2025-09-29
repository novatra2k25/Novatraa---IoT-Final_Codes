#define SWEET_PIN 34

float sweetValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(SWEET_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);

 
  sweetValue = voltage * 10.0;

  if (sweetValue < 0) sweetValue = 0;
  if (sweetValue > 10) sweetValue = 10;

  Serial.print("Sweetness Level: ");
  Serial.println(sweetValue, 2);

  if (sweetValue < 3.0) {
    Serial.println("Taste: Not Sweet");
  }
  else if (sweetValue >= 3.0 && sweetValue <= 5.5) {
    Serial.println("Taste: Slightly Sweet");
  }
  else if (sweetValue > 5.5 && sweetValue <= 8.0) {
    Serial.println("Taste: Moderately Sweet");
  }
  else {
    Serial.println("Taste: Very Sweet");
  }

  Serial.println("------------------------");
  delay(2000);
}

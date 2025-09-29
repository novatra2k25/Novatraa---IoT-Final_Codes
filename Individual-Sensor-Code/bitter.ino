#define BITTER_PIN 34

float bitternessValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(BITTER_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);

 
  bitternessValue = voltage * 10.0;

  if (bitternessValue < 0) bitternessValue = 0;
  if (bitternessValue > 10) bitternessValue = 10;

  Serial.print("Bitterness Level: ");
  Serial.println(bitternessValue, 2);

  if (bitternessValue < 3.0) {
    Serial.println("Taste: Not Bitter");
  }
  else if (bitternessValue >= 3.0 && bitternessValue <= 5.5) {
    Serial.println("Taste: Slightly Bitter");
  }
  else if (bitternessValue > 5.5 && bitternessValue <= 8.0) {
    Serial.println("Taste: Moderately Bitter");
  }
  else {
    Serial.println("Taste: Very Bitter");
  }

  Serial.println("------------------------");
  delay(2000);
}

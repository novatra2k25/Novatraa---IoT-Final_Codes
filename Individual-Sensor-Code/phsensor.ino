#define PH_PIN 34   // ADC pin for pH sensor

float phValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // 0–4095
}

void loop() {
  int sensorValue = analogRead(PH_PIN);
  phValue = map(sensorValue, 0, 4095, 0, 1400) / 100.0;

  if (phValue < 0) phValue = 0;
  if (phValue > 14) phValue = 14;

  Serial.print("pH Value: ");
  Serial.println(phValue, 2);

  if (phValue < 4.0) {
    Serial.println("Taste: Very Sour");
  } 
  else if (phValue >= 4.0 && phValue <= 5.5) {
    Serial.println("Taste: Moderately Sour");
  } 
  else if (phValue > 5.5 && phValue <= 7.0) {
    Serial.println("Taste: Slightly Sour / Neutral");
  } 
  else {
    Serial.println("Taste: Not Sour (Alkaline)");
  }

  Serial.println("------------------------");
  delay(2000);
}

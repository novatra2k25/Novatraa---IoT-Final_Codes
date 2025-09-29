
#define PH_PIN        32  // Sour
#define TDS_PIN       33  // Salty
#define BITTER_PIN    34  // Bitter
#define SWEET_PIN     35  // Sweet
#define PUNGENT_PIN   25  // Pungent
#define ASTRINGENT_PIN 26 // Astringent


float phValue, tdsValue, bitterValue, sweetValue, pungentValue, astringentValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); 
}

void loop() {
  // -------- Sour (pH) --------
  int phRaw = analogRead(PH_PIN);
  phValue = map(phRaw, 0, 4095, 0, 1400) / 100.0;
  if(phValue < 0) phValue = 0;
  if(phValue > 14) phValue = 14;
  Serial.print("Sour (pH): ");
  Serial.println(phValue, 2);
  if (phValue < 4.0) Serial.println("Taste: Very Sour");
  else if (phValue >= 4.0 && phValue <= 5.5) Serial.println("Taste: Moderately Sour");
  else if (phValue > 5.5 && phValue <= 7.0) Serial.println("Taste: Slightly Sour / Neutral");
  else Serial.println("Taste: Not Sour (Alkaline)");

  // -------- Salty (TDS) --------
  int tdsRaw = analogRead(TDS_PIN);
  float tdsVoltage = tdsRaw * (3.3 / 4095.0);
  tdsValue = (133.42 * tdsVoltage * tdsVoltage * tdsVoltage 
             - 255.86 * tdsVoltage * tdsVoltage 
             + 857.39 * tdsVoltage) * 0.5;
  if(tdsValue < 0) tdsValue = 0;
  Serial.print("Salty (TDS): ");
  Serial.print(tdsValue, 2);
  Serial.println(" ppm");
  if(tdsValue < 300) Serial.println("Taste: Not Salty");
  else if(tdsValue >= 300 && tdsValue <= 600) Serial.println("Taste: Slightly Salty");
  else if(tdsValue > 600 && tdsValue <= 900) Serial.println("Taste: Moderately Salty");
  else Serial.println("Taste: Very Salty");

  // -------- Bitter --------
  int bitterRaw = analogRead(BITTER_PIN);
  float bitterVoltage = bitterRaw * (3.3 / 4095.0);
  bitterValue = bitterVoltage * 10.0;
  if(bitterValue < 0) bitterValue = 0;
  if(bitterValue > 10) bitterValue = 10;
  Serial.print("Bitter: ");
  Serial.println(bitterValue, 2);
  if(bitterValue < 3.0) Serial.println("Taste: Not Bitter");
  else if(bitterValue >= 3.0 && bitterValue <= 5.5) Serial.println("Taste: Slightly Bitter");
  else if(bitterValue > 5.5 && bitterValue <= 8.0) Serial.println("Taste: Moderately Bitter");
  else Serial.println("Taste: Very Bitter");

  // -------- Sweet --------
  int sweetRaw = analogRead(SWEET_PIN);
  float sweetVoltage = sweetRaw * (3.3 / 4095.0);
  sweetValue = sweetVoltage * 10.0;
  if(sweetValue < 0) sweetValue = 0;
  if(sweetValue > 10) sweetValue = 10;
  Serial.print("Sweet: ");
  Serial.println(sweetValue, 2);
  if(sweetValue < 3.0) Serial.println("Taste: Not Sweet");
  else if(sweetValue >= 3.0 && sweetValue <= 5.5) Serial.println("Taste: Slightly Sweet");
  else if(sweetValue > 5.5 && sweetValue <= 8.0) Serial.println("Taste: Moderately Sweet");
  else Serial.println("Taste: Very Sweet");

  // -------- Pungent --------
  int pungentRaw = analogRead(PUNGENT_PIN);
  float pungentVoltage = pungentRaw * (3.3 / 4095.0);
  pungentValue = pungentVoltage * 10.0;
  if(pungentValue < 0) pungentValue = 0;
  if(pungentValue > 10) pungentValue = 10;
  Serial.print("Pungent: ");
  Serial.println(pungentValue, 2);
  if(pungentValue < 3.0) Serial.println("Taste: Not Pungent");
  else if(pungentValue >= 3.0 && pungentValue <= 5.5) Serial.println("Taste: Slightly Pungent");
  else if(pungentValue > 5.5 && pungentValue <= 8.0) Serial.println("Taste: Moderately Pungent");
  else Serial.println("Taste: Very Pungent");

  // -------- Astringent --------
  int astringentRaw = analogRead(ASTRINGENT_PIN);
  float astringentVoltage = astringentRaw * (3.3 / 4095.0);
  astringentValue = astringentVoltage * 10.0;
  if(astringentValue < 0) astringentValue = 0;
  if(astringentValue > 10) astringentValue = 10;
  Serial.print("Astringent: ");
  Serial.println(astringentValue, 2);
  if(astringentValue < 3.0) Serial.println("Taste: Not Astringent");
  else if(astringentValue >= 3.0 && astringentValue <= 5.5) Serial.println("Taste: Slightly Astringent");
  else if(astringentValue > 5.5 && astringentValue <= 8.0) Serial.println("Taste: Moderately Astringent");
  else Serial.println("Taste: Very Astringent");

  Serial.println("===============================");
  delay(2000);
}

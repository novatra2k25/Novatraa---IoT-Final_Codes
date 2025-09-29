The Novatraa E-Tongue IoT Device is a sensor-based system that creates a Taste Fingerprint of herbal samples. Data is transmitted to the cloud for ML-based classification and report generation.

Hardware & Sensors

Microcontroller: ESP32/Arduino

Sensors:

pH sensor → Sourness
TDS sensor → Saltiness
MQ136 sensor → Pungency
Modified Carbon Electrodes → Bitter, Sweet, Astringent

Setup Instructions
Connect sensors to ESP32 pins (see /docs/circuit-diagram.png).
Update WiFi credentials in firmware.ino.
Flash firmware using Arduino IDE.
Device automatically sends sensor data to backend API.

Sample Data (Neem Extract Example)
Sensor	Value
pH	6.2
TDS (ppm)	480
MQ136 (ppm)	0.42
Bitter Electrode(V)	0.87
Sweet Electrode(V)	0.12

Taste Fingerprint → {6.2, 480, 0.42, 0.87, 0.12}

Predicted Output → Pure Neem

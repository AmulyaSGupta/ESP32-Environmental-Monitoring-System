#include <DHT.h>

#define DHTPIN 4        // DHT22 DATA -> ESP 4
#define DHTTYPE DHT22

#define LDR_PIN 34      // Analog pin for LDR (AO -> GPIO34)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  // Read Temperature & Humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read LDR value
  int lightValue = analogRead(LDR_PIN);

  // Check if DHT failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  //  Print Light Data
  Serial.print("LDR Value: ");
  Serial.print(lightValue);

  if (lightValue < 1000) {
    Serial.println(" → DARK");
  } else {
    Serial.println(" → BRIGHT");
  }

  Serial.println("------------------------");

  delay(2000);
}

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define RELAY_PIN 3

DHT dht(DHTPIN, DHTTYPE);

String keputusanAC(float suhu);
String keputusanHumidifier(float kelembapan);
bool isIdealCondition(float suhu, float kelembapan);

void setup() {
  Serial.begin(9600);
  Serial.println("Smart AC-Humidifier System Starting...");

  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  String statusAC = keputusanAC(t);
  String statusHumidifier = keputusanHumidifier(h);
  bool ideal = isIdealCondition(t, h);

  if (statusHumidifier == "ON") {
    digitalWrite(RELAY_PIN, LOW);
  } else {
    digitalWrite(RELAY_PIN, HIGH);
  }

  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.print("C | ");
  Serial.print("Kelembapan: ");
  Serial.print(h);
  Serial.println("%");

  Serial.print("Status AC: ");
  Serial.println(statusAC);
  Serial.print("Status Humidifier: ");
  Serial.println(statusHumidifier);

  if (ideal) {
    Serial.println(">>> SMART POWER MODE: ACTIVE <<<");
  }

  Serial.println("-----------------------------------");
}

String keputusanAC(float suhu) {
  if (suhu > 28.0)
    return "ON";
  else if (suhu <= 24.0)
    return "OFF";
  else
    return "STANDBY";
}

String keputusanHumidifier(float kelembapan) {
  if (kelembapan < 40.0)
    return "ON";
  else if (kelembapan >= 50.0)
    return "OFF";
  else
    return "STANDBY";
}

bool isIdealCondition(float suhu, float kelembapan) {
  return (suhu > 24.0 && suhu <= 28.0) &&
         (kelembapan >= 40.0 && kelembapan < 50.0);
}

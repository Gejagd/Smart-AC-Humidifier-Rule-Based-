#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <LCD-I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define RELAY_PIN 3

DHT dht(DHTPIN, DHTTYPE);
LCD_I2C lcd(0x27, 20, 4);

String keputusanAC(float suhu);
String keputusanHumidifier(float kelembapan);
bool isIdealCondition(float suhu, float kelembapan);

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  lcd.begin(&Wire);
  lcd.display();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("   SMART CLIMATE    ");
  lcd.setCursor(0, 1);
  lcd.print("   CONTROL SYSTEM   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("SENSOR ERROR!       ");
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

  lcd.setCursor(0, 0);
  lcd.print("Suhu: "); lcd.print(t); lcd.print("C     ");
  lcd.setCursor(0, 1);
  lcd.print("Hmd : "); lcd.print(h); lcd.print("%     ");
  
  lcd.setCursor(0, 2);
  lcd.print("AC  : "); lcd.print(statusAC); lcd.print("       ");
  lcd.setCursor(0, 3);
  if (ideal) {
    lcd.print("MODE: SMART POWER   ");
  } else {
    lcd.print("HUM : "); lcd.print(statusHumidifier); lcd.print("       ");
  }
}

String keputusanAC(float suhu) {
  if (suhu > 28.0) return "ON";
  else if (suhu <= 24.0) return "OFF";
  else return "STANDBY";
}

String keputusanHumidifier(float kelembapan) {
  if (kelembapan < 40.0) return "ON";
  else if (kelembapan >= 50.0) return "OFF";
  else return "STANDBY";
}

bool isIdealCondition(float suhu, float kelembapan) {
  return (suhu > 24.0 && suhu <= 28.0) &&
         (kelembapan >= 40.0 && kelembapan < 50.0);
}

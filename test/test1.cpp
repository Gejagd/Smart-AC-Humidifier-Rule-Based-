#include <iostream>
using namespace std;

int main() {
  float suhu, kelembapan;
  string statusAC, statusHumidifier;

  cout << "Masukkan suhu ruangan (°C): ";
  cin >> suhu;

  cout << "Masukkan kelembapan udara (%): ";
  cin >> kelembapan;

  // Keputusan AC
  if (suhu > 28.0) {
    statusAC = "ON";
  } else if (suhu <= 25.0) {
    statusAC = "OFF";
  } else {
    statusAC = "STANDBY";
  }

  // Keputusan Humidifier
  if (kelembapan < 40.0) {
    statusHumidifier = "ON";
  } else if (kelembapan >= 50.0) {
    statusHumidifier = "OFF";
  } else {
    statusHumidifier = "STANDBY";
  }

  cout << "\n=== Keputusan Sistem ===" << endl;
  cout << "Status AC         : " << statusAC << endl;
  cout << "Status Humidifier : " << statusHumidifier << endl;

  return 0;
}

/*
Ini dibuat memakai AI sebagai acuan awal, dimana ini
hanya kasaran ide-nya saja.
*/
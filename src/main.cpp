#include "../include/smartdecision.h"
#include <iostream>

int main() {
  float suhu, kelembapan;

  std::cout << "Suhu Ruang(°C): " << std::endl;
  std::cin >> suhu;
  std::cout << "Kelembapan Udara(%): " << std::endl;
  std::cin >> kelembapan;

  std::string statusAC = keputusanAC(suhu);
  std::cout << "AC Status: " << statusAC << std::endl;
  std::string statusHumidifier = keputusanHumidifier(kelembapan);
  std::cout << "Humidifier Status: " << statusHumidifier << std::endl;

  if (isIdealCondition(suhu, kelembapan)) {
    std::cout << "Smart Power Mode: Active (Energy Saving)" << std::endl;
  }

  return 0;
}

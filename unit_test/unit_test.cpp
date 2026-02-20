#include "../include/smartdecision.h"
#include <cassert>
#include <iostream>


int main() {
  assert(keputusanAC(29.0) == "ON");
  assert(keputusanAC(28.0) == "STANBY");
  assert(keputusanAC(25.0) == "STANBY");
  assert(keputusanAC(24.0) == "OFF");

  assert(keputusanHumidifier(30.0) == "ON");
  assert(keputusanHumidifier(45.0) == "STANBY");
  assert(keputusanHumidifier(50.0) == "OFF");
  assert(keputusanHumidifier(60.0) == "OFF");

  std::cout << "Semua test lulus!\n";

  return 0;
}
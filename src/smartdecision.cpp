#include "../include/smartdecision.h"
#include <iostream>
#include <string>

std::string keputusanAC(float suhu) {
  if (suhu > 28.0) {
    return "ON";
  } else if (suhu <= 24.0) {
    return "OFF";
  } else {
    return "STANBY";
  }
}

bool isIdealCondition(float suhu, float kelembapan) {
  // Kondisi ideal: Suhu 24-28 dan Kelembapan 40-50
  return (suhu > 24.0 && suhu <= 28.0) &&
         (kelembapan >= 40.0 && kelembapan < 50.0);
}

std::string keputusanHumidifier(float kelembapan) {
  if (kelembapan < 40.0) {
    return "ON";
  } else if (kelembapan >= 50.0) {
    return "OFF";
  } else {
    return "STANBY";
  }
}
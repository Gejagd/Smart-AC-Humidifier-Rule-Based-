#ifndef SMARTDECISION_H
#define SMARTDECISION_H

#include <string>

std::string keputusanAC(float suhu);
std::string keputusanHumidifier(float kelembapan);
bool isIdealCondition(float suhu, float kelembapan);

#endif
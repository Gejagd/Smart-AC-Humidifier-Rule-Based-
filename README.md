<div align="center">

# 🌡️ Smart AC-Humidifier 💧

**A Rule-Based Intelligent Decision System for Climate Control**

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Active-success.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-gray.svg)](#)

---

### "Smart climate choices for a smarter room."

[📖 Baca Tutorial Perakitan Hardware](./TUTORIAL.md)

</div>

## 🚀 Overview
**Smart AC-Humidifier** adalah sistem pengambilan keputusan cerdas berbasis aturan (*rule-based*) yang dirancang untuk mengatur kondisi udara dalam ruangan secara otomatis.

---

## 🤖 Hardware Ready (Real Practice)
Sistem ini kini mendukung implementasi hardware nyata menggunakan Arduino/ESP32 dengan tampilan informasi melalui LCD.

### 🛒 Shopping List
- **Arduino Uno R3** (Otak utama)
- **Sensor DHT22** (Akurasi tinggi untuk suhu & kelembapan)
- **LCD 20x4 with I2C Adapter** (Display status)
- **Relay Module** (Kontrol power Humidifier)
- **Kabel Jumper & Breadboard**

### 📂 Hardware Files
- [`hardware/Smart-AC_Humidifier_Arduino/`](./hardware/Smart-AC_Humidifier_Arduino/)
- **`..._LCD.ino`**: Versi premium dengan dukungan LCD 20x4.
- **`... .ino`**: Versi standar tanpa LCD.

---

## ✨ Features
- **Rule-Based Logic**: Pengambilan keputusan cepat & akurat.
- **🛡️ Smart Power Mode**: Mode hemat energi otomatis (Suhu: 24-28°C, Hmd: 40-50%).
- **📺 LCD 20x4 Support**: Monitoring real-time status suhu, kelembapan, dan mode perangkat.
- **Modular Design**: Pemisahan logika (*core*) dan antarmuka (*interface*).

---

## 📊 Decision Logic

### ❄️ AC Rules
| Kondisi Suhu (°C) | Status AC |
| :--- | :--- |
| > 28.0 | **ON** |
| <= 24.0 | **OFF** |
| 24.1 - 28.0 | **STANDBY** |

### 💧 Humidifier Rules
| Kondisi Kelembapan (%) | Status Humidifier |
| :--- | :--- |
| < 40.0 | **ON** |
| >= 50.0 | **OFF** |
| 40.0 - 49.9 | **STANDBY** |

---

## 🛠️ Installation & Usage

### 1. Desktop (C++)
```bash
g++ src/main.cpp src/smartdecision.cpp -Iinclude -o app
./app
```

### 2. Hardware (Arduino IDE)
- Instal library: `DHT sensor library` (Adafruit) & `LiquidCrystal I2C`.
- Buka file `.ino` di folder `hardware/`.
- Hubungkan I2C LCD ke Pin A4 (SDA) & A5 (SCL).

---

<div align="center">

*Developed with ❤️ for learning C++ & Robotics*

</div>
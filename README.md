<div align="center">

# 🌡️ Smart AC-Humidifier 💧

**A Rule-Based Intelligent Decision System for Climate Control**

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Active-success.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-gray.svg)](#)

---

### "Smart climate choices for a smarter room."

</div>

## 🚀 Overview
**Smart AC-Humidifier** adalah sistem pengambilan keputusan cerdas berbasis aturan (*rule-based*) yang dirancang untuk mengatur kondisi udara dalam ruangan secara optimal. Program ini menganalisis suhu dan kelembapan untuk menentukan status operasional AC dan Humidifier secara otomatis.

---

## ✨ Features
- **Rule-Based Logic**: Pengambilan keputusan cepat berbasis parameter lingkungan.
- **🛡️ Smart Power Mode**: Fitur hemat energi yang mendeteksi kondisi ideal untuk menonaktifkan perangkat secara otomatis.
- **Modular Design**: Struktur kode yang terbagi antara Header, Source, dan Unit Testing.
- **Unit Tested**: Menjamin keakuratan logika melalui pengujian terstandarisasi.

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

> [!IMPORTANT]
> **Smart Power Mode** akan aktif secara otomatis jika:
> - Suhu berada di rentang **24.1 - 28.0°C**
> - Kelembapan berada di rentang **40.0 - 49.9%**

---

## 📂 Project Structure
```bash
.
├── include/      # Header file (*.h)
├── src/          # Source code (*.cpp)
├── test/         # Trial-test code file
├── unit_test/    # Unit test files
└── README.md     # Documentation
```

---

## 🛠️ Installation & Usage

### 1. Prasyarat
Pastikan Anda memiliki compiler C++ (seperti `g++`) yang sudah terinstall.

### 2. Compile Main Program
```bash
g++ src/main.cpp src/smartdecision.cpp -Iinclude -o app
```

### 3. Jalankan Program
```bash
./app
```

### 4. Run Unit Tests
```bash
g++ unit_test/unit_test.cpp src/smartdecision.cpp -Iinclude -o testapp
./testapp
```

---

<div align="center">

*Developed with ❤️ for learning C++*

</div>
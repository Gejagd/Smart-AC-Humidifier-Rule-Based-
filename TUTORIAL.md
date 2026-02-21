# 📖 Hardware Assembly Tutorial

Panduan langkah-demi-langkah untuk merakit sistem **Smart AC-Humidifier** menggunakan Arduino, Sensor DHT22, dan LCD 20x4.

## 🛒 Daftar Komponen

| Komponen | Kegunaan | Jumlah |
| :--- | :--- | :--- |
| **Arduino Uno R3** | Otak utama sistem. | 1 |
| **Sensor DHT22** (Warna Putih) | Sensor suhu & kelembapan. | 1 |
| **LCD 20x4 I2C Adapter** | Menampilkan status sistem. | 1 |
| **Relay Module 1-Channel** | Saklar otomatis Humidifier. | 1 |
| **Breadboard 400 pts** | Media pasang kabel tanpa solder. | 1 |
| **Kabel Jumper (Male-Female)** | Untuk menghubungkan komponen. | 1 Set |

---

## 🔌 Skema Penyambungan (Wiring)

Pastikan Arduino **tidak terhubung ke listrik** saat menyambungkan kabel.

### 1. LCD 20x4 (I2C)
| Pin LCD | Pin Arduino |
| :--- | :--- |
| **GND** | GND |
| **VCC** | 5V |
| **SDA** | Pin A4 |
| **SCL** | Pin A5 |

### 2. Sensor DHT22
| Pin DHT22 | Pin Arduino |
| :--- | :--- |
| **VCC/Positive (+)** | 5V |
| **GND/Negative (-)** | GND |
| **Out/Data/SDA** | Digital Pin 2 |

### 3. Relay Module
| Pin Relay | Pin Arduino |
| :--- | :--- |
| **VCC/DC+** | 5V |
| **GND/DC-** | GND |
| **IN/Signal** | Digital Pin 3 |

---

## 🛠️ Langkah-Langkah Perakitan

1. **Pasang Komponen**: Letakkan sensor DHT22 dan Arduino di area kerja yang bersih.
2. **Setup Wiring**: Ikuti tabel skema di atas dengan teliti. Pastikan tidak ada kabel yang kendor.
3. **Instalasi Library**: Di Arduino IDE, instal dua library ini (Pilih buatan **Adafruit**):
   - `DHT sensor library`
   - `LCD-I2C` (oleh S. Bondar)
4. **Upload Code**: Buka file `hardware/Smart-AC_Humidifier_Arduino/Smart-AC_Humidifier_Arduino_LCD.ino` dan tekan tombol **Upload** (Tanda panah kanan).
5. **Adjust Kontras**: Jika layar LCD sudah nyala tapi tulisan tidak terlihat, gunakan obeng kecil untuk memutar **potensiometer (kotak biru)** di bagian belakang modul I2C LCD sampai tulisan muncul jelas.

---

## 🆘 Troubleshooting Umum

- **"SENSOR ERROR!" di LCD**: Periksa apakah kabel data DHT22 sudah benar di Pin 2.
- **Layar Berkedip (Flicker)**: Pastikan kabel SDA & SCL tidak tertukar dan power menggunakan 5V (bukan 3.3V).
- **Relay Tidak "Klik"**: Pastikan kabel IN Relay sudah di Pin 3. Periksa apakah jenis relay kamu "Active Low" atau "Active High".

---

<div align="center">

**Selamat! Kamu telah berhasil merakit asisten iklim cerdasmu sendiri!** 🎉

</div>

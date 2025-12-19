# 🍴 Aplikasi Manajemen Kalori Harian (C++)

Aplikasi berbasis Command Line Interface (CLI) yang membantu pengguna mengelola kesehatan dengan menghitung Basal Metabolic Rate (BMR) dan memantau asupan kalori harian sesuai dengan target kesehatan (menurunkan, menstabilkan, atau meningkatkan berat badan).

## ✨ Fitur Utama
- **Input Data Fisik:** Berat badan, tinggi, usia, gender, dan tingkat aktivitas.
- **Perhitungan BMR:** Menggunakan rumus Mifflin-St Jeor yang akurat.
- **Evaluasi Kalori:** Membandingkan asupan real-time dengan target harian (dengan batas toleransi ±10%).
- **Saran Kesehatan:** Memberikan peringatan otomatis jika kalori terlalu rendah atau berlebih.

## 🛠️ Teknologi yang Digunakan
- **Bahasa:** C++
- **Konsep:** Modular Programming (Functions), Data Validation, Vector (untuk menyimpan riwayat input kalori).

## 🚀 Cara Menjalankan
1. Clone repositori ini.
2. Compile file `main.cpp` menggunakan compiler C++ (g++):
   ```bash
   g++ -o manajemen-kalori main.cpp

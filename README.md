# 📘 Student Attendance Management

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Compiler](https://img.shields.io/badge/Compiler-GCC%20%2F%20G%2B%2B-green)
![Project](https://img.shields.io/badge/Project-UAS%20Dasar%20Pemrograman-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## 📌 Deskripsi Proyek
**Student Attendance Management** adalah program berbasis bahasa **C++** yang dirancang untuk mengelola data mahasiswa dan kehadiran secara efisien dengan memanfaatkan fitur *file handling*. 

Program ini dikembangkan sebagai tugas **Ujian Akhir Semester (UAS)** mata kuliah Dasar Pemrograman. Aplikasi dijalankan melalui antarmuka *console/terminal* dan menyediakan dua jenis hak akses utama:

* **Admin:** Berwenang mengelola database mahasiswa dan memantau laporan kehadiran.
* **Mahasiswa:** Berwenang melakukan login mandiri dan mencatat kehadiran pribadi.

---

## 🎯 Tujuan Program
Pengembangan aplikasi ini bertujuan untuk:
- **Menerapkan konsep dasar** pemrograman C++.
- **Melatih logika** penggunaan variabel, percabangan, perulangan, array, dan fungsi.
- **Mengimplementasikan file handling** sebagai media penyimpanan data (database sederhana).
- **Membangun sistem interaktif** berbasis teks (*console application*).

---

## ✨ Fitur Utama

### 👩‍💼 Panel Admin
- Login autentikasi admin secara aman.
- Pendaftaran data mahasiswa baru ke dalam sistem.
- Penghapusan data mahasiswa secara spesifik atau reset seluruh database.
- Visualisasi daftar mahasiswa yang telah terdaftar dalam sistem.
- Pemantauan akumulasi kehadiran setiap mahasiswa.

### 👨‍🎓 Panel Mahasiswa
- Login menggunakan *username* dan *password* unik.
- Pencatatan absensi harian secara mandiri melalui terminal.
- Pengecekan riwayat total kehadiran pribadi secara *real-time*.

---

## 🛠️ Prasyarat Sistem
Aplikasi ini dapat dikembangkan dan dijalankan pada lingkungan berikut:

| Komponen | Keterangan |
| :--- | :--- |
| **Sistem Operasi** | Windows / Linux / MacOS |
| **Compiler** | GCC / G++ |
| **Standar Bahasa** | C++ (C++11 atau lebih baru) |
| **Editor** | VS Code / CodeBlocks / Dev-C++ |

---

## 🧩 Struktur Kode & Logika Program

Berikut adalah rincian fungsi utama yang membangun logika aplikasi ini:

| Fungsi/Komponen | Penjelasan |
| :--- | :--- |
| `main()` | Titik masuk utama dan pengatur navigasi menu. |
| `adminLogin()` | Menangani validasi keamanan untuk akses administratif. |
| `studentLogin()` | Menangani autentikasi identitas mahasiswa. |
| `adminView()` | Kumpulan logika dan antarmuka khusus untuk fitur admin. |
| `studentView()` | Kumpulan logika dan antarmuka khusus untuk fitur mahasiswa. |
| `registerStudent()` | Proses input dan penyimpanan data mahasiswa baru ke file eksternal. |
| `markMyAttendance()` | Proses pencatatan kehadiran yang langsung memperbarui data file. |
| `countMyAttendance()` | Algoritma untuk menghitung total kehadiran mahasiswa dari database. |
| **File `.dat`** | Media penyimpanan persisten untuk data mahasiswa & log kehadiran. |

---

## 📚 Materi Dasar Pemrograman yang Diterapkan

| Konsep Materi | Implementasi dalam Kode |
| :--- | :--- |
| **Variabel & Tipe Data** | Menyimpan nama, NIM, dan password mahasiswa. |
| **Percabangan** | Penentuan hak akses (Admin vs Mahasiswa). |
| **Perulangan** | Menampilkan daftar mahasiswa dari file secara berurutan. |
| **Fungsi** | Pembagian logika program menjadi sub-program mandiri. |
| **Array (Vector)** | Penyimpanan data mahasiswa sementara di memori. |
| **File Handling** | Operasi *Read/Write* pada database `.dat` atau `.txt`. |

---
## ⚙️ Cara Instalasi & Menjalankan Program

### 1️⃣ Clone atau Download Repository
```bash
git clone https://github.com/username/student-attendance-management.git
cd student-attendance-management
g++ attendance.cpp -o attendance
./attendance
attendance.exe 
```
---

## 🎥 Video Demo

📌 **Tonton demonstrasi penggunaan program melalui tautan di bawah ini:**

[![Video Demo](https://img.shields.io/badge/YouTube-Watch%20Demo-red?style=for-the-badge&logo=youtube)](https://youtu.be/2MF8k9rHpSY?si=X6Q5rbgAEquTDjDm)

---

## 👤 Identitas Mahasiswa

| Informasi | Detail |
| :--- | :--- |
| **Nama** | Annisa Fathia Rahmah |
| **NIM** | 1257050083 |
| **Kelas** | IF 1 A |
| **Mata Kuliah** | Dasar Pemrograman |
| **Bahasa Pemrograman** | C++ |

---

> ✨ **Terima kasih telah membaca README ini.**
> ✨ *Semoga proyek ini memberikan gambaran jelas mengenai implementasi fundamental C++.*

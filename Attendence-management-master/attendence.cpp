#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cstdio>  
#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else
  #define CLEAR_CMD "clear"
#endif

using namespace std;

/* ----- Prototypes ----- */
int adminView();
int studentView();
int studentLogin();
int checkStudentCredentials(const string& username, const string& password);
int getAllStudentsbyName();
int getAllStudentsbyRollNo();
int deleteAllStudents();
int deleteStudentbyRollno();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int markMyAttendance(const string& username);
int countMyAttendance(const string& username);
void pauseForUser();
void smallDelay();
string todayString();
vector<string> readDbLines();
void writeDbLines(const vector<string>& lines);

/* ----- Helpers ----- */

void clearScreen() {
    system(CLEAR_CMD);
}

void pauseForUser() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void smallDelay() {
    cout << "\nMenyimpan data...";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    cout << " selesai.\n";
}

string todayString() {
    time_t t = time(nullptr);
    tm localTm;
#ifdef _WIN32
    localtime_s(&localTm, &t);
#else
    localtime_r(&t, &localTm);
#endif
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", &localTm);
    return string(buf);
}

vector<string> readDbLines() {
    vector<string> lines;
    ifstream read("db.dat");
    if (!read) return lines;
    string line;
    while (getline(read, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    read.close();
    return lines;
}

void writeDbLines(const vector<string>& lines) {
    ofstream out("db.dat", ios::trunc);
    for (const auto& l : lines) {
        out << l << "\n";
    }
    out.close();
}

/* ----- Implementations ----- */

int adminView()
{
    int goBack = 0;
    while (1)
    {
        clearScreen();
        cout << "\n === Menu Admin ===\n";
        cout << "\n 1. Daftarkan Mahasiswa";
        cout << "\n 2. Hapus Semua Mahasiswa";
        cout << "\n 3. Hapus Mahasiswa berdasarkan Username";
        cout << "\n 4. Lihat Daftar Mahasiswa (Username)";
        cout << "\n 5. Lihat Jumlah Kehadiran Mahasiswa (Username)";
        cout << "\n 6. Daftar Mahasiswa beserta Jumlah Kehadiran";
        cout << "\n 0. Kembali\n";
        int choice;

        cout << "\nMasukkan pilihan: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInput tidak valid.\n";
            pauseForUser();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1: registerStudent(); break;
        case 2: deleteAllStudents(); break;
        case 3: deleteStudentbyRollno(); break;
        case 4: checkListOfStudentsRegistered(); break;
        case 5: checkPresenseCountbyRollno(); break;
        case 6: getListOfStudentsWithTheirPresenseCount(); break;
        case 0: goBack = 1; break;
        default: cout << "\nPilihan tidak valid."; pauseForUser();
        }

        if (goBack == 1) break;
    }

    return 0;
}

int studentLogin()
{
    clearScreen();
    cout << "\n ----- Login Mahasiswa -----\n";
    studentView();
    smallDelay();
    return 0;
}

int adminLogin()
{
    clearScreen();
    cout << "\n ----- Login Admin -----\n";

    string username;
    string password;

    cout << "\nMasukkan username : ";
    getline(cin, username);
    cout << "Masukkan password : ";
    getline(cin, password);

    if (username == "admin" && password == "admin@1")
    {
        adminView();
        smallDelay();
    }
    else
    {
        cout << "\nError! Username atau password salah.";
        pauseForUser();
    }

    return 0;
}

int checkStudentCredentials(const string& username, const string& password)
{
    vector<string> db = readDbLines();
    string filename = username + ".dat";

    if (find(db.begin(), db.end(), filename) == db.end()) {
        return 0;
    }

    ifstream read(filename.c_str());
    if (!read) return 0;

    string name, user, pass, rollno, address, father, mother;
    getline(read, name);
    getline(read, user);
    getline(read, pass);
    getline(read, rollno);
    getline(read, address);
    getline(read, father);
    getline(read, mother);
    read.close();

    if (pass == password) return 1;
    return 0;
}

int getAllStudentsbyName()
{
    clearScreen();
    cout << "\nDaftar Mahasiswa (berdasarkan Nama):\n\n";

    vector<string> db = readDbLines();
    if (db.empty()) {
        cout << "Belum ada mahasiswa terdaftar.\n";
        pauseForUser();
        return 0;
    }

    for (const auto& f : db) {
        ifstream in(f.c_str());
        if (in) {
            string realName;
            getline(in, realName);
            cout << realName << "\n";
            in.close();
        }
    }

    pauseForUser();
    return 0;
}

int getAllStudentsbyRollNo()
{
    clearScreen();
    cout << "\nDaftar Mahasiswa (berdasarkan NIM):\n\n";

    vector<string> db = readDbLines();
    if (db.empty()) {
        cout << "Belum ada mahasiswa terdaftar.\n";
        pauseForUser();
        return 0;
    }

    for (const auto& f : db) {
        ifstream in(f.c_str());
        if (in) {
            string name, username, pass, rollno;
            getline(in, name);
            getline(in, username);
            getline(in, pass);
            getline(in, rollno);
            cout << "NIM: " << rollno << " | Nama: " << name << " | Username: " << username << "\n";
            in.close();
        }
    }

    pauseForUser();
    return 0;
}

int deleteStudentbyRollno()
{
    clearScreen();
    cout << "\nHapus Mahasiswa berdasarkan Username\n";
    cout << "Masukkan username: ";
    string username;
    getline(cin, username);

    if (username.empty()) {
        cout << "Username tidak boleh kosong.\n";
        pauseForUser();
        return 0;
    }

    string filename = username + ".dat";
    string attendanceFile = username + "_att.dat";

    vector<string> db = readDbLines();
    auto it = find(db.begin(), db.end(), filename);
    if (it == db.end()) {
        cout << "Mahasiswa tidak ditemukan.\n";
        pauseForUser();
        return 0;
    }

    db.erase(it);
    writeDbLines(db);

    remove(filename.c_str());
    remove(attendanceFile.c_str());

    smallDelay();
    cout << "Mahasiswa berhasil dihapus.\n";
    pauseForUser();
    return 0;
}

int checkPresenseCountbyRollno()
{
    clearScreen();
    cout << "\nCek Jumlah Kehadiran Mahasiswa\n";
    cout << "Masukkan username: ";
    string username;
    getline(cin, username);

    if (username.empty()) {
        cout << "Username tidak boleh kosong.\n";
        pauseForUser();
        return 0;
    }

    string file = username + "_att.dat";
    ifstream in(file.c_str());
    if (!in) {
        cout << "Belum ada data kehadiran.\n";
        pauseForUser();
        return 0;
    }

    int count = 0;
    string line;
    while (getline(in, line)) {
        if (!line.empty()) count++;
    }
    cout << "Total kehadiran: " << count << "\n";

    pauseForUser();
    return 0;
}

int checkListOfStudentsRegistered()
{
    clearScreen();
    cout << "\nDaftar Mahasiswa Terdaftar (Username):\n\n";

    vector<string> db = readDbLines();
    if (db.empty()) {
        cout << "Belum ada mahasiswa terdaftar.\n";
        pauseForUser();
        return 0;
    }

    for (auto line : db) {
        if (line.size() > 4 && line.substr(line.size()-4) == ".dat")
            line = line.substr(0, line.size()-4);
        cout << line << "\n";
    }

    pauseForUser();
    return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
    clearScreen();
    cout << "\nDaftar Mahasiswa & Jumlah Kehadiran:\n\n";

    vector<string> db = readDbLines();
    if (db.empty()) {
        cout << "Belum ada mahasiswa.\n";
        pauseForUser();
        return 0;
    }

    for (auto f : db) {
        string username = f.substr(0, f.size()-4);
        string att = username + "_att.dat";

        int cnt = 0;
        ifstream in(att.c_str());
        string line;
        while (in && getline(in, line)) {
            if (!line.empty()) cnt++;
        }

        string realName = username;
        ifstream st(f.c_str());
        getline(st, realName);

        cout << "Username: " << username << " | Nama: " << realName << " | Kehadiran: " << cnt << "\n";
    }

    pauseForUser();
    return 0;
}

int registerStudent()
{
    clearScreen();
    cout << "\n ---- Form Pendaftaran Mahasiswa ---- \n";

    string name, username, password, rollno, address, father, mother;

    cout << "Nama : ";
    getline(cin, name);

    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    cout << "NIM : ";
    getline(cin, rollno);

    cout << "Alamat : ";
    getline(cin, address);

    cout << "Nama Ayah : ";
    getline(cin, father);

    cout << "Nama Ibu : ";
    getline(cin, mother);

    if (username.empty()) {
        cout << "Username tidak boleh kosong.\n";
        pauseForUser();
        return 0;
    }

    vector<string> db = readDbLines();
    string entry = username + ".dat";

    if (find(db.begin(), db.end(), entry) != db.end()) {
        cout << "\nUsername sudah terdaftar.\n";
        pauseForUser();
        return 0;
    }

    db.push_back(entry);
    writeDbLines(db);

    ofstream out(entry.c_str());
    out << name << "\n";
    out << username << "\n";
    out << password << "\n";
    out << rollno << "\n";
    out << address << "\n";
    out << father << "\n";
    out << mother << "\n";
    out.close();

    smallDelay();
    cout << "Mahasiswa berhasil didaftarkan.\n";
    pauseForUser();
    return 0;
}

int studentView()
{
    clearScreen();
    cout << "\n ---- Login Mahasiswa ----\n";

    string username, password;

    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    int res = checkStudentCredentials(username, password);

    if (res == 0)
    {
        cout << "\nUsername atau password salah.\n";
        pauseForUser();
        return 0;
    }

    int goBack = 0;
    while (1)
    {
        clearScreen();
        cout << "\n --- Menu Mahasiswa ---";
        cout << "\n 1. Tandai Kehadiran Hari Ini";
        cout << "\n 2. Lihat Total Kehadiran";
        cout << "\n 0. Kembali\n";
        int choice;

        cout << "\nMasukkan pilihan: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInput tidak valid.\n";
            pauseForUser();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1: markMyAttendance(username); break;
        case 2: countMyAttendance(username); break;
        case 0: goBack = 1; break;
        default: cout << "\nPilihan invalid"; pauseForUser();
        }

        if (goBack == 1) break;
    }

    return 0;
}

int markMyAttendance(const string& username)
{
    clearScreen();
    cout << "\nTandai Kehadiran Hari Ini\n";

    string file = username + "_att.dat";
    string today = todayString();

    ifstream in(file.c_str());
    string line;
    while (in && getline(in, line)) {
        if (line == today) {
            cout << "\nAnda sudah absen hari ini (" << today << ").\n";
            pauseForUser();
            return 0;
        }
    }

    ofstream out(file.c_str(), ios::app);
    out << today << "\n";
    out.close();

    smallDelay();
    cout << "Kehadiran untuk hari ini berhasil dicatat.\n";
    pauseForUser();
    return 0;
}

int countMyAttendance(const string& username)
{
    clearScreen();
    cout << "\nTotal Kehadiran Saya:\n";

    string file = username + "_att.dat";
    ifstream in(file.c_str());
    if (!in) {
        cout << "Belum ada data kehadiran.\n";
        pauseForUser();
        return 0;
    }

    int cnt = 0;
    string line;
    while (getline(in, line)) {
        if (!line.empty()) cnt++;
    }

    cout << "Total kehadiran Anda: " << cnt << " hari.\n";

    pauseForUser();
    return 0;
}

int deleteAllStudents()
{
    clearScreen();
    cout << "\nAnda yakin ingin menghapus SEMUA mahasiswa? (y/n): ";
    char c;
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (c != 'y' && c != 'Y') {
        cout << "Dibatalkan.\n";
        pauseForUser();
        return 0;
    }

    vector<string> db = readDbLines();
    for (const auto& f : db) {
        remove(f.c_str());
        string username = f.substr(0, f.size()-4);
        string att = username + "_att.dat";
        remove(att.c_str());
    }

    writeDbLines(vector<string>());

    smallDelay();
    cout << "Semua mahasiswa berhasil dihapus.\n";
    pauseForUser();
    return 0;
}

int main(int argc, char** argv)
{
    while (1)
    {
        clearScreen();

        cout << "\t Sistem Manajemen Kehadiran \n";
        cout << "-------------------------------------\n\n";

        cout << "1. Login Mahasiswa\n";
        cout << "2. Login Admin\n";
        cout << "0. Keluar\n";
        int choice;

        cout << "\nMasukkan pilihan: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInput tidak valid.\n";
            pauseForUser();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1: studentLogin(); break;
        case 2: adminLogin(); break;
        case 0:
        {
            clearScreen();
            cout << "Yakin ingin keluar? (y/n): ";
            char ex;
            cin >> ex;
            if (ex == 'y' || ex == 'Y') exit(0);
        } break;

        default:
            cout << "\nPilihan tidak valid.\n";
            pauseForUser();
        }
    }

    return 0;
}
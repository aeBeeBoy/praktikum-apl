#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14

string USERNAME = "Ahmad Habibi";
string PASSWORD = "2409106104";

int main() {
    string username, password;
    cout << "\n== SISTEM LOGIN ==\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    cin >> password;
    cin.ignore();
    if (username != USERNAME || password != PASSWORD) {
        cout << "Login gagal!";
        return 0;
    }
    
    int pilihan;
    do {
        cout << "\n== SISTEM HITUNG ==\n1. Hitung Luas\n2. Hitung Keliling\n3. Hitung Volume\n4. Logout\nPilihan: ";
        cin >> pilihan;
        if (pilihan == 1) {
            int subPilihan;
            do {
                cout << "\n== HITUNG LUAS ==\n1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilihan: ";
                cin >> subPilihan;
                double hasil;
                if (subPilihan == 1) {
                    double s;
                    do {
                        cout << "Masukkan sisi: ";
                        cin >> s;
                    } while (s < 0);
                    hasil = s * s;
                } else if (subPilihan == 2) {
                    double p, l;
                    do {
                        cout << "Masukkan panjang: ";
                        cin >> p;
                        cout << "Masukkan lebar: ";
                        cin >> l;
                    } while (p < 0 || l < 0);
                    hasil = p * l;
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: ";
                        cin >> r;
                    } while (r < 0);
                    hasil = PI * r * r;
                } else if (subPilihan == 4) {
                    double a, t;
                    do {
                        cout << "Masukkan alas: ";
                        cin >> a;
                        cout << "Masukkan tinggi: ";
                        cin >> t;
                    } while (a < 0 || t < 0);
                    hasil = 0.5 * a * t;
                }
                if (subPilihan != 5) cout << "Hasil luas: " << hasil << "\n";
            } while (subPilihan != 5);
        } else if (pilihan == 2) {
            int subPilihan;
            do {
                cout << "\n== HITUNG KELILING ==\n1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilihan: ";
                cin >> subPilihan;
                double hasil;
                if (subPilihan == 1) {
                    double s;
                    do {
                        cout << "Masukkan sisi: ";
                        cin >> s;
                    } while (s < 0);
                    hasil = 4 * s;
                } else if (subPilihan == 2) {
                    double p, l;
                    do {
                        cout << "Masukkan panjang: ";
                        cin >> p;
                        cout << "Masukkan lebar: ";
                        cin >> l;
                    } while (p < 0 || l < 0);
                    hasil = 2 * (p + l);
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: ";
                        cin >> r;
                    } while (r < 0);
                    hasil = 2 * PI * r;
                } else if (subPilihan == 4) {
                    double a, b, c;
                    do {
                        cout << "Masukkan sisi 1: ";
                        cin >> a;
                        cout << "Masukkan sisi 2: ";
                        cin >> b;
                        cout << "Masukkan sisi 3: ";
                        cin >> c;
                    } while (a < 0 || b < 0 || c < 0);
                    hasil = a + b + c;
                }
                if (subPilihan != 5) cout << "Hasil keliling: " << hasil << "\n";
            } while (subPilihan != 5);
        } else if (pilihan == 3) {
            int subPilihan;
            do {
                cout << "\n== HITUNG VOLUME ==\n1. Kubus\n2. Balok\n3. Bola\n4. Prisma Segitiga\n5. Kembali\nPilihan: ";
                cin >> subPilihan;
                double hasil;
                if (subPilihan == 1) {
                    double s;
                    do {
                        cout << "Masukkan sisi: ";
                        cin >> s;
                    } while (s < 0);
                    hasil = s * s * s;
                } else if (subPilihan == 2) {
                    double p, l, t;
                    do {
                        cout << "Masukkan panjang: ";
                        cin >> p;
                        cout << "Masukkan lebar: ";
                        cin >> l;
                        cout << "Masukkan tinggi: ";
                        cin >> t;
                    } while (p < 0 || l < 0 || t < 0);
                    hasil = p * l * t;
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: ";
                        cin >> r;
                    } while (r < 0);
                    hasil = (4.0 / 3.0) * PI * pow(r, 3);
                } else if (subPilihan == 4) {
                    double a, t, h;
                    do {
                        cout << "Masukkan alas segitiga: ";
                        cin >> a;
                        cout << "Masukkan tinggi segitiga: ";
                        cin >> t;
                        cout << "Masukkan tinggi prisma: ";
                        cin >> h;
                    } while (a < 0 || t < 0 || h < 0);
                    hasil = 0.5 * a * t * h;
                }
                if (subPilihan != 5) cout << "Hasil volume: " << hasil << "\n";
            } while (subPilihan != 5);
        }
    } while (pilihan != 4);
    return 0;
}

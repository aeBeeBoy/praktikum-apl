#include <iostream>
#include <iomanip>
using namespace std;

string username = "Ahmad Habibi";
string password = "2409106104";
int percobaan = 0;

const int MAX_MINYAK = 100;
string jenisMinyak[MAX_MINYAK];
int hargaMinyak[MAX_MINYAK];    
int stokMinyak[MAX_MINYAK];   
int jumlahMinyak = 0;

int main() {
    string nama, pw;
    while (percobaan < 3) {
        cout << "Masukkan username: ";
        getline(cin, nama);
        cout << "Masukkan password: ";
        getline(cin, pw);
        if (nama == username && pw == password) {
            cout << "Login Berhasil\n";
            break;
        } else {
            cout << "Username atau password salah. Coba lagi.\n";
            percobaan++;
        }
    }
    if (percobaan == 3) {
        cout << "Percobaan melebihi batas, program terhenti.\n";
        return 0;
    }
    int pilihan;
    do {
        cout << "\n===== MENU CRUD MINYAK =====\n";
        cout << "1. Tambah Tipe Minyak (Create)\n";
        cout << "2. Lihat Stok Minyak (Read)\n";
        cout << "3. Ubah Harga & Tambah Stok Minyak (Update)\n";
        cout << "4. Hapus Minyak (Delete)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (jumlahMinyak >= MAX_MINYAK) {
                    cout << "Data minyak penuh!\n";
                    break;
                }
                cout << "Masukkan nama minyak: ";
                getline(cin, jenisMinyak[jumlahMinyak]);
                cout << "Masukkan harga minyak: ";
                cin >> hargaMinyak[jumlahMinyak];
                cout << "Masukkan stok minyak: ";
                cin >> stokMinyak[jumlahMinyak];
                jumlahMinyak++;
                cout << "Data minyak berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                if (jumlahMinyak == 0) {
                    cout << "Tidak ada data minyak.\n";
                    break;
                }
                cout << "\n====================================================================\n";
                cout << "| No  | Nama Minyak         | Harga Minyak      | Stok Minyak       |\n";
                cout << "====================================================================\n";
                for (int i = 0; i < jumlahMinyak; i++) {
                    cout << "| " << setw(3) << i + 1 << " | "
                        << setw(20) << left << jenisMinyak[i] << " | Rp."
                        << setw(15) << hargaMinyak[i] << " | "
                        << setw(15) << stokMinyak[i] << " |\n";
                }
                cout << "====================================================================\n";
                break;
            }
            case 3: {
                if (jumlahMinyak == 0) {
                    cout << "Tidak ada minyak yang bisa diupdate!\n";
                    break;
                }
                int index;
                cout << "Pilih nomor minyak yang ingin diupdate: ";
                cin >> index;
                if (index < 1 || index > jumlahMinyak) {
                    cout << "Nomor minyak tidak valid!\n";
                    break;
                }
                index--;
                cout << "Masukkan harga baru: ";
                cin >> hargaMinyak[index];
                cout << "Masukkan tambahan stok: ";
                int tambahan;
                cin >> tambahan;
                stokMinyak[index] += tambahan;
                cout << "Data minyak berhasil diupdate!\n";
                break;
            }
            case 4: {
                if (jumlahMinyak == 0) {
                    cout << "Tidak ada minyak yang bisa dihapus!\n";
                    break;
                }
                int index;
                cout << "Pilih nomor minyak yang ingin dihapus: ";
                cin >> index;
                if (index < 1 || index > jumlahMinyak) {
                    cout << "Nomor minyak tidak valid!\n";
                    break;
                }
                index--;
                for (int i = index; i < jumlahMinyak - 1; i++) {
                    jenisMinyak[i] = jenisMinyak[i + 1];
                    hargaMinyak[i] = hargaMinyak[i + 1];
                    stokMinyak[i] = stokMinyak[i + 1];
                }
                jumlahMinyak--;
                cout << "Data minyak berhasil dihapus!\n";
                break;
            }
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
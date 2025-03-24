#include <iostream>
#include <iomanip>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Minyak {
    string jenis;
    int harga;
    int stok;
};

struct Data {
    User users[100];
    Minyak daftarMinyak[100];
    int jumlahUser = 0;
    int jumlahMinyak = 0;
};

int main() {
    Data data;
    data.users[0].nama = "Ahmad Habibi";
    data.users[0].nim = "2409106104";
    data.jumlahUser = 1;
    
    int pilihan;
    string nama, nim;
    int percobaan = 0;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Register User\n";
        cout << "2. Login User\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (data.jumlahUser >= 100) {
                    cout << "Pendaftaran penuh!\n";
                    break;
                }
                cout << "Masukkan Nama: ";
                getline(cin, data.users[data.jumlahUser].nama);
                cout << "Masukkan NIM: ";
                getline(cin, data.users[data.jumlahUser].nim);
                data.jumlahUser++;
                cout << "Registrasi berhasil!\n";
                break;
            case 2:
                while (percobaan < 3) {
                    cout << "Masukkan Nama: ";
                    getline(cin, nama);
                    cout << "Masukkan NIM: ";
                    getline(cin, nim);
                    bool loginBerhasil = false;
                    for (int i = 0; i < data.jumlahUser; i++) {
                        if (data.users[i].nama == nama && data.users[i].nim == nim) {
                            loginBerhasil = true;
                            break;
                        }
                    }
                    if (loginBerhasil) {
                        cout << "Login Berhasil!\n";
                        break;
                    }
                    cout << "Nama atau NIM salah. Coba lagi.\n";
                    percobaan++;
                }
                if (percobaan == 3) {
                    cout << "Percobaan melebihi batas, program terhenti.\n";
                    return 0;
                }
                int menu;
                do {
                    cout << "\n===== MENU CRUD MINYAK =====\n";
                    cout << "1. Tambah Tipe Minyak (Create)\n";
                    cout << "2. Lihat Stok Minyak (Read)\n";
                    cout << "3. Ubah Harga & Tambah Stok Minyak (Update)\n";
                    cout << "4. Hapus Minyak (Delete)\n";
                    cout << "5. Logout\n";
                    cout << "Pilih menu: ";
                    cin >> menu;
                    cin.ignore();

                    switch (menu) {
                        case 1:
                            if (data.jumlahMinyak >= 100) {
                                cout << "Data minyak penuh!\n";
                                break;
                            }
                            cout << "Masukkan nama minyak: ";
                            getline(cin, data.daftarMinyak[data.jumlahMinyak].jenis);
                            cout << "Masukkan harga minyak: ";
                            cin >> data.daftarMinyak[data.jumlahMinyak].harga;
                            cout << "Masukkan stok minyak: ";
                            cin >> data.daftarMinyak[data.jumlahMinyak].stok;
                            cin.ignore();
                            data.jumlahMinyak++;
                            cout << "Data minyak berhasil ditambahkan!\n";
                            break;
                        case 2:
                            if (data.jumlahMinyak == 0) {
                                cout << "Tidak ada data minyak.\n";
                                break;
                            }
                            cout << "\n====================================================================\n";
                            cout << "| No  | Nama Minyak         | Harga Minyak      | Stok Minyak       |\n";
                            cout << "====================================================================\n";
                            for (int i = 0; i < data.jumlahMinyak; i++) {
                                cout << "| " << setw(3) << i + 1 << " | "
                                    << setw(20) << left << data.daftarMinyak[i].jenis << " | Rp."
                                    << setw(15) << data.daftarMinyak[i].harga << " | "
                                    << setw(15) << data.daftarMinyak[i].stok << " |\n";
                            }
                            cout << "====================================================================\n";
                            break;
                        case 3:
                            if (data.jumlahMinyak == 0) {
                                cout << "Tidak ada minyak yang bisa diupdate!\n";
                                break;
                            }
                            int index;
                            cout << "Pilih nomor minyak yang ingin diupdate: ";
                            cin >> index;
                            if (index < 1 || index > data.jumlahMinyak) {
                                cout << "Nomor minyak tidak valid!\n";
                                break;
                            }
                            index--;
                            cout << "Masukkan harga baru: ";
                            cin >> data.daftarMinyak[index].harga;
                            cout << "Masukkan tambahan stok: ";
                            int tambahan;
                            cin >> tambahan;
                            data.daftarMinyak[index].stok += tambahan;
                            cin.ignore();
                            cout << "Data minyak berhasil diupdate!\n";
                            break;
                        case 4:
                            if (data.jumlahMinyak == 0) {
                                cout << "Tidak ada minyak yang bisa dihapus!\n";
                                break;
                            }
                            cout << "Pilih nomor minyak yang ingin dihapus: ";
                            cin >> index;
                            if (index < 1 || index > data.jumlahMinyak) {
                                cout << "Nomor minyak tidak valid!\n";
                                break;
                            }
                            for (int i = index - 1; i < data.jumlahMinyak - 1; i++) {
                                data.daftarMinyak[i] = data.daftarMinyak[i + 1];
                            }
                            data.jumlahMinyak--;
                            cin.ignore();
                            cout << "Data minyak berhasil dihapus!\n";
                            break;
                        case 5:
                            cout << "Logout berhasil.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid! Coba lagi.\n";
                    }
                } while (menu != 5);
                break;
            case 3:
                cout << "Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}
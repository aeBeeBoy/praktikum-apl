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

void tampilkanMinyakRekursif(Minyak minyak[], int i, int total) {
    if (i >= total) return;
    cout << "| " << setw(3) << i + 1 << " | "
         << setw(20) << left << minyak[i].jenis << " | Rp."
         << setw(15) << minyak[i].harga << " | "
         << setw(15) << minyak[i].stok << " |\n";
    tampilkanMinyakRekursif(minyak, i + 1, total);
}

void tambahStokDenganPointer(Minyak* minyak, int tambahan) {
    minyak->stok += tambahan;
    cout << "Stok berhasil ditambah menjadi: " << minyak->stok << endl;
}

void ubahHargaDenganAddressOf(Minyak &minyak, int hargaBaru) {
    minyak.harga = hargaBaru;
    cout << "Harga berhasil diubah menjadi: " << minyak.harga << endl;
}

void registerUser(Data &data) {
    if (data.jumlahUser >= 100) {
        cout << "Pendaftaran penuh!\n";
        return;
    }
    cout << "Masukkan Nama: ";
    getline(cin, data.users[data.jumlahUser].nama);
    cout << "Masukkan NIM: ";
    getline(cin, data.users[data.jumlahUser].nim);
    data.jumlahUser++;
    cout << "Registrasi berhasil!\n";
}

bool login(Data &data, string nama, string nim) {
    for (int i = 0; i < data.jumlahUser; i++) {
        if (data.users[i].nama == nama && data.users[i].nim == nim) {
            return true;
        }
    }
    return false;
}

void tambahMinyak(Data &data) {
    if (data.jumlahMinyak >= 100) {
        cout << "Data minyak penuh!\n";
        return;
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
}

void lihatMinyak(Data &data) {
    if (data.jumlahMinyak == 0) {
        cout << "Tidak ada data minyak.\n";
        return;
    }
    cout << "\n====================================================================\n";
    cout << "| No  | Nama Minyak         | Harga Minyak      | Stok Minyak       |\n";
    cout << "====================================================================\n";
    tampilkanMinyakRekursif(data.daftarMinyak, 0, data.jumlahMinyak);
    cout << "====================================================================\n";
}

void updateMinyak(Data &data) {
    if (data.jumlahMinyak == 0) {
        cout << "Tidak ada minyak yang bisa diupdate!\n";
        return;
    }
    int index, tambahan, hargaBaru;
    cout << "Pilih nomor minyak yang ingin diupdate: ";
    cin >> index;
    if (index < 1 || index > data.jumlahMinyak) {
        cout << "Nomor minyak tidak valid!\n";
        return;
    }
    index--;
    cout << "Masukkan harga baru: ";
    cin >> hargaBaru;
    ubahHargaDenganAddressOf(data.daftarMinyak[index], hargaBaru);
    cout << "Masukkan tambahan stok: ";
    cin >> tambahan;
    tambahStokDenganPointer(&data.daftarMinyak[index], tambahan);
    cin.ignore();
    cout << "Data minyak berhasil diupdate!\n";
}

void hapusMinyak(Data &data) {
    if (data.jumlahMinyak == 0) {
        cout << "Tidak ada minyak yang bisa dihapus!\n";
        return;
    }
    int index;
    cout << "Pilih nomor minyak yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > data.jumlahMinyak) {
        cout << "Nomor minyak tidak valid!\n";
        return;
    }
    for (int i = index - 1; i < data.jumlahMinyak - 1; i++) {
        data.daftarMinyak[i] = data.daftarMinyak[i + 1];
    }
    data.jumlahMinyak--;
    cin.ignore();
    cout << "Data minyak berhasil dihapus!\n";
}

int main() {
    Data data;
    data.users[0] = {"Ahmad Habibi", "104"};
    data.jumlahUser = 1;
    int pilihan;
    string nama, nim;
    int percobaan;
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
                registerUser(data);
                break;
            case 2:
                percobaan = 0;
                while (percobaan < 3) {
                    cout << "Masukkan Nama: ";
                    getline(cin, nama);
                    cout << "Masukkan NIM: ";
                    getline(cin, nim);
                    if (login(data, nama, nim)) {
                        cout << "Login Berhasil!\n";
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
                                case 1: tambahMinyak(data); break;
                                case 2: lihatMinyak(data); break;
                                case 3: updateMinyak(data); break;
                                case 4: hapusMinyak(data); break;
                                case 5: cout << "Logout berhasil.\n"; break;
                                default: cout << "Pilihan tidak valid!\n";
                            }
                        } while (menu != 5);
                        break;
                    }
                    cout << "Nama atau NIM salah. Coba lagi.\n";
                    percobaan++;
                }
                if (percobaan == 3) {
                    cout << "Percobaan melebihi batas, program terhenti.\n";
                    return 0;
                }
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
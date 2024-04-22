#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

// Struct untuk mendefinisikan codingan
struct mahasiswa {
    int nim;
    string nama;
    string kelas;
    string prodi;
    mahasiswa *next;
    mahasiswa *prev;
};

// Variabel global awal linked list
mahasiswa *head = NULL;
mahasiswa *tail = NULL;
mahasiswa *current = NULL;

// Memeriksa Linked List
bool isEmpty() { 
    return head == NULL;
}

// Memasukan data mahasiswa baru 
void tambahDataMahasiswa(int nim, string nama, string kelas, string prodi) { 
    mahasiswa* new_mahasiswa = new mahasiswa;
    new_mahasiswa->nama = nama;
    new_mahasiswa->nim = nim;
    new_mahasiswa->kelas = kelas;
    new_mahasiswa->prodi = prodi;

    // Node baru akan menjadi head
    if (isEmpty()) { 
        head = new_mahasiswa;
        new_mahasiswa->next = NULL;
        new_mahasiswa->prev = NULL;
    } else {
        new_mahasiswa->next = head;
        new_mahasiswa->prev = NULL;
        head->prev = new_mahasiswa;
        head = new_mahasiswa;
    }
}

void cariDataMahasiswa(int targetNIM) {
    mahasiswa* current = head;
    while (current != NULL) {
        if (current->nim == targetNIM) {
            system("cls");
            cout << "Data Mahasiswa ditemukan!\n" << endl;
            cout << "NIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Kelas: " << current->kelas << endl;
            cout << "Prodi: " << current->prodi << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa tidak ditemukan.\n" << endl;
}

void ubahDataMahasiswa(int targetNIM) {
    mahasiswa* current = head;
    while (current != NULL) {
        if (current->nim == targetNIM) {
            cout << "Masukkan Nama Baru: ";
            cin >> current->nama;
            cout << "Masukkan Kelas Baru: ";
            cin >> current->kelas;
            cout << "Masukkan Prodi Baru: ";
            cin >> current->prodi;
            system("cls");
            cout << "Data Mahasiswa berhasil diubah!" << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa tidak ditemukan.\n" << endl;
}

void hapusDataMahasiswa(int targetNIM) {
    mahasiswa* current = head;
    while (current != NULL) {
        if (current->nim == targetNIM) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            system("cls");
            cout << "Data Mahasiswa dengan NIM tersebut telah dihapus.\n" << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa berdasarkan NIM tersebut tidak ditemukan.\n" << endl;
}

 // Menampilkan data mahasiswa
void lihatDataMahasiswa() {
    mahasiswa* current = head;
    if (current != NULL) {
        cout << "Daftar Mahasiswa:\n" << endl;
        while (current != NULL) {
            cout << "NIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl; 
            cout << "Kelas: " << current->kelas << endl;
            cout << "Prodi: " << current->prodi << endl;
            cout << endl;
            current = current->next;
        } 
    } else {
        cout << "Data Mahasiswa masih kosong.\n" << endl;
    }
}

void tampilkanMenu() {
    system("cls");
    cout << "========================================" << endl;
    cout << "===== SISTEM KELOLA DATA MAHASISWA =====" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "MENU OPERASI :" << endl;
    cout << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Lihat Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa" << endl;
    cout << "4. Ubah Data Mahasiswa" << endl;
    cout << "5. Hapus Data Mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << endl;
}

int main() {
    int pilihan;
    while (true) {
        tampilkanMenu();
        cout << "Masukan Menu : "; 
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            int nim;
            string nama, kelas, prodi;
            cout << "Masukkan NIM: "; 
            cin >> nim;
            cout << "Masukkan Nama: "; 
            cin >> nama;
            cout << "Masukkan Kelas: "; 
            cin >> kelas;
            cout << "Masukkan Prodi: "; 
            cin >> prodi;
            tambahDataMahasiswa(nim, nama, kelas, prodi);
            system("cls");
            cout << "Data Mahasiswa berhasil ditambahkan!\n" << endl;
        } else if (pilihan == 2) {
            system("cls");
            lihatDataMahasiswa();
        } else if (pilihan == 3) {
            system("cls");
            int targetNIM;
            cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
            cin >> targetNIM;
            cariDataMahasiswa(targetNIM);
        } else if (pilihan == 4) {
            system("cls");
            int targetNIM;
            cout << "Masukkan NIM Mahasiswa yang ingin diubah: ";
            cin >> targetNIM;
            ubahDataMahasiswa(targetNIM);
        } else if (pilihan == 5) {
            system("cls");
            int targetNIM;
            cout << "Masukkan NIM Mahasiswa yang ingin anda hapus: ";
            cin >> targetNIM;
            hapusDataMahasiswa(targetNIM);
        } else if (pilihan == 6) {
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!\n" << endl;
        }

        cout << "1. Kembali ke Menu Utama" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; 
        cin >> pilihan;

        if (pilihan == 2)
            return 0;
    }

    return 0;
}
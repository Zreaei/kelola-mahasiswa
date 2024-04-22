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
mahasiswa *head;
mahasiswa *tail;
mahasiswa *current = NULL;

// Memeriksa Linked List
bool isEmpty(){ 
    if (head == NULL){
        return true;
    } return false;
}

// Memasukan data mahasiswa baru 
void tambahDataMahasiswa(int nim, string nama, string kelas, string prodi){ 
    mahasiswa* new_mahasiswa = new mahasiswa;
    new_mahasiswa->nama = nama; // Mengatur nilai nama_mahasiswa
    new_mahasiswa->nim = nim;   // Mengatur nilai nim_mahasiswa
    new_mahasiswa->kelas = kelas; // Mengatur nilai kelas_mahasiswa
    new_mahasiswa->prodi = prodi; // Mengatur nilai prodi_mahasiswa

    // Node baru akan menjadi head
    if (isEmpty()){ 
        head = new_mahasiswa;
        new_mahasiswa->next = NULL;
    } else {
        new_mahasiswa->next = head;
        new_mahasiswa->prev = NULL;
        head = new_mahasiswa;
    }
}

void cariDataMahasiswa(int targetNIM){
    mahasiswa* current = head;
    while (current != NULL){
        if (current->nim == targetNIM){
            system("cls");
            cout << "Data Mahasiswa ditemukan!" << endl;
            cout << "NIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Kelas: " << current->kelas << endl;
            cout << "Prodi: " << current->prodi << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa tidak ditemukan." << endl;
}

void ubahDataMahasiswa(int targetNIM){
    mahasiswa* current = head;
    while (current != NULL){
        if (current->nim == targetNIM){
            cout << "Masukkan Nama Baru: ";
            cin >> current->nama;
            cout << "Masukkan Kelas Baru: ";
            cin >> current->kelas;
            cout << "Masukkan Prodi Baru: ";
            cin >> current->prodi;
            system("cls");
            cout << "Data Mahasiswa berhasil diubah!" << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa tidak ditemukan." << endl;
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
            cout << "Data Mahasiswa dengan NIM tersebut telah dihapus\n" << endl;
            return;
        }
        current = current->next;
    }
    system("cls");
    cout << "Data Mahasiswa berdasarkan NIM tersebut tidak ditemukan.\n" << endl;
}


 // Menampilkan data mahasiswa
void lihatDataMahasiswa(){
    mahasiswa* current = head;
    if (current != NULL){
        cout << "Daftar Mahasiswa:\n";
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

void tampilkanMenu(){
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

int main(){
    int pilihan;
    tampilkanMenu();
    cout << "Masukan Menu : "; cin >> pilihan;

    if (pilihan == 1){
        system("cls");
        int pilihan;
        int nim;
        string nama, kelas, prodi;
        cout << "Masukkan NIM: "; cin >> nim;
        cout << "Masukkan Nama: "; cin >> nama;
        cout << "Masukkan Kelas: "; cin >> kelas;
        cout << "Masukkan Prodi: "; cin >> prodi;
        tambahDataMahasiswa(nim, nama, kelas, prodi);
        system("cls");
        cout << "Data Mahasiswa berhasil ditambahkan!" << endl;
        cout << endl;
        cout << "1. Kembali" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            main();
        } else if (pilihan == 2) {
            system("cls");
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!" << endl;
        }

    } else if (pilihan == 2){
        system("cls");
        lihatDataMahasiswa();
        cout << "1. Kembali" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            main();
        } else if (pilihan == 2) {
            system("cls");
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!" << endl;
        }
    } else if (pilihan == 3){
        system("cls");
        int targetNIM;
        cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
        cin >> targetNIM;
        cariDataMahasiswa(targetNIM);
        cout << endl;
        cout << "1. Kembali" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            main();
        } else if (pilihan == 2) {
            system("cls");
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!" << endl;
        }
    } else if (pilihan == 4){
        system("cls");
        int targetNIM;
        cout << "Masukkan NIM Mahasiswa yang ingin diubah: ";
        cin >> targetNIM;
        ubahDataMahasiswa(targetNIM);
        cout << endl;
        cout << "1. Kembali" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            main();
        } else if (pilihan == 2) {
            system("cls");
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!" << endl;
        }
    } else if (pilihan == 5){
        system("cls");
        int targetNIM;
        cout << "Masukkan NIM Mahasiswa yang ingin anda hapus: ";
        cin >> targetNIM;
        hapusDataMahasiswa(targetNIM);
        cout << "1. Kembali" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;
        cout << "Masukan Menu : "; cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            main();
        } else if (pilihan == 2) {
            system("cls");
            return 0;
        } else {
            system("cls");
            cout << "Masukan pilihan sesuai dengan opsi!" << endl;
        }
    } else if (pilihan == 6){
        system("cls");
        return 0;
    } else {
        system("cls");
        cout << "Masukan pilihan sesuai dengan opsi!" << endl;
    }
}
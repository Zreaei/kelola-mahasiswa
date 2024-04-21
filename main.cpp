#include <iostream>
#include <stdlib.h>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

void cariDataMahasiswa(Mahasiswa* head, int targetNIM) {
    Mahasiswa* current = head;
    while (current != NULL) {
        if (current->nim == targetNIM) {
            cout << "Data Mahasiswa ditemukan!" << endl;
            cout << "NIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl;
            return;
        }
        current = current->next;
    }
    cout << "Data Mahasiswa tidak ditemukan." << endl;
}

#include <iostream>
using namespace std;

struct mahasiswa //struct untuk mendefinisikan codingan
{
    string nama_mahasiswa;
    int nim_mahasiswa;
    mahasiswa *next;
};

mahasiswa *head = nullptr; //variabel global awal linked list

bool isEmpty() { //memeriksa linked list
    return head == nullptr;
}

void insertfirst(string nama_mahasiswa, int nim_mahasiswa) { //memasukan data mahasiswa baru 
    mahasiswa* new_mahasiswa = new mahasiswa;
    new_mahasiswa->nama_mahasiswa = nama_mahasiswa; // Mengatur nilai nama_mahasiswa
    new_mahasiswa->nim_mahasiswa = nim_mahasiswa;   // Mengatur nilai nim_mahasiswa

    if (isEmpty()) { //node baru akan menjadi head
        new_mahasiswa->next = nullptr;
        head = new_mahasiswa;
    }
    else {
        new_mahasiswa->next = head;
        head = new_mahasiswa;
    }
}

void display() { //menampilkan data mahasiswa
    mahasiswa* current = head;
    cout << "Daftar Mahasiswa:\n";
    while (current != nullptr) {
        cout << "Nama: " << current->nama_mahasiswa << ", NIM: " << current->nim_mahasiswa << endl; 
        current = current->next;
    } 
}

int main () { //memasukan data linked list 
    insertfirst("Muhammad Rafi zamzami", 2301678);
    insertfirst("Naila Melany", 2300512);
    insertfirst("R. Arya Muharrom D.M", 2301720);
    insertfirst("Risti Sabila", 2303903);

    display(); //menampilkan data mahasiswa

    return 0;
}


void tampilkanMenu() {
    system("cls");
    cout << "========================================" << endl;
    cout << "===== SISTEM KELOLA DATA MAHASISWA =====" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "MENU OPERASI :" << endl;
    cout << endl;
    cout << "1. Cari Data Mahasiswa" << endl;
    cout << "2. Tambah Data Mahasiswa" << endl;
    cout << "3. Ubah Data Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiswa" << endl;
    cout << endl;
}

int main() {
    Mahasiswa* head = new Mahasiswa();
    head->nim = 12345;
    head->nama = "Raden";
    
    Mahasiswa* node1 = new Mahasiswa();
    node1->nim = 67890;
    node1->nama = "Zem";
    
    head->next = node1;
    node1->next = NULL;

    int pilihan;
    tampilkanMenu();
    cout << "Masukan Menu : "; cin >> pilihan;

    if (pilihan == 1){
        int targetNIM;
        cout << "Masukkan NIM yang ingin dicari: ";
        cin >> targetNIM;
        cariDataMahasiswa(head, targetNIM);
    } else if (pilihan == 2){
        system("cls");
        cout << "2 Done" << endl;
    } else if (pilihan == 3){
        system("cls");
        cout << "3 Done" << endl;
    } else if (pilihan == 4){
        system("cls");
        cout << "4 Done" << endl;
    } else {
        system("cls");
        cout << "Masukan pilihan sesuai dengan opsi!" << endl;
    }

    return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

// Struct untuk mendefinisikan codingan
struct mahasiswa 
{
    string nama;
    int nim;
    mahasiswa *next;
    mahasiswa *prev;
};

// Variabel global awal linked list
// mahasiswa *head = nullptr; 
mahasiswa *head;
mahasiswa *tail;
mahasiswa *current = NULL;

// Memeriksa Linked List
bool isEmpty() { 
    return head == nullptr;
}

// Memasukan data mahasiswa baru 
void tambahDataMahasiswa(string nama, int nim) { 
    mahasiswa* new_mahasiswa = new mahasiswa;
    new_mahasiswa->nama = nama; // Mengatur nilai nama_mahasiswa
    new_mahasiswa->nim = nim;   // Mengatur nilai nim_mahasiswa

    // Node baru akan menjadi head
    if (isEmpty()) { 
        new_mahasiswa->next = nullptr;
        head = new_mahasiswa;
    } else {
        new_mahasiswa->next = head;
        head = new_mahasiswa;
    }
}

void cariDataMahasiswa(mahasiswa* head, int targetNIM) {
    mahasiswa* current = head;
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

void ubahDataMahasiswa(int targetNIM){

}

void hapusDataMahasiswa (int targetNIM){
    while (head != NULL) {
        if (current->nim = targetNIM) {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            cout << "Nim " << targetNIM << " telah dihapus" << endl;
            return;
        }
    } cout << "Nim " << targetNIM << " tidak ditemukan." << endl;
}

// int main(){
//     cout << "Hapus Nim" << endl;
//     string nimHapus;
//     cout << "Masukkan nim yang ingin dihapus: ";
//     cin >> nimHapus; 
//     deleteDataMahasiswa(nimHapus);
// }

 // Menampilkan data mahasiswa
void display() {
    mahasiswa* current = head;
    cout << "Daftar Mahasiswa:\n";
    while (current != nullptr) {
        cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl; 
        current = current->next;
    } 
}

// int main () { //memasukan data linked list 
//     tambahDataMahasiswa("Muhammad Rafi zamzami", 2301678);
//     tambahDataMahasiswa("Naila Melany", 2300512);
//     tambahDataMahasiswa("R. Arya Muharrom D.M", 2301720);
//     tambahDataMahasiswa("Risti Sabila", 2303903);

//     display(); //menampilkan data mahasiswa

//     return 0;
// }

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
    // mahasiswa* head = new mahasiswa();
    // head->nim = 12345;
    // head->nama = "Raden";
    
    // mahasiswa* node1 = new mahasiswa();
    // node1->nim = 67890;
    // node1->nama = "Zem";
    
    // head->next = node1;
    // node1->next = NULL;

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
        // tambahDataMahasiswa();
        cout << "Done 2" << endl;
    } else if (pilihan == 3){
        system("cls");
        // ubahDataMahasiswa();
        cout << "Done 3" << endl;
    } else if (pilihan == 4){
        system("cls");
        // hapusDataMahasiswa();
        cout << "Done 4" << endl;
    } else {
        system("cls");
        cout << "Masukan pilihan sesuai dengan opsi!" << endl;
    }

    return 0;
}

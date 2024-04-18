#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int pilihan;
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
    cout << "Masukan Menu : "; cin >> pilihan;

    if (pilihan == 1){
        system("cls");
        cout << "1 Done" << endl;
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
}
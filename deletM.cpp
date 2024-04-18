#include <iostream>
#include <malloc.h>
using namespace std;

void deleteNim (string targetNim){
    while (head != NULL) {
        if (current->nim == targetNim) { // mencari nim yang sesuai
            if (current->prev != NULL) //pengecekkan letak node
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current; // menghapus nim
            cout << "Nim " << targetNim << " telah dihapus" << endl;
            return;
        }
    } cout << "Nim " << targetNim << " tidak ditemukan." << endl; //hapus
}

//
cout << "Hapus Nim" << endl;
string nimHapus;
cout << "Masukkan nim yang ingin dihapus: ";
cin >> nimHapus; 
deletenim(nimHapus);
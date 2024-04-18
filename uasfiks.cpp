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

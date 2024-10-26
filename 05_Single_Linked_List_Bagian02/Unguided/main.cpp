#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menyimpan NIM dan Nama mahasiswa
struct Node {
    int nim;
    string nama;
    Node* next;
};

typedef Node* address;

struct List {
    address head;
};

// Function untuk membuat node baru
address createNode(int nim, string nama) {
    address newNode = new Node;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->next = NULL;
    return newNode;
}

// Function untuk menambahkan data mahasiswa ke dalam linked list
void tambahMahasiswa(List &L, int nim, string nama) {
    address newNode = createNode(nim, nama);
    
    // Jika list kosong
    if (L.head == NULL) {
        L.head = newNode;
    } else {
        // Tambahkan di akhir list
        address temp = L.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    cout << "Data mahasiswa berhasil ditambahkan!" << endl;
}

// Function untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(List L, int nim) {
    address current = L.head;
    bool found = false;
    
    while (current != NULL && !found) {
        if (current->nim == nim) {
            found = true;
        } else {
            current = current->next;
        }
    }
    
    if (found) {
        cout << "Mahasiswa ditemukan!" << endl;
        cout << "Nama: " << current->nama << endl;
    } else {
        cout << "Mahasiswa dengan NIM(" << nim << ") tidak ditemukan" << endl;
    }
}

// Function untuk menampilkan semua data mahasiswa
void tampilkanSemuaMahasiswa(List L) {
    address current = L.head;
    
    cout << "\nDaftar Mahasiswa:" << endl;
    cout << "=================" << endl;
    
    if (current == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    while (current != NULL) {
        cout << "NIM: " << current->nim << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "----------------" << endl;
        current = current->next;
    }
}

int main() {
    List L;
    L.head = NULL;
    int pilihan, nim;
    string nama;
    
    do {
        cout << "\nProgram Data Mahasiswa" << endl;
        cout << "======================" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "3. Tampilkan Semua Mahasiswa" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "\nMasukkan data mahasiswa" << endl;
                cout << "NIM: ";
                cin >> nim;
                cout << "Nama: ";
                cin.ignore(); // Clear buffer
                getline(cin, nama);
                tambahMahasiswa(L, nim, nama);
                break;
                
            case 2:
                cout << "\nMasukkan NIM yang dicari: ";
                cin >> nim;
                cariMahasiswa(L, nim);
                break;
                
            case 3:
                tampilkanSemuaMahasiswa(L);
                break;
                
            case 4:
                cout << "Program selesai!" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);
    
    return 0;
}
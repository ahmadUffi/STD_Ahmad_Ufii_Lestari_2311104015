#include <iostream>
#include <string>
using namespace std;

struct Node{
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* next;
    Node* prev;
};

class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;

    public: 
        // constructor
        DoubleLinkedList(){
            head = NULL;
            tail = NULL;
        }

        // fungsi menambahkan data
        void tambahData(int idBuku, string judulBuku, string penulisBuku){
            Node* newNode = new Node();
            newNode->idBuku = idBuku;
            newNode->judulBuku = judulBuku;
            newNode->penulisBuku = penulisBuku;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            cout << "Data berhasil ditambahkan" << endl;
        }

        // Tampilkan dari awal
        void tampilDariAwal(){
            if(head == NULL){
                cout << "Data kosong" << endl;
                return;
            }

            cout << "\nDaftar Buku dari awal:" << endl;
            Node* current = head;
            while(current != NULL){
                cout << "ID Buku: " << current->idBuku << endl;
                cout << "Judul Buku: " << current->judulBuku << endl;
                cout << "Penulis Buku: " << current->penulisBuku << endl;
                cout << "---------------------" << endl;
                current = current->next;
            }
        }

        // Tampilkan dari akhir
        void tampilDariAkhir(){
            if (tail == NULL){
                cout << "Data kosong" << endl;
                return;
            }

            cout << "\nDaftar Buku dari akhir:" << endl;
            Node* current = tail;
            while (current != NULL){
                cout << "ID Buku: " << current->idBuku << endl;
                cout << "Judul Buku: " << current->judulBuku << endl;
                cout << "Penulis Buku: " << current->penulisBuku << endl;
                cout << "---------------------" << endl;
                current = current->prev;
            }
        }
};

int main(){
    DoubleLinkedList daftarBuku;
    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku dari awal\n";
        cout << "3. Tampilkan Buku dari akhir\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();  // Membersihkan newline dari input sebelumnya

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore();  // Mengabaikan newline setelah ID
                
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                
                daftarBuku.tambahData(id, judul, penulis);
                break;

            case 2:
                daftarBuku.tampilDariAwal();
                break;

            case 3:
                daftarBuku.tampilDariAkhir();
                break;

            case 4:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
                break;
        }

    } while (pilihan != 4);

    return 0;
}

// Soal 1: Program mencari elemen tertentu dalam Single Linked List
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

typedef Node* address;
struct List {
    address head;
};

// Function untuk membuat node baru
address createNode(int value) {
    address newNode = new Node;
    newNode->info = value;
    newNode->next = NULL;
    return newNode;
}

// Function untuk mencari elemen
void searchElement(List L, int i) {
    address current = L.head;
    int position = 1;
    
    // Melakukan perulangan selama i belum ditemukan dan current belum NULL
    while (current != NULL && current->info != i) {
        current = current->next;
        position++;
    }
    
    // Jika elemen ditemukan
    if (current != NULL) {
        cout << "Elemen " << i << " ditemukan pada:" << endl;
        cout << "Alamat: " << current << endl;
        cout << "Posisi ke-" << position << endl;
    } else {
        cout << "Elemen " << i << " tidak ditemukan dalam list" << endl;
    }
}

int main() {
    List L;
    L.head = NULL;
    int value;
    
    // Input 6 elemen
    cout << "Masukkan 6 angka:\n";
    for(int i = 0; i < 6; i++) {
        cin >> value;
        address newNode = createNode(value);
        if (L.head == NULL) {
            L.head = newNode;
        } else {
            address temp = L.head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> value;
    searchElement(L, value);
    
    return 0;
}
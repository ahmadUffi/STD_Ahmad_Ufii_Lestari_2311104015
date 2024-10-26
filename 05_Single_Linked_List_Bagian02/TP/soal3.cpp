// Soal 3: Program menambahkan elemen secara terurut
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

// Procedure untuk insert sorted
void insertSorted(List &L, address P) {
    address Q = L.head;
    address Prev = NULL;
    bool found = false;
    
    // Melakukan perulangan selama found masih false dan Q masih menunjuk elemen pada list
    while (!found && Q != NULL) {
        // Melakukan pengecekan apakah info dari elemen yang ditunjuk memiliki nilai lebih kecil dari P
        if (Q->info < P->info) {
            Prev = Q;
            Q = Q->next;
        } else {
            found = true;
        }
    }
    
    // Melakukan pengecekan apakah Q elemen head
    if (Q == L.head) {
        // Tambahkan P sebagai head
        P->next = L.head;
        L.head = P;
    }
    // Melakukan pengecekan apakah Q berisi null
    else if (Q == NULL) {
        // Tambahkan P sebagai elemen terakhir
        Prev->next = P;
        P->next = NULL;
    }
    else {
        // Tambahkan P pada posisi diantara Prev dan Q
        Prev->next = P;
        P->next = Q;
    }
}

// Function untuk menampilkan list
void displayList(List L) {
    address current = L.head;
    while (current != NULL) {
        cout << current->info;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    List L;
    L.head = NULL;
    int value;
    
    // Input 4 elemen terurut
    cout << "Masukkan 4 angka secara terurut:\n";
    for(int i = 0; i < 4; i++) {
        cin >> value;
        address newNode = createNode(value);
        if (L.head == NULL) {
            L.head = newNode;
        } else {
            insertSorted(L, newNode);
        }
    }
    
    cout << "List saat ini: ";
    displayList(L);
    
    cout << "Masukkan nilai baru untuk disisipkan: ";
    cin >> value;
    address newNode = createNode(value);
    insertSorted(L, newNode);
    
    cout << "List setelah penyisipan: ";
    displayList(L);
    
    return 0;
}
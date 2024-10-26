// Soal 2: Program mengurutkan list menggunakan Bubble Sort
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

// Procedure untuk bubble sort
void bubbleSort(List &L) {
    bool swapped;
    address current;
    
    do {
        swapped = false;
        current = L.head;
        
        while (current->next != NULL) {
            if (current->info > current->next->info) {
                // Tukar data
                int temp = current->info;
                current->info = current->next->info;
                current->next->info = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
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
    
    // Input 5 elemen
    cout << "Masukkan 5 angka:\n";
    for(int i = 0; i < 5; i++) {
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
    
    cout << "List sebelum sorting: ";
    displayList(L);
    bubbleSort(L);
    cout << "List setelah sorting: ";
    displayList(L);
    
    return 0;
}
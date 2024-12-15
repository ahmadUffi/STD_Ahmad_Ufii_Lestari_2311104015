#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;
typedef struct ElemList *address;

struct ElemList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = nullptr;
}

address allocate(infotype data) {
    address P = new ElemList;
    P->info = data;
    P->next = nullptr;
    return P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(address prec, address P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void printList(const List &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM : " << P->info.nim << endl;
        cout << "L/P : " << P->info.jenis_kelamin << endl;
        cout << "IPK : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);
    infotype m1 = {"Ali", "01", 'L', 3.3};
    infotype m2 = {"Paul", "02", 'L', 3.14};
    infotype m3 = {"Ali", "03", 'L', 3.43};
    infotype m4 = {"Ahmad", "04", 'L', 3.84};
    infotype m5 = {"Uffi", "05", 'L', 3.39};
    infotype m6 = {"Intan", "06", 'L', 3.11};
    infotype m7 = {"Azizah", "07", 'L', 3.9};
    infotype m8 = {"Makruf", "08", 'L', 3.5};

    // Allocate elements
    address p1 = allocate(m1);
    address p2 = allocate(m2);
    address p3 = allocate(m3);
    address p4 = allocate(m4);
    address p5 = allocate(m5);
    address p6 = allocate(m6);
    address p7 = allocate(m7);
    address p8 = allocate(m8);

    // Insert data
    insertFirst(L, p1);
    insertLast(L, p2);
    insertAfter(p2, p3);
    insertAfter(p3, p4);
    insertLast(L, p5);
    insertLast(L, p6);
    insertLast(L, p7);
    insertLast(L, p8);

    // Print list
    printList(L);

    return 0;
}

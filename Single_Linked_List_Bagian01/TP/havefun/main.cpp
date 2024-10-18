#include "list.h"

int main() {
    List L;
    address P;
    infotype x;

    createList(L);

    cout << "Masukkan NIM perdigit" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << " : ";
        cin >> x;
        P = allocate(x);
        insertLast(L, P);
    }

    cout << "Isi list : ";
    printInfo(L);

    return 0;
}
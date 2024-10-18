#include <iostream>
#include "list.h"

int main() {
    List L;
    address P;
    infotype x;

    createList(L);

    // Input 3 digits of NIM (assuming the last 3 digits are 742)
    x = 2;
    P = allocate(x);
    insertFirst(L, P);

    x = 4;
    P = allocate(x);
    insertFirst(L, P);

    x = 7;
    P = allocate(x);
    insertFirst(L, P);

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}
#include <iostream>
using namespace std;

const int IDXMAX = 15;

struct Kota {
    string nama;
};

struct Stack {
    Kota T[IDXMAX];
    int top;
};

bool isEmpty(Stack &S) {
    return S.top == -1;
}

bool isFull(Stack &S) {
    return S.top == IDXMAX - 1;
}

Stack createStack() {
    Stack S;
    S.top = -1;
    return S;
}

void push(Stack &S, string nama) {
    if (isFull(S)) {
        cout << "Stack Penuh" << endl;
    } else {
        S.top = S.top + 1;
        S.T[S.top].nama = nama;  // Set the name of the Kota
        cout << "Data berhasil ditambahkan" << endl;
        cout << "=====================" << endl;
    }
}

Kota pop(Stack &S) {
    Kota P;
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        P = S.T[S.top];  // Get the Kota to be popped
        S.top = S.top - 1;
        
    }
    return P;
}

void printStack(Stack &S) {
    cout << "== Isi Stack ==" << endl;
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.T[i].nama ;
        }
    }
    cout << endl;
}

int main() {
    Stack S = createStack();
    cout << "Posisi dari Top : " << S.top << endl;
    push(S, "G");
    push(S, "N");
    push(S, "U");
    push(S, "D");
    push(S, "N");
    push(S, "A");
    push(S, "B");
    push(S, "O");
    push(S, "L");
    push(S, "A");
    push(S, "H");
    printStack(S);
    pop(S);
    pop(S);
    pop(S);
    pop(S);
    cout << "=====================" << endl;
    printStack(S);


    return 0;
}

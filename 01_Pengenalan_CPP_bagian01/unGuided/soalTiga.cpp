#include <iostream>
using namespace std;

void printPattern(int n) {  
    for (int i = n; i > 0; i--) {
        // cetak untuk bagian kiri
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "* ";
        // Bagian untuk bagian kanan
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "*" ;
}

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;
    printPattern(n);
    return 0;
}

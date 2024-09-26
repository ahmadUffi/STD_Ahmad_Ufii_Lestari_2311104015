#include <iostream>
using namespace std;

// Array untuk angka 0 sampai 19
string angka[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", 
                  "Sepuluh", "Sebelas", "Dua belas", "Tiga belas", "Empat belas", "Lima belas", 
                  "Enam belas", "Tujuh belas", "Delapan belas", "Sembilan belas"};

// Array untuk puluhan
string puluhan[] = {"", "", "Dua puluh", "Tiga puluh", "Empat puluh", "Lima puluh", 
                    "Enam puluh", "Tujuh puluh", "Delapan puluh", "Sembilan puluh"};

// Fungsi untuk mengubah angka menjadi teks
void angkaKeTeks(int n) {
    if (n >= 0 && n <= 19) {
        cout << angka[n];
    } else if (n >= 20 && n <= 99) {
        cout << puluhan[n / 10];
        if (n % 10 != 0) {
            cout << " " << angka[n % 10];
        }
    } else if (n == 100) {
        cout << "Seratus";
    }
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    // Pastikan input berada dalam rentang yang benar
    if (n < 0 || n > 100) {
        cout << "Input tidak valid!";
    } else {
        cout << n << " : ";
        angkaKeTeks(n);
        cout << endl;
    }

    return 0;
}

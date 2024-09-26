#include <iostream>
using namespace std;
int main(){
    float a, b, hasil;
    cout << "Masukkan nilai a: "; cin >> a;
    cout << "Masukkan nilai b: "; cin >> b;
    hasil = a + b;
    cout << "Hasil penjumlahan: " << hasil << endl;
    hasil = a - b;
    cout << "Hasil pengurangan: " << hasil << endl;
    hasil = a * b;
    cout << "Hasil perkalian: " << hasil << endl;
    hasil = a / b;
    cout << "Hasil pembagian: " << hasil << endl;
    return 0;
}
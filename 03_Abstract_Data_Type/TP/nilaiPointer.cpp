#include <iostream>
using namespace std;

int main() {
    int x = 20;
    int* ptr = &x; // Pointer ptr menyimpan alamat dari x

    cout << "Nilai x: " << x << endl;
    cout << "Alamat memori x: " << ptr << endl;
    cout << "Nilai yang disimpan di alamat yang ditunjuk ptr: " << *ptr << endl;

    return 0;
}

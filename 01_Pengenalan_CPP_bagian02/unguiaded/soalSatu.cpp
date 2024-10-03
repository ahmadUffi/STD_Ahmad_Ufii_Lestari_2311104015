#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> genap;
    vector<int> ganjil;

    // Memisahkan bilangan genap dan ganjil
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            genap.push_back(arr[i]);
        } else {
            ganjil.push_back(arr[i]);
        }
    }
    // Menampilkan data array
    cout << "data array : ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    // Menampilkan bilangan genap
    cout << "Genap: ";
    for (size_t i = 0; i < genap.size(); i++) {
        cout << genap[i] << " ";
    }
    cout << endl;

    // Menampilkan bilangan ganjil
    cout << "Ganjil: ";
    for (size_t i = 0; i < ganjil.size(); i++) {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Meminta input ukuran array dari pengguna
    cout << "Masukkan ukuran dimensi pertama (x): ";
    cin >> x;
    cout << "Masukkan ukuran dimensi kedua (y): ";
    cin >> y;
    cout << "Masukkan ukuran dimensi ketiga (z): ";
    cin >> z;

    // Deklarasi array 3D dinamis
    int array3D[x][y][z];

    // Meminta input elemen-elemen array dari pengguna
    cout << "Masukkan elemen-elemen array 3D:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan isi array 3D
    cout << "\nIsi array 3D:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: " << array3D[i][j][k] << endl;
            }
        }
    }


    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlahSimpul;

    // Menerima input jumlah simpul
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    // Menerima input nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << (i + 1) << " : ";
        cin >> namaSimpul[i];
    }

    // Menerima input bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i != j) { // Menghindari input bobot untuk simpul yang sama
                cout << namaSimpul[i] << " --> " << namaSimpul[j] << " : ";
                cin >> bobot[i][j];
            }
        }
    }

    // Menampilkan bobot antar simpul
    cout << endl << "Bobot antar simpul:" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << " " << namaSimpul[j] << " : " << bobot[i][j] << endl;
        }
    }

    return 0;
}

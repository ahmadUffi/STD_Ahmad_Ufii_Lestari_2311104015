#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;

    // Menerima input jumlah simpul
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    // Menerima input jumlah sisi
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    // Membuat adjacency matrix
    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul (misal: 1 2 untuk simpul 1 dan 2):" << endl;
    for (int i = 0; i < jumlahSisi; i++) {
        int u, v;
        cin >> u >> v;

        // Mengurangi 1 untuk indeks array (0-based index)
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1; // Karena graf tidak berarah
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

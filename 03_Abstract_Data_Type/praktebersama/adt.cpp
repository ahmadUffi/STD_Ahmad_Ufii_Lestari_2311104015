#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiiswa &m){
    cout << "input nim = "; cin >> m.nim;
    cout << "input nilai 1 = "; cin >> m.nilai1;
    cout << "input nilai 2 = "; cin >> m.nilai2;
}

float rata2(mahasiiswa m){

    return (m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs) << endl;
    return 0;
};




// void inputMhs(mahasiiswa &m){
//     cout << "input nama = " << endl;
// }
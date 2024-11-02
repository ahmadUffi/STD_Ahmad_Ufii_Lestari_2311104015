#include <iostream>
#include <string>
using namespace std;

string balikKalimat(string kalimat){
    string hasil = "";
    int length = kalimat.length();
    for(int i = length - 1; i >= 0 ; i--){
        hasil += kalimat[i];
    }
    return hasil;
}
int main(){
    string kalimat;

    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "Data array : " << kalimat << endl;
    cout << "Data di balik : " << balikKalimat(kalimat) << endl;

}
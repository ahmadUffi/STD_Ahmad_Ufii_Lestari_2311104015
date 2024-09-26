#include <iostream>

using namespace std;

int main(){
    int nilai;
    cout << "Berapa Nilai Anda :";
    cin >> nilai;
    if (nilai > 80) {
        cout << "A" << endl;
    } else {
        cout << "Bukan A" << endl;
    }
    
    return 0;
}

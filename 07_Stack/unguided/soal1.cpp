#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

// mengubah string menjadi kecil dan menghapus spasi
string formatString(string str){
    string result = "";
    for(char c : str){
        if(!isspace(c)){
            result += tolower(c);
        }

    }
    return result;
}

bool cekPolidrom(string str){
    str = formatString(str);

    stack<char> s;
    int n = str.length();

    for(int i = 0; i < n/2; i++){
        s.push(str[i]);
    }

    int startIndex = (n / 2 == 0 ) ? n/2 : n/2 + 1;

    for(int i = startIndex; i < n; i++){
        if(s.empty()) return false;
        if(s.top() != str[i]) return false;
        s.pop();
    }

    return true;
}

int main(){
    string str;
    char lanjut;
    do{

        cout << "Masukkan kata atau kalimat: ";
        getline(cin, str);

        if(cekPolidrom(str)){
            cout << "Kata atau kalimat tersebut adalah polidrom" << endl;
        }else {
            cout << "Kata atau kalimat tersebut bukan polidrom" << endl;
        }
        cout << "Apakah anda ingin mengulang? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    }while(tolower(lanjut) == 'y');
    return 0;
}
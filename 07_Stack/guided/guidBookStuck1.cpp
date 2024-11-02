#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;
   
bool isFull(){
    return top == maksimal;
}

bool isEmpty(){
    return top == 0;
}

void pushArrayBuku(string buku ){
    if(isFull()){
        cout << "Data sudah penuh" << endl;

    }else{
        arrayBuku[top] = buku;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout << "Data sudah kosong" << endl;
    }else{
        arrayBuku[top -1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi){
    if(isEmpty()){
        cout << "Data sudah kosong" << endl;
    }else{
        int index = top - posisi;
        if(index >= 0 ; index < top){
            cout << "Data pada posisi " << posisi << " adalah " << arrayBuku[index] << endl;
        }else{
            cout << "Posisi tidak valid" << endl;
        }
    }
}

int countStack(){
    return top;
}

void changeArrayBuku(int posisi, string data){
     int index = top - posisi;
     if(index >= 0 && index < top){
        arrayBuku[index] = data;
     }else{
        cout << "Posisi tidak valid" << endl;
     }

}

void destroyArrayBuku(){
    for(int i = top -1 ; i >= 0; i--){
        arrayBuku[i] = "";
    }

    top = 0;
}

void cetakArrayBuku(){
    if(isEmpty()){
        cout << "Data masih kosong" << endl;
    }else{
        for(int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}

int main(){
    pushArrayBuku("kalkulus");
    pushArrayBuku("ipa");
    pushArrayBuku("bhs.inggris");
    pushArrayBuku("matematika");
    pushArrayBuku("pkn");

    cetakArrayBuku();
    cout << "\n " << endl;

    cout << "apakah data stack penuh" <<( isFull() ? "ya" : "tidak") << endl;
    cout << "apakah data stack kosong" << (isEmpty() ? "ya" : "tida") << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "banyaknya data =" << countStack() << endl;

    changeArrayBuku(2, "web design");
    cetakArrayBuku();
    cout << '\n' << endl;

    destroyArrayBuku();
    cout << "top setelah data di destroy =" << top << endl;
    cetakArrayBuku();
    
    

    return 0;  
}
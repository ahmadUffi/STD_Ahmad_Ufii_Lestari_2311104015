#include <iostream> 
#include <string>
using namespace std;

const int maxQueue = 5;
int front = 0;
int back = 0;
string queTeller[5];

bool isFull() {
    return (back == maxQueue);
}

bool isEmpty() {
    return (back == 0);
}

void enqueue(string data){
    if(isFull()){
        cout << "antrian penuh" << endl;
    }else{
        if(isEmpty()){
            queTeller[0] = data;
            front++;
            back++;
        }else{zz
            queTeller[back] = data;
            back++;
        }
            
    }
}

void dequeue(){
    if(isEmpty()){
        cout << "antrian kosong" << endl;
    } else{
        cout << "pasien yang dikeluarkan: " << queTeller[front] << endl;
        for(int i = 0; i < back - 1; i++){
            queTeller[i] = queTeller[i+1];
        }
        queTeller[back -1 ] = "";
        back--;
    }
}

int countQueue(){
    return back; 
}

void clearQueue(){
  if(isEmpty()){
    cout << "antrian kosong" << endl;
    
  }else{
    for(int i = 0; i < back; i++){
        queTeller[i] = "";
    }
    back = 0;
    front = 0;
  }
}

void viewQueue(){
    if(isEmpty()){
        cout << "antrian kosong" << endl;
    } else{
        cout << "Antrian: ";
        for(int i = 0; i < maxQueue; i++){
            cout << queTeller[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    enqueue("Ahmad");
    enqueue("Uffi");
    enqueue("Lestari");
    enqueue("Ma'ruf");
    cout << "================================================================" << endl;
    viewQueue();
    cout << "Jumlah Antrian =" << countQueue() << endl;
    dequeue();
    viewQueue();

    cout << "Jumlah Antrian =" << countQueue() << endl;
    clearQueue();
    viewQueue();

    cout << "==============================================" << endl;
    cout << "Jumlah Antrian =" << countQueue() << endl;
    return 0;




}
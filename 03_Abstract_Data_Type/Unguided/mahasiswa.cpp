#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};
    float nilaiAkhir(float uts, float uas, float tugas){
       float nilai = (uts * 0.3) + (uas * 0.4) + (tugas * 0.3);
        return nilai;
    }

    void tampilkanNilai(Mahasiswa mahasiswa[], int jumlah){
        cout << "\n Data mahasiswa \n";
        cout << "Nama\tNIM\tUTS\tUAS\tTugas\tNilai Akhir\n";

        for(int i = 0; i < jumlah; i++){
            cout << mahasiswa[i].nama << "\t"
            << mahasiswa[i].nim << "\t"
            << mahasiswa[i].uts << "\t"
            << mahasiswa[i].uas << "\t"
            << mahasiswa[i].tugas << "\t"
            << mahasiswa[i].nilaiAkhir << endl;
        };
    };


int main() {
    const int maxMahaiswa = 10;
    Mahasiswa mhs[maxMahaiswa];

    int jumlahMhasiswa = 0;
    char pilihan;

    for(int i = 0 ; i < maxMahaiswa ; i++){
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "Masukan Nama : ";
        cin >> mhs[i].nama << endl;
        cout << "Masukan NIM : ";
        cin >> mhs[i].nim << endl;
        cout << "Masukan Nilai UTS : ";
        cin >> mhs[i].uts << endl;
        cout << "Masukan Nilai UAS : ";
        cin >> mhs[i].uas << endl;
        cout << "Masukan Nilai Tugas : ";
        cin >> mhs[i].tugas << endl;
        
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);

        jumlahMhasiswa++;

        cout << "Apakah ingin memasukan data mahasiswa lagi Y / N";
        cin >> pilihan;

        if(pilihan == 'n' || pilihan == 'N'){
            break;
        }
    }

    tampilkanNilai(mhs, jumlahMhasiswa);

    return 0;

}


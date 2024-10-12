#include <iostream>
#include <cmath>
using namespace std;

class Kerucut {
    private : 
        double radius;
        double tinggi;
    public :
        // Constructor
        Kerucut(double r, double t){
            radius = r;
            tinggi = t;
        };

        double hitungVolume(){
            return (M_PI  * radius * radius * tinggi) / 3;
        };

        double luasPermukaanKerucut(){
           double s = sqrt((radius * radius) + (tinggi * tinggi));
            return (M_PI * radius * (s + radius));
        };

        double tampilkanHasil(){
            cout << "jari - jari : " << radius << endl;
            cout << "tinggi : " << tinggi << endl;
            cout << "Volume : " << hitungVolume() << endl;
            cout << "Luas Permukaan : " << luasPermukaanKerucut() << endl;
            return 0;
        }

};

int main(){
    double r, t;
    cout << "masukan jari jari als kerucut : ";
    cin >> r;
    cout << "masukan tinggi kerucut : ";
    cin >> t;
    

    Kerucut kerucut(r, t);
    kerucut.tampilkanHasil();
}
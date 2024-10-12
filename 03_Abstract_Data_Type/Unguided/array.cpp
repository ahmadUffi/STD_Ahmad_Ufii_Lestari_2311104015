#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void pindahElement(int arr1[3][3], int arr2[3][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

void pindahPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    int a = 10, b = 20;
    int *ptrA = &a, *ptrB = &b;

    cout << "Isi Array 1:" << endl;
    tampilkanArray(array1);
    cout << "Isi Array 2:" << endl;
    tampilkanArray(array2);

    pindahElement(array1, array2, 1, 1);

    cout << "Setelah menukar elemen di posisi [1][1]:" << endl;
    cout << "Isi Array 1:" << endl;
    tampilkanArray(array1);
    cout << "Isi Array 2:" << endl;
    tampilkanArray(array2);

    cout << "Sebelum menukar nilai menggunakan pointer:" << endl;
    cout << "Nilai a = " << a << ", Nilai b = " << b << endl;

    pindahPointer(ptrA, ptrB);

    cout << "Setelah menukar nilai menggunakan pointer:" << endl;
    cout << "Nilai a = " << a << ", Nilai b = " << b << endl;

    return 0;
}

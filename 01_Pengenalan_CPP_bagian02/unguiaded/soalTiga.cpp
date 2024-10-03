#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah banyaknya array: ";
    cin >> n;

    int arr[n], maks = numeric_limits<int>::min(), min = numeric_limits<int>::max();
    double total = 0;
    
    cout << "Masukkan banyaknya array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > maks) maks = arr[i];
        if (arr[i] < min) min = arr[i];
        total += arr[i];
    }

    cout << "Nilai maksimum: " << maks << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << total / n << endl;

    return 0;
}

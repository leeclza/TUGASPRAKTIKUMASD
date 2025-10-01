#include <iostream>
using namespace std;

void balikArray(int *ptr, int n) {
    for (int i = 0; i < n / 2; ++i) {
        int tmp = *(ptr + i);
        *(ptr + i) = *(ptr + (n - 1 - i));
        *(ptr + (n - 1 - i)) = tmp;
    }
}

void printArray(int *ptr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << *(ptr + i);
        if (i < n - 1) cout << " ";
    }
    cout << '\n';
}

int main() {
    const int maxN = 1000;
    int arr[maxN];
    int n;

    cout << "Masukkan ukuran array n: ";
    cin >> n;
    if (n <= 0 || n > maxN) {
        cout << "Nilai n tidak valid. Pakai 1.." << maxN << '\n';
        return 0;
    }

    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);        
    }

    cout << "Array sebelum dibalik: ";
    printArray(arr, n);

    balikArray(arr, n);         

    cout << "Array setelah dibalik: ";
    printArray(arr, n);

    return 0;
}

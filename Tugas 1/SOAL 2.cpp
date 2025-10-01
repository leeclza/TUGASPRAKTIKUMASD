#include <iostream>
using namespace std;

// Fungsi operasi: hitung jumlah kuadrat dan hasil kali bilangan ganjil
void operasi(int *x, int y, int *z) {
    *x = 0;          // inisialisasi jumlah kuadrat
    *z = 1;          // inisialisasi hasil kali ganjil
    for(int n = 1; n <= y; n++) {
        *x += n * n;       // jumlah kuadrat dari 1^2 + 2^2 + ... + y^2
        *z *= (2 * n - 1); // kali semua bilangan ganjil: 1 * 3 * 5 * ...
    }
}

int main() {
    int x, y, z;
    cout << "y: "; cin >> y;  

    operasi(&x, y, &z);        // panggil fungsi dengan pointer

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;
    return 0;
}

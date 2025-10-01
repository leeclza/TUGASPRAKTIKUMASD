#include <iostream>
using namespace std;

// Fungsi untuk menghitung jumlah bilangan ganjil 1 sampai y
// Hasil disimpan di pointer *x
void jumlahGanjil(int *x, int y) {
    *x = 0;                      
    for(int i = 1; i <= y; i+=2) // loop hanya bilangan ganjil
        *x += i;                  // tambahkan ke hasil
}

int main() {
    int y; 
    cout << "Masukkan nilai y: "; 
    cin >> y;                    

    int hasil = 0; 
    jumlahGanjil(&hasil, y);      // panggil fungsi dengan alamat hasil
    cout << "Hasil: " << hasil;   
    return 0;
}

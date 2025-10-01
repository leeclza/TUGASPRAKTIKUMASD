#include <iostream>
using namespace std;

void jumlahGanjil(int *x, int y) {
    *x = 0;
    for(int i = 1; i <= y; i += 2){
        *x += i;
    }
}

int main() {
    int y;
    cout << "Masukkan nilai y: "; cin >> y;
    int hasil = 0;
    jumlahGanjil(&hasil, y);
    cout << "Hasil: " << hasil << endl;
}
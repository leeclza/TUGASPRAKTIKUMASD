#include <iostream>
using namespace std;

void operasi(int *x, int y, int *z) {
    *x = 0;
    *z = 1;
    for(int n = 1; n <= y; n++) {
        *x += n * n;
        *z *= (2 * n - 1);
    }
}

int main() {
    int x, y, z;
    cout << "y: "; cin >> y;

    operasi(&x, y, &z);

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;
}
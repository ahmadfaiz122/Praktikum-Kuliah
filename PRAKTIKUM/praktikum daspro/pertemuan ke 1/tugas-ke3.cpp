#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Masukkan nilai a: ";
    cin >> a;

    cout << "Masukkan nilai b: ";
    cin >> b;

    // =========================
    // CARA 1: Variabel bantuan
    // =========================

    int x = a;
    int y = b;

    cout << "\n=== CARA 1: VARIABEL BANTUAN ===" << endl;
    cout << "Sebelum: x = " << x << ", y = " << y << endl;

    int temp = x;
    x = y;
    y = temp;

    cout << "Sesudah: x = " << x << ", y = " << y << endl;


    // =========================
    // CARA 2: Tanpa variabel bantuan
    // =========================

    int p = a;
    int q = b;

    cout << "\n=== CARA 2: TANPA VARIABEL BANTUAN ===" << endl;
    cout << "Sebelum: p = " << p << ", q = " << q << endl;

    p = p + q;
    q = p - q;
    p = p - q;

    cout << "Sesudah: p = " << p << ", q = " << q << endl;

    return 0;
}
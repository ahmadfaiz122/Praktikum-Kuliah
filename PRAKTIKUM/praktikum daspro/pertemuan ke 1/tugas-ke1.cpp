#include <iostream>
using namespace std;

int main() {
    int totalDetik;

    cout << "Masukkan total detik: ";
    cin >> totalDetik;

    int jam = totalDetik / 3600;
    int sisa = totalDetik % 3600;

    int menit = sisa / 60;
    int detik = sisa % 60;

    cout << jam << " jam "
         << menit << " menit "
         << detik << " detik" << endl;

    return 0;
}


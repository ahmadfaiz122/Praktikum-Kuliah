#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double PHI = 3.14159;

    double r, t;

    cout << "Masukkan jari-jari: ";
    cin >> r;

    cout << "Masukkan tinggi: ";
    cin >> t;

    double luasAlas = PHI * r * r;
    double luasSelimut = 2 * PHI * r * t;
    double luasPermukaan = 2 * luasAlas + luasSelimut;
    double volume = PHI * r * r * t;

    cout << fixed << setprecision(3);

    cout << "\n=================================" << endl;
    cout << "          HASIL TABUNG           " << endl;
    cout << "=================================" << endl;

    cout << left;
    cout << setw(20) << "Luas Alas"
         << ": " << luasAlas << endl;

    cout << setw(20) << "Luas Selimut"
         << ": " << luasSelimut << endl;

    cout << setw(20) << "Luas Permukaan"
         << ": " << luasPermukaan << endl;

    cout << setw(20) << "Volume"
         << ": " << volume << endl;

    cout << "=================================" << endl;

    return 0;
}
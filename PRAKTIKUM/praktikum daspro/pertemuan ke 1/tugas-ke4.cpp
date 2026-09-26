#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan bilangan bulat: ";
    cin >> angka;

    cout << boolalpha;

    cout << "Bilangan genap                  : "
         << (angka % 2 == 0) << endl;

    cout << "Positif dan habis dibagi 3     : "
         << (angka > 0 && angka % 3 == 0) << endl;

    cout << "Habis dibagi 5 atau 7          : "
         << (angka % 5 == 0 || angka % 7 == 0) << endl;

    cout << "Bukan bilangan negatif         : "
         << !(angka < 0) << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double BOBOT_TUGAS = 0.20;
    const double BOBOT_KUIS = 0.10;
    const double BOBOT_UTS = 0.30;
    const double BOBOT_UAS = 0.40;

    string nama;
    double tugas, kuis, uts, uas;

    cout << "Nama mahasiswa: ";
    getline(cin, nama);

    cout << "Nilai tugas: ";
    cin >> tugas;

    cout << "Nilai kuis: ";
    cin >> kuis;

    cout << "Nilai UTS: ";
    cin >> uts;

    cout << "Nilai UAS: ";
    cin >> uas;

    double nilaiAkhir =
        tugas * BOBOT_TUGAS +
        kuis * BOBOT_KUIS +
        uts * BOBOT_UTS +
        uas * BOBOT_UAS;

    cout << fixed << setprecision(2);

    cout << "\n=== HASIL ===" << endl;
    cout << "Nama       : " << nama << endl;
    cout << "Nilai Tugas: " << tugas << endl;
    cout << "Nilai Kuis : " << kuis << endl;
    cout << "Nilai UTS  : " << uts << endl;
    cout << "Nilai UAS  : " << uas << endl;
    cout << "Nilai Akhir: " << nilaiAkhir << endl;

    return 0;
}
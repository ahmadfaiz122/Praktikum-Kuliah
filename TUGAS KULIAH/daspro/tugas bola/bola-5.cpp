#include <iostream>
#include <unistd.h>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int tinggi = 20;
    int lebar = 60;
    int jumlahBola = 5;
    int maxFrame = 500;

    // Posisi dan kecepatan awal setiap bola (berbeda-beda)
    vector<float> posX = {5, 10, 15, 20, 25};
    vector<float> posY = {3, 5, 8, 10, 12};
    vector<float> vx   = {1.0f, 1.5f, 0.7f, 2.0f, 1.2f};
    vector<float> vy   = {1.0f, 0.6f, 1.3f, 0.9f, 1.7f};
    vector<char> simbol = {'O', '@', '*', '#', '+'}; // simbol beda tiap bola

    for (int frame = 1; frame <= maxFrame; frame++) {
        // Bersihkan layar
        system("cls"); 

        // Update posisi & pantulan untuk setiap bola
        for (int i = 0; i < jumlahBola; i++) {
            posX[i] += vx[i];
            posY[i] += vy[i];

            if (posX[i] <= 1 || posX[i] >= lebar - 2) {
                vx[i] = -vx[i];
            }
            if (posY[i] <= 1 || posY[i] >= tinggi - 2) {
                vy[i] = -vy[i];
            }
        }

        // Gambar kotak dan semua bola
        for (int y = 0; y < tinggi; y++) {
            for (int x = 0; x < lebar; x++) {
                if (y == 0 || y == tinggi - 1 || x == 0 || x == lebar - 1) {
                    cout << "#"; // dinding
                    continue;
                }

                bool adaBola = false;
                for (int i = 0; i < jumlahBola; i++) {
                    if ((int)round(posX[i]) == x && (int)round(posY[i]) == y) {
                        cout << simbol[i];
                        adaBola = true;
                        break;
                    }
                }

                if (!adaBola) {
                    cout << " ";
                }
            }
            cout << endl;
        }

        usleep(28000); // delay animasi
    }

    return 0;
}
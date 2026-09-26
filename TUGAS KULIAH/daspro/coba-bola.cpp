#include <bits/stdc++.h>
using namespace std;

const int SIZE = 20;

int main() {
    srand((unsigned)time(nullptr));

    double x = SIZE / 2.0, y = SIZE / 2.0;
    double angle = ((double)rand() / RAND_MAX) * 2 * M_PI;
    double speed = 1.0;
    double vx = speed * cos(angle);
    double vy = speed * sin(angle);

    while (true) {
        x += vx;
        y += vy;

        // pantul di dinding kiri/kanan
        if (x <= 1 || x >= SIZE - 2) {
            vx = -vx;
            double a = ((double)rand() / RAND_MAX - 0.5) * 1.0; // variasi random
            vy += a;
        }
        // pantul di dinding atas/bawah
        if (y <= 1 || y >= SIZE - 2) {
            vy = -vy;
            double a = ((double)rand() / RAND_MAX - 0.5) * 1.0;
            vx += a;
        }
        x = max(1.0, min((double)SIZE - 2, x));
        y = max(1.0, min((double)SIZE - 2, y));

        // normalisasi kecepatan biar besar tetap
        double mag = sqrt(vx * vx + vy * vy);
        vx = vx / mag * speed;
        vy = vy / mag * speed;

        // gambar
        system("cls");
        vector<string> grid(SIZE, string(SIZE, ' '));
        for (int i = 0; i < SIZE; i++)
            grid[0][i] = grid[SIZE-1][i] = grid[i][0] = grid[i][SIZE-1] = '#';
        grid[(int)round(y)][(int)round(x)] = 'O';
        for (auto &r : grid) cout << r << "\n";

        this_thread::sleep_for(chrono::milliseconds(150));
    }
}
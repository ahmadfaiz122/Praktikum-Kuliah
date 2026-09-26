#include <bits/stdc++.h>
using namespace std;

const int SIZE = 20;          // ukuran kotak 20x20
const int MIN_BOUND = 1;      // batas dalam kiri/atas (index 0 = tembok)
const int MAX_BOUND = SIZE - 2; // batas dalam kanan/bawah (index 19 = tembok)

struct Ball {
    double x, y;   // posisi bola (pecahan, biar gerakan halus)
    double vx, vy; // komponen kecepatan (arah + besar)
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// menghasilkan angka acak kecil di rentang [-range, range]
// dipakai supaya pantulan tidak selalu punya sudut yang sama
double randomVariation(double range) {
    double r = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // -1..1
    return r * range;
}

void drawFrame(const Ball &ball, double kecepatan, double kemiringan) {
    vector<string> grid(SIZE, string(SIZE, ' '));

    // gambar tembok di sekeliling kotak
    for (int i = 0; i < SIZE; i++) {
        grid[0][i] = '#';
        grid[SIZE - 1][i] = '#';
        grid[i][0] = '#';
        grid[i][SIZE - 1] = '#';
    }

    int bx = (int)round(ball.x);
    int by = (int)round(ball.y);
    if (bx < 0) bx = 0; if (bx > SIZE - 1) bx = SIZE - 1;
    if (by < 0) by = 0; if (by > SIZE - 1) by = SIZE - 1;
    grid[by][bx] = 'O';

    clearScreen();
    for (auto &row : grid) cout << row << "\n";

    cout << "-------------------------------------------\n";
    cout << "Posisi (x, y)        : (" << ball.x << ", " << ball.y << ")\n";
    cout << "Vektor Kecepatan     : " << kecepatan << "\n";
    cout << "Vektor Kemiringan    : " << kemiringan << "\n";
    cout << "-------------------------------------------\n";
}

int main() {
    srand((unsigned)time(nullptr));

    double kecepatan, kemiringan;
    cout << "=== Simulasi Bola Memantul ===\n";
    cout << "Masukkan besar vektor kecepatan (contoh: 1.0): ";
    cin >> kecepatan;
    cout << "Masukkan kemiringan awal / arah (contoh: 0.5): ";
    cin >> kemiringan;

    double angle = atan(kemiringan);
    Ball ball;
    ball.x = SIZE / 2.0;
    ball.y = SIZE / 2.0;
    ball.vx = kecepatan * cos(angle);
    ball.vy = kecepatan * sin(angle);

    double dt = 1.0;

    while (true) {
        ball.x += ball.vx * dt;
        ball.y += ball.vy * dt;

        bool kena = false;

        // pantulan di dinding kiri/kanan -> vx dibalik
        if (ball.x <= MIN_BOUND) {
            ball.x = MIN_BOUND;
            ball.vx = -ball.vx;
            double relatif = (ball.y - SIZE / 2.0) / (SIZE / 2.0); // -1..1, posisi tumbukan
            ball.vy += randomVariation(0.6) + relatif * 0.4; // titik tumbukan + acak -> sudut beda tiap pantul
            kena = true;
        } else if (ball.x >= MAX_BOUND) {
            ball.x = MAX_BOUND;
            ball.vx = -ball.vx;
            double relatif = (ball.y - SIZE / 2.0) / (SIZE / 2.0);
            ball.vy += randomVariation(0.6) + relatif * 0.4;
            kena = true;
        }

        // pantulan di dinding atas/bawah -> vy dibalik
        if (ball.y <= MIN_BOUND) {
            ball.y = MIN_BOUND;
            ball.vy = -ball.vy;
            double relatif = (ball.x - SIZE / 2.0) / (SIZE / 2.0);
            ball.vx += randomVariation(0.6) + relatif * 0.4;
            kena = true;
        } else if (ball.y >= MAX_BOUND) {
            ball.y = MAX_BOUND;
            ball.vy = -ball.vy;
            double relatif = (ball.x - SIZE / 2.0) / (SIZE / 2.0);
            ball.vx += randomVariation(0.6) + relatif * 0.4;
            kena = true;
        }

        // jaga besar kecepatan tetap sama seperti input awal (energi kekal),
        // hanya arah/kemiringannya yang berubah-ubah tiap pantul
        if (kena) {
            double mag = sqrt(ball.vx * ball.vx + ball.vy * ball.vy);
            if (mag > 0.0001) {
                ball.vx = ball.vx / mag * kecepatan;
                ball.vy = ball.vy / mag * kecepatan;
            }
        }

        double kemiringanSekarang = (ball.vx != 0) ? (ball.vy / ball.vx) : 0;

        drawFrame(ball, kecepatan, kemiringanSekarang);
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    return 0;
}
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Bola {
    float x, y;
    float vx, vy;
    char simbol;
};

const float RADIUS = 1.0f; // radius bola untuk deteksi tabrakan (dalam satuan grid)

void clearScreen() {
    // ANSI escape code, kompatibel Linux/Mac/Windows Terminal modern
    system("cls");
}

// Cek & tangani tabrakan dinding
void pantulDinding(Bola &b, int tinggi, int lebar) {
    if (b.x <= 1) { b.x = 1; b.vx = fabs(b.vx); }
    if (b.x >= lebar - 2) { b.x = lebar - 2; b.vx = -fabs(b.vx); }
    if (b.y <= 1) { b.y = 1; b.vy = fabs(b.vy); }
    if (b.y >= tinggi - 2) { b.y = tinggi - 2; b.vy = -fabs(b.vy); }
}

// Tangani tabrakan antar 2 bola (elastic collision, massa sama)
void pantulAntarBola(Bola &a, Bola &b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dist2 = dx * dx + dy * dy;
    float minDist = RADIUS * 2.0f;

    if (dist2 <= 0.0001f) dist2 = 0.0001f; // hindari pembagian nol
    float dist = sqrt(dist2);

    if (dist < minDist) {
        // --- 1. Pisahkan posisi supaya tidak saling menembus ---
        float overlap = (minDist - dist) / 2.0f;
        float nx = dx / dist;
        float ny = dy / dist;
        a.x -= nx * overlap;
        a.y -= ny * overlap;
        b.x += nx * overlap;
        b.y += ny * overlap;

        // --- 2. Hitung kecepatan relatif ---
        float rvx = a.vx - b.vx;
        float rvy = a.vy - b.vy;

        // hanya proses jika keduanya memang saling mendekat
        float velAlongNormal = rvx * nx + rvy * ny;
        if (velAlongNormal < 0) return; // sudah menjauh, tidak perlu dipantulkan lagi

        // --- 3. Elastic collision massa sama (tukar komponen kecepatan sepanjang garis normal) ---
        float impulse = velAlongNormal; // massa sama -> impulse sederhana
        a.vx -= impulse * nx;
        a.vy -= impulse * ny;
        b.vx += impulse * nx;
        b.vy += impulse * ny;
    }
}

int main() {
    srand((unsigned) time(0));

    int tinggi = 30;
    int lebar = 100;
    int jumlahBola = 20;
    int maxFrame = 2000;

    vector<Bola> bola(jumlahBola);

    // daftar simbol unik untuk 20 bola
    string daftarSimbol = "0123456789ABCDEFGHIJ";

    // Inisialisasi posisi & kecepatan acak, hindari tumpang tindih awal
    for (int i = 0; i < jumlahBola; i++) {
        bool valid;
        do {
            valid = true;
            bola[i].x = 2 + rand() % (lebar - 4);
            bola[i].y = 2 + rand() % (tinggi - 4);

            for (int j = 0; j < i; j++) {
                float dx = bola[i].x - bola[j].x;
                float dy = bola[i].y - bola[j].y;
                if (sqrt(dx * dx + dy * dy) < RADIUS * 2.0f) {
                    valid = false;
                    break;
                }
            }
        } while (!valid);

        // kecepatan acak berbeda-beda, arah acak, magnitude 0.5 - 2.0
        float sudut = ((float) rand() / RAND_MAX) * 2.0f * M_PI;
        float speed = 0.5f + ((float) rand() / RAND_MAX) * 1.5f;
        bola[i].vx = cos(sudut) * speed;
        bola[i].vy = sin(sudut) * speed;

        bola[i].simbol = daftarSimbol[i % daftarSimbol.size()];
    }

    for (int frame = 1; frame <= maxFrame; frame++) {
        clearScreen();

        // 1. Update posisi tiap bola
        for (int i = 0; i < jumlahBola; i++) {
            bola[i].x += bola[i].vx;
            bola[i].y += bola[i].vy;
            pantulDinding(bola[i], tinggi, lebar);
        }

        // 2. Cek tabrakan antar semua pasangan bola
        for (int i = 0; i < jumlahBola; i++) {
            for (int j = i + 1; j < jumlahBola; j++) {
                pantulAntarBola(bola[i], bola[j]);
            }
        }

        // 3. Gambar kotak dan semua bola
        for (int y = 0; y < tinggi; y++) {
            for (int x = 0; x < lebar; x++) {
                if (y == 0 || y == tinggi - 1 || x == 0 || x == lebar - 1) {
                    cout << "#";
                    continue;
                }

                bool adaBola = false;
                for (int i = 0; i < jumlahBola; i++) {
                    if ((int) round(bola[i].x) == x && (int) round(bola[i].y) == y) {
                        cout << bola[i].simbol;
                        adaBola = true;
                        break;
                    }
                }

                if (!adaBola) cout << " ";
            }
            cout << "\n";
        }
        cout.flush();

        usleep(30000); // delay animasi 40.000 mikrodetik = 40 milidetik = 0,04 detik.\(\text{FPS} = \frac{1}{\text{durasi per frame (detik)}} = \frac{1}{0,04} = \mathbf{25\text{ FPS}}\).
    }

    return 0;
}
#include <iostream>
#include <unistd.h>
#include <cmath>

using namespace std;


int main(){
    int tinggi = 15;
    int lebar = 40;
    float posX = 20;
    float posY = 7;
    float vx = 1;
    float vy = 1;
    int maxFrame = 300;

    for (int frame = 1; frame <= maxFrame; frame++) {
        // Clear screen
        system("cls");

        // Update position
        posX += vx;
        posY += vy;

        // Check for collision with walls
        if (posX <= 1 || posX >= lebar - 2) {
            vx = -vx; // Reverse X velocity
        }
        if (posY <= 1 || posY >= tinggi - 2) {
            vy = -vy; // Reverse Y velocity
        }

        // Draw the box and the ball
        for (int y = 0; y < tinggi; y++) {
            for (int x = 0; x < lebar; x++) {
                if (y == 0 || y == tinggi - 1 || x == 0 || x == lebar - 1) {
                    cout << "#"; // Draw walls
                } else if ((int)round(posX) == x && (int)round(posY) == y) {
                    cout << "O"; // Draw ball
                } else {
                    cout << " "; // Empty space
                }
            }
            cout << endl;
        }

        usleep(100000); // Delay for smooth animation
    }
}


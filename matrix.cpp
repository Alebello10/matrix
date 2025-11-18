#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int WIDTH = 80;
const int HEIGHT = 25;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H"; // ANSI escape code per pulire il terminale
#endif
}

int main() {
    srand(time(nullptr));
    vector<int> drops(WIDTH, 0);

    while (true) {
        clearScreen();

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if (drops[x] == y) {
                    cout << "\033[32m" << char(33 + rand() % 94) << "\033[0m"; // verde stile Matrix
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 0; i < WIDTH; ++i) {
            if (rand() % 100 < 10) {
                drops[i] = 0; // reset drop
            } else {
                drops[i]++;
                if (drops[i] >= HEIGHT) drops[i] = HEIGHT;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}

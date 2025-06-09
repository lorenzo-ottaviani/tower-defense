/*
* Author : Lorenzo OTTAVIANI.
* Date : 10/06/2025 00h27
* Aim of the program :
*    Tower defense game.
* Input : ∅
* Output : Sea tower help us to stop enemies!
*/

#include <iostream>

#include "enemy_wave.hpp"

void printWave(int waveNumber, const EnemyWave& wave, int total) {
    std::cout << "Wave " << waveNumber << " (Total: " << total << "):\n";
    std::cout << "  Tourist:  " << wave.tourist << '\n';
    std::cout << "  Fishing:  " << wave.fishing << '\n';
    std::cout << "  JetSki:   " << wave.jetSki << '\n';
    std::cout << "  Tanker:   " << wave.tanker << '\n';
    std::cout << "  Yacht:    " << wave.yacht << '\n';
    std::cout << "  Cruise:   " << wave.cruise << "\n\n";
}

int main() {
    int previousTotal = 10;

    for (int i = 1; i <= 10; ++i) {
        EnemyWave wave = generateWave(i, previousTotal);

        int currentTotal = wave.tourist + wave.fishing + wave.jetSki +
                           wave.tanker + wave.yacht + wave.cruise;

        printWave(i, wave, currentTotal);

        previousTotal = currentTotal;
    }

    return 0;
}

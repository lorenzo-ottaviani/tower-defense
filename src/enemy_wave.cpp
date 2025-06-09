#include "enemy_wave.hpp"

EnemyWave generateWave(int waveNumber, int previousTotal) {
    int total = static_cast<int>(previousTotal * 1.3 + 5);

    EnemyWave wave = {0};

    if (waveNumber >= 1) {
        wave.tourist = total * 0.4;
        wave.fishing = total * 0.3;
    }
    if (waveNumber >= 2) wave.jetSki = total * 0.2;
    if (waveNumber >= 4) wave.tanker = total * 0.15;
    if (waveNumber >= 6) wave.yacht = total * 0.1;
    if (waveNumber >= 8) wave.cruise = total * 0.05;

    int sum = wave.tourist + wave.fishing + wave.jetSki + wave.tanker + wave.yacht + wave.cruise;
    int diff = total - sum;
    wave.tourist += diff; // Adjust to match the exact total

    return wave;
}

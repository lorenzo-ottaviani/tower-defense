# pragma once

struct EnemyWave {
    int tourist;
    int fishing;
    int jetSki;
    int tanker;
    int yacht;
    int cruise;
};

EnemyWave generateWave(int waveNumber, int previousTotal);

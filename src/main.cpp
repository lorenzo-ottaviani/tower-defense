/*
* Authors : Samy BELAZZOUG, Laurent CASSAR, Lorenzo OTTAVIANI and Leila WILDE.
* Date : 12/06/2025 20h08
* Aim of the program :
*    Tower defense game.
* Input : ∅
* Output : Sea tower help us to stop enemies!
*/

#include <iostream>
#include <string>

#include "models\enemy.hpp"
#include "models\enemy_factory.hpp"
#include "enemy_wave.hpp"
#include "models\tower.hpp"
#include "models\tower_factory.hpp"

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

	std::cout << std::endl;
	std::unique_ptr<Tower> tower_test = TowerFactory::createTower("Sandcastle");
	tower_test->display_information();
	std::cout << std::endl;


	std::unique_ptr<Enemy> enemy_test = EnemyFactory::createEnemy("OilTanker");
    enemy_test->display_information();
	std::cout << std::endl;

    for (int i = 1; i <= 10; ++i) {
        EnemyWave wave = generateWave(i, previousTotal);

        int currentTotal = wave.tourist + wave.fishing + wave.jetSki +
                           wave.tanker + wave.yacht + wave.cruise;

        printWave(i, wave, currentTotal);

        previousTotal = currentTotal;
    }

    return 0;
}

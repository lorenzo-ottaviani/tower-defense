#include <chrono>
#include <iostream>
#include <string>

#include "models/tower.hpp"

/**
 * @brief Displays information about a Sandcastle Tower.
 *
 * Prints the tower's stats to the terminal.
 */
void SandcastleTower::display_information() {
	std::cout << "SANDCASTLE TOWER" << std::endl;
    std::cout << "Level : " << level_name << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "RPM : " << rpm << std::endl;
    std::cout << "Cost : " << cost << std::endl;
}

/**
 * @brief Change the Sandcastle Tower level and update its stats accordingly.
 *
 * @param new_level The new level to apply to the tower.
 */
void SandcastleTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Solar Prism";
        this->attack_power = 25;
        this->range = 5.0;
        this->rpm = 40;
        this->cost = 100;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Solar Beam";
        this->attack_power = 60;
        this->range = 4.5;
        this->rpm = 20;
        this->cost = 120;
    }
}

/**
 * @brief Displays information about a Clam Tower.
 *
 * Prints the tower's stats to the terminal.
 */
void ClamTower::display_information() {
	std::cout << "CLAM TOWER" << std::endl;
    std::cout << "Level : " << level_name << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "RPM : " << rpm << std::endl;
    std::cout << "Cost : " << cost << std::endl;
}

/**
 * @brief Change the Clam Tower level and update its stats accordingly.
 *
 * @param new_level The new level to apply to the tower.
 */
void ClamTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Tide Clam";
        this->attack_power = 45;
        this->range = 3.5;
        this->rpm = 20;
        this->cost = 110;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Echo Clam";
        this->attack_power = 40;
        this->range = 3.0;
        this->rpm = 15;
        this->cost = 130;
    }
}

/**
 * @brief Displays information about a Algae Bed Tower.
 *
 * Prints the tower's stats to the terminal.
 */
void AlgaeBedTower::display_information() {
	std::cout << "ALGAE BED TOWER" << std::endl;
    std::cout << "Level : " << level_name << std::endl;
    std::cout << "Slow effect : " << slow_percentage << "for " << slow_time << "s" << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "Cost : " << cost << std::endl;
}

/**
 * @brief Change the Algae Bed Tower level and update its stats accordingly.
 *
 * @param new_level The new level to apply to the tower.
 */
void AlgaeBedTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Kelp Forest";
        this->range = 3.0;
        this->slow_time = 3;
        this->slow_percentage = 0.5;
        this->cost = 90;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Sticky Algae";
        this->range = 2.5;
        this->slow_time = 4;
        this->slow_percentage = 0.6;
        this->cost = 100;
    }
}

/**
 * @brief Displays information about a Jellyfish Nest Tower.
 *
 * Prints the tower's stats to the terminal.
 */
void JellyfishNestTower::display_information() {
	std::cout << "JELLYFISH NEST TOWER" << std::endl;
    std::cout << "Level : " << level_name << std::endl;
    std::cout << "Attack : " << attack_power << "for " << attack_time << "s" << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "RPM : " << rpm << std::endl;
    std::cout << "Cost : " << cost << std::endl;
}

/**
 * @brief Change the Jellyfish Nest Tower level and update its stats accordingly.
 *
 * @param new_level The new level to apply to the tower.
 */
void JellyfishNestTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Toxic Bloom";
        this->attack_power = 12;
        this->attack_time = 4;
        this->range = 4.0;
        this->rpm = 12;
        this->cost = 120;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Neuro Sting";
        this->attack_power = 15;
        this->attack_time = 5;
        this->range = 3.5;
        this->rpm = 10;
        this->cost = 130;
    }
}

/**
 * @brief Displays information about a Octopus Tower.
 *
 * Prints the tower's stats to the terminal.
 */
void OctopusTower::display_information() {
	std::cout << "OCTOPUS TOWER" << std::endl;
    std::cout << "Level : " << level_name << std::endl;
    std::cout << "Attack : kill the enemy !" << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "RPM : " << rpm << std::endl;
    std::cout << "Cost : " << cost << std::endl;
}

/**
 * @brief Change the Octopus Tower level and update its stats accordingly.
 *
 * @param new_level The new level to apply to the tower.
 */
void OctopusTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Kraken Jr.";
        this->range = 3.0;
        this->rpm = 8;
        this->cost = 160;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Tentacle Horror";
        this->range = 3.5;
        this->rpm = 6;
        this->cost = 180;
    }
}

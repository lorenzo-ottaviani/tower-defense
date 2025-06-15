#include <iostream>

#include "models/enemy.hpp"

/**
 * @brief Displays information about the Tourist Boat.
 *
 * Prints the enemy's stats to the terminal.
 */
void TouristBoat::display_information() {
    std::cout << "TOURIST BOAT" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

/**
 * @brief Displays information about the Fishing Boat.
 *
 * Prints the enemy's stats to the terminal.
 */
void FishingBoat::display_information() {
    std::cout << "FISHING BOAT" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

/**
 * @brief Displays information about the Jetski.
 *
 * Prints the enemy's stats to the terminal.
 */
void Jetski::display_information() {
    std::cout << "JETSKI" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

/**
 * @brief Displays information about the Oil Tanker.
 *
 * Prints the enemy's stats to the terminal.
 */
void OilTanker::display_information() {
    std::cout << "OIL TANKER" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

/**
 * @brief Displays information about the Yacht.
 *
 * Prints the enemy's stats to the terminal.
 */
void Yacht::display_information() {
    std::cout << "YACHT" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

/**
 * @brief Displays information about the Cruise Ship.
 *
 * Prints the enemy's stats to the terminal.
 */
void CruiseShip::display_information() {
    std::cout << "CRUISE SHIP" << std::endl;
    std::cout << "Attack : " << attack_power << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "HP : " << hp << std::endl;
}
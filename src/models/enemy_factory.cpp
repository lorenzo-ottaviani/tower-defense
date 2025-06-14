#include <memory>
#include <stdexcept>

#include "models/enemy.hpp"
#include "models/enemy_factory.hpp"

std::unique_ptr<Enemy> EnemyFactory::createEnemy(const std::string& type) {
    if (type == "TouristBoat") {
        return std::make_unique<TouristBoat>();
    } else if (type == "FishingBoat") {
        return std::make_unique<FishingBoat>();
    } else if (type == "Jetski") {
        return std::make_unique<Jetski>();
    } else if (type == "OilTanker") {
        return std::make_unique<OilTanker>();
    } else if (type == "Yacht") {
        return std::make_unique<Yacht>();
    } else if (type == "CruiseShip") {
        return std::make_unique<CruiseShip>();
    } else {
        throw std::invalid_argument("Unknown enemy type: " + type);
    }
}


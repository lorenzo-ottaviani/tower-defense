#include <memory>
#include <stdexcept>

#include "models/tower.hpp"
#include "models/tower_factory.hpp"

// Create and return a tower object based on the specified type.
std::unique_ptr<Tower> TowerFactory::createTower(const std::string& type) {
    if (type == "Sandcastle") {
        return std::make_unique<SandcastleTower>();
    } else if (type == "Clam") {
        return std::make_unique<ClamTower>();
    } else if (type == "AlgaeBed") {
        return std::make_unique<AlgaeBedTower>();
    } else if (type == "JellyfishNest") {
        return std::make_unique<JellyfishNestTower>();
    } else if (type == "Octopus") {
        return std::make_unique<OctopusTower>();
    } else {
        throw std::invalid_argument("Unknown tower type: " + type);
    }
}

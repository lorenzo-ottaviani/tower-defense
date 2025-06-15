#pragma once

#include <memory>

/**
 * @brief Factory class for creating tower objects.
 *
 * Used to construct instances of different types of towers.
 */
class TowerFactory {
public:
    /**
     * @brief Creates a tower object of the specified type.
     *
     * @param type The type of tower to create.
     * @return A unique pointer to the newly created Tower object.
     */
    static std::unique_ptr<Tower> createTower(const std::string& type);
};

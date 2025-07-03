#pragma once

#include <memory>

/**
 * @brief Factory class for creating enemy objects.
 *
 * Used to construct instances of different types of enemies.
 */
class EnemyFactory {
public:
    /**
     * @brief Creates an enemy object of the specified type.
     *
     * @param type The type of enemy to create.
     * @return A unique pointer to the newly created Enemy object.
     */
    static std::unique_ptr<Enemy> createEnemy(const std::string& type);
};

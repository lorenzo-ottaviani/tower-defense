#pragma once

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy(const std::string& type);
};

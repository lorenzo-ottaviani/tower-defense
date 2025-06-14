#pragma once

#include <memory>

class TowerFactory {
public:
    static std::unique_ptr<Tower> createTower(const std::string& type);
};

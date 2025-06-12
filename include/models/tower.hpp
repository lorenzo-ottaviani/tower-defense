#pragma once

#include <chrono>
#include <string>

class Tower {
public:
    virtual ~Tower() = default;
    virtual void changeLevel(int new_level) = 0;
    virtual void attack() = 0;
};

class SandcastleTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 20;
    double range = 4.0;
    double rpm = 30;
    std::string effect_type = "Direct Damage";
    int cost = 50;

public:
    ~SandcastleTower() = default;
    void changeLevel(int new_level) override;
    void attack() override;
};

class ClamTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 40;
    double range = 3.0;
    double rpm = 15;
    std::string effect_type = "Area Damage";
    int cost = 60;

public:
    ~ClamTower() = default;
    void changeLevel(int new_level) override;
    void attack() override;
};

class AlgaeBedTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    double range = 2.5;
    std::chrono::seconds slow_time = 2;
    double slow_percentage = 0.4;
    std::string effect_type = "Slow Down";
    int cost = 40;

public:
    ~AlgaeBedTower() = default;
    void changeLevel(int new_level) override;
    void attack() override;
};

class JellyfishNestTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 10;
    std::chrono::seconds attack_time = 3;
    double range = 3.5;
    double rpm = 10;
    std::string effect_type = "Poison Damage";
    int cost = 70;

public:
    ~JellyfishNestTower() = default;
    void changeLevel(int new_level) override;
    void attack() override;
};

class OctopusTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    double range = 2.5;
    double rpm = 6;
    std::string effect_type = "Instant Kill";
    int cost = 100;

public:
    ~OctopusTower() = default;
    void changeLevel(int new_level) override;
    void attack() override;
};

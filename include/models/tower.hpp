#pragma once

#include <chrono>
#include <string>

/**
 * @brief Abstract base class for all tower types.
 *
 * Defines the common interface and structure for all tower variants.
 */
class Tower {
public:
    virtual ~Tower() = default;
	/**
     * @brief Display information about the tower.
     */
    virtual void display_information() = 0;
	/**
     * @brief Change the tower's level and update its stats accordingly.
     *
     * @param new_level The new level to apply to the tower.
     */
    virtual void changeLevel(int new_level) = 0;
    // virtual void attack() = 0;
};

/**
 * @brief A basic tower made of sand, dealing direct damage.
 */
class SandcastleTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 20;
    double range = 4.0;
    double rpm = 30;
    std::string effect_type = "Direct Damage";
    int cost = 50;
	// image
	// sound

public:
    ~SandcastleTower() = default;
    void display_information() override;
    void changeLevel(int new_level) override;
    // void attack() override;
};

/**
 * @brief A clam-shaped tower that deals area damage.
 */
class ClamTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 40;
    double range = 3.0;
    double rpm = 15;
    std::string effect_type = "Area Damage";
    int cost = 60;
	// image
	// sound

public:
    ~ClamTower() = default;
    void display_information() override;
    void changeLevel(int new_level) override;
    // void attack() override;
};

/**
 * @brief A tower that slows down enemies in its range.
 */
class AlgaeBedTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    double range = 2.5;
    int slow_time = 2;
    double slow_percentage = 0.4;
    std::string effect_type = "Slow Down";
    int cost = 40;
	// image
	// sound

public:
    ~AlgaeBedTower() = default;
    void display_information() override;
    void changeLevel(int new_level) override;
	// void attack() override;
    // std::chrono::seconds slow_down();
};

/**
 * @brief A jellyfish tower applying poison damage over time.
 */
class JellyfishNestTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    int attack_power = 10;
    int attack_time = 3;
    double range = 3.5;
    double rpm = 10;
    std::string effect_type = "Poison Damage";
    int cost = 70;
	// image
	// sound

public:
    ~JellyfishNestTower() = default;
    void display_information() override;
    void changeLevel(int new_level) override;
    // void attack() override;
};

/**
 * @brief A powerful tower capable of instantly eliminating enemies.
 */
class OctopusTower : public Tower {
private:
    int level = 1;
    std::string level_name = "Base";
    double range = 2.5;
    double rpm = 6;
    std::string effect_type = "Instant Kill";
    int cost = 100;
	// image
	// sound

public:
    ~OctopusTower() = default;
    void display_information() override;
    void changeLevel(int new_level) override;
    // void attack() override;
};

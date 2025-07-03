#pragma once

/**
 * @brief Abstract base class for all enemy types.
 *
 * Defines the common interface and structure for all enemy variants.
 */
class Enemy {
public:
    virtual ~Enemy() = default;
    /**
     * @brief Display information about the enemy.
     */
    virtual void display_information() = 0;
    // virtual void attack() = 0;
    // virtual void isDead() = 0;
    // virtual void move() =0;
    // virtual void spawn() = 0;
};

/**
 * @brief A basic tourist boat enemy.
 *
 * A major tour operator sends its first tourists to pollute our little corner of paradise.
 */
class TouristBoat : public Enemy {
private:
    int hp = 50;
    int attack_power = 1;
    double speed = 1.4;
	// image
	// sound

public:
    ~TouristBoat() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

/**
 * @brief A boat used for industrial fishing.
 *
 * The Crazy Tuna Company is dredging the lagoon to plunder all its marine resources.
 */
class FishingBoat : public Enemy {
    private:
    int hp = 100;
    int attack_power = 2;
    double speed = 1.0;
	// image
	// sound

    public:
    ~FishingBoat() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

/**
 * @brief A fast and noisy jetski enemy.
 *
 * A horde of jetskis pollutes our turquoise waters and drowns us in their incessant noise.
 */
class Jetski : public Enemy {
    private:
    int hp = 30;
    int attack_power = 1;
    double speed = 1.8;
	// image
	// sound

    public:
    ~Jetski() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

/**
 * @brief A massive oil tanker enemy.
 *
 * An oil company dares to enter our lagoon to install its new XXL petrolarium platform.
 */
class OilTanker : public Enemy {
    private:
    int hp = 300;
    int attack_power = 4;
    double speed = 1.0;
	// image
	// sound

    public:
    ~OilTanker() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

/**
 * @brief A next-generation luxury yacht.
 *
 * The ultrarich have arrived to contaminate our little corner of paradise.
 */
class Yacht : public Enemy {
    private:
    int hp = 150;
    int attack_power = 3;
    double speed = 1.4;
	// image
	// sound

    public:
    ~Yacht() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

/**
 * @brief A colossal cruise ship.
 *
 * Tour operators are no longer content with jet skis—they now dock cruise ships directly in our lagoon.
 */
class CruiseShip : public Enemy {
    private:
    int hp = 600;
    int attack_power = 6;
    double speed = 0.6;
	// image
	// sound

    public:
    ~CruiseShip() = default;
    void display_information() override;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};
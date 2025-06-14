#pragma once

class Enemy {
public:
    virtual ~Enemy() = default;
    // virtual void attack() = 0;
    // virtual void isDead() = 0;
    // virtual void move() =0;
    // virtual void spawn() = 0;
};

class TouristBoat : public Enemy {
private:
    int hp = 50;
    int attack_power = 1;
    double speed = 1.4;
	// image
	// sound

public:
    ~TouristBoat() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

class FishingBoat : public Enemy {
    private:
    int hp = 100;
    int attack_power = 2;
    double speed = 1.0;
	// image
	// sound

    public:
    ~FishingBoat() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

class Jetski : public Enemy {
    private:
    int hp = 30;
    int attack_power = 1;
    double speed = 1.8;
	// image
	// sound

    public:
    ~Jetski() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

class OilTanker : public Enemy {
    private:
    int hp = 300;
    int attack_power = 4;
    double speed = 1.0;
	// image
	// sound

    public:
    ~OilTanker() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

class Yacht : public Enemy {
    private:
    int hp = 150;
    int attack_power = 3;
    double speed = 1.4;
	// image
	// sound

    public:
    ~Yacht() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};

class CruiseShip : public Enemy {
    private:
    int hp = 600;
    int attack_power = 6;
    double speed = 0.6;
	// image
	// sound

    public:
    ~CruiseShip() = default;
    // void attack() override;
    // void isDead() override;
    // void move() override;
    // void spawn() override;
};
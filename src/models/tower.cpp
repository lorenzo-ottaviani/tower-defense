#include <chrono>
#include <string>

#include "tower.hpp"

void SandcastleTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Solar Prism";
        this->attack_power = 25;
        this->range = 5.0;
        this->rpm = 40;
        this->cost = 100;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Solar Beam";
        this->attack_power = 60;
        this->range = 4.5;
        this->rpm = 20;
        this->cost = 120;
    }
}

void ClamTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Tide Clam";
        this->attack_power = 45;
        this->range = 3.5;
        this->rpm = 20;
        this->cost = 110;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Echo Clam";
        this->attack_power = 40;
        this->range = 3.0;
        this->rpm = 15;
        this->cost = 130;
    }
}

void AlgaeBedTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Kelp Forest";
        this->range = 3.0;
        this->slow_time = 3;
        this->slow_percentage = 0.5;
        this->cost = 90;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Sticky Algae";
        this->range = 2.5;
        this->slow_time = 4;
        this->slow_percentage = 0.6;
        this->cost = 100;
    }
}

void JellyfishNest::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Toxic Bloom";
        this->attack_power = 12;
        this->attack_time = 4;
        this->range = 4.0;
        this->rpm = 12;
        this->cost = 120;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Neuro Sting";
        this->attack_power = 15;
        this->attack_time = 5;
        this->range = 3.5;
        this->rpm = 10;
        this->cost = 130;
    }
}

void OctopusTower::changeLevel(int new_level) {
    if (new_level == 2) {
        this->level = 2;
        this->level_name = "Kraken Jr.";
        this->range = 3.0;
        this->rpm = 8;
        this->cost = 160;
    } else if (new_level == 3) {
        this->level = 3;
        this->level_name = "Tentacle Horror";
        this->range = 3.5;
        this->rpm = 6;
        this->cost = 180;
    }
}

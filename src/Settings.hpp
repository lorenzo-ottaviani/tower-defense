#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class Settings : public Screen {
public:
    Settings(sf::RenderWindow& window);
    void handleInput(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
};

#endif // SETTINGS_HPP

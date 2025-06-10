#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class Credits : public Screen {
public:
    Credits(sf::RenderWindow& window);
    void handleInput(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;

    
};

#endif // CREDITS_HPP
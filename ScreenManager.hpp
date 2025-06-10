#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Screen.hpp"

class ScreenManager {
public:
    // Push a new screen onto the stack
    void pushScreen(std::unique_ptr<Screen> screen);

    // Pop the current screen from the stack
    void popScreen();

    // Handle input for the current screen
    void handleInput(sf::Event& event);

    // Update the current screen
    void update();

    // Draw the current screen
    void draw(sf::RenderWindow& window);

private:
    std::vector<std::unique_ptr<Screen>> screens; // Stack of screens
};

#endif // SCREEN_MANAGER_HPP

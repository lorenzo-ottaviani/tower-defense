#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenManager.hpp"
#include "MainMenu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Sea vs Humans");
    window.setFramerateLimit(60);

    ScreenManager screenManager;
    screenManager.pushScreen(std::make_unique<MainMenu>(window));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            screenManager.handleInput(event);
        }

        screenManager.update();

        window.clear();
        screenManager.draw(window);
        window.display();
    }

    return 0;
}

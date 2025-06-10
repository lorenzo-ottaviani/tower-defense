#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <functional>
#include "Screen.hpp"

// Struct to hold a text button and its shadow
struct TextButton {
    sf::Text text;
    sf::Text shadow;
    std::function<void()> onClick;
};

class MainMenu : public Screen {
public:
    MainMenu(sf::RenderWindow& window);
    void handleInput(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    sf::Sprite background;
    sf::Sprite logo;
    sf::Font font;
    std::vector<TextButton> buttons;

    void initializeButtons();
    void loadAssets();
};

#endif // MAIN_MENU_HPP
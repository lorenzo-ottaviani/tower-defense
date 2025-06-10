#include "ScreenManager.hpp"
#include <Screen.hpp>

class ScreenManager {
public:
    void pushScreen(std::unique_ptr<Screen> screen) {
        screens.push_back(std::move(screen));
    }

    void popScreen() {
        if (!screens.empty()) {
            screens.pop_back();
        }
    }

    void handleInput(sf::Event& event) {
        if (!screens.empty()) {
            screens.back()->handleInput(event);
        }
    }

    void update() {
        if (!screens.empty()) {
            screens.back()->update();
        }
    }

    void draw(sf::RenderWindow& window) {
        if (!screens.empty()) {
            screens.back()->draw(window);
        }
    }

private:
    std::vector<std::unique_ptr<Screen>> screens;
};

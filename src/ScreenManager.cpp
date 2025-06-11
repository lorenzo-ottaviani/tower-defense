#include "ScreenManager.hpp"

void ScreenManager::pushScreen(std::unique_ptr<Screen> screen) {
    screens.push_back(std::move(screen));
}

void ScreenManager::popScreen() {
    if (!screens.empty()) {
        screens.pop_back();
    }
}

void ScreenManager::handleInput(sf::Event& event) {
    if (!screens.empty()) {      
        screens.back()->handleInput(event);
    }
}

void ScreenManager::update() {
    if (!screens.empty()) {
        screens.back()->update();
    }
}

void ScreenManager::draw(sf::RenderWindow& window) {
    if (!screens.empty()) {
        screens.back()->draw(window);
    }
}
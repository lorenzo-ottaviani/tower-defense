#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& window) : window(window) {
    loadAssets();
    initializeButtons();
}

void MainMenu::loadAssets() {
    // Load background image
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("assets/images/background.png")) {
        std::cerr << "Error loading background.png\n";
        throw std::runtime_error("Failed to load background image");
    }
    background.setTexture(bgTexture);

    // Load logo
    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("assets/images/logo.png")) {
        std::cerr << "Error loading logo.png\n";
        throw std::runtime_error("Failed to load logo image");
    }
    logo.setTexture(logoTexture);
    logo.setPosition((window.getSize().x - logo.getGlobalBounds().width) / 2.f, 1.f);

    // Load font
    if (!font.loadFromFile("assets/fonts/zing.rust-demo-base.otf")) {
        std::cerr << "Error loading zing.rust-demo-base.otf\n";
        throw std::runtime_error("Failed to load font");
    }
}

void MainMenu::initializeButtons() {
    std::vector<std::string> labels = { "Play", "How to Play", "Settings", "Credits" };
    float buttonYStart = logo.getPosition().y + 300.f;
    float spacing = 100.f;

    for (size_t i = 0; i < labels.size(); ++i) {
        TextButton btn;

        // Shadow (drawn first, slightly offset)
        btn.shadow.setFont(font);
        btn.shadow.setString(labels[i]);
        btn.shadow.setCharacterSize(72);
        btn.shadow.setFillColor(sf::Color(0, 0, 0, 150)); // semi-transparent black

        // Main text
        btn.text.setFont(font);
        btn.text.setString(labels[i]);
        btn.text.setCharacterSize(72);
        btn.text.setFillColor(sf::Color::White);

        // Center horizontally
        float x = (window.getSize().x - btn.text.getGlobalBounds().width) / 2.f;
        float y = buttonYStart + i * spacing;

        btn.shadow.setPosition(x + 2, y + 2);
        btn.text.setPosition(x, y);

        // assign a simple click handler
        if (labels[i] == "Play") {
            btn.onClick = []() { std::cout << "Play clicked\n"; };
        } else if (labels[i] == "Settings") {
            btn.onClick = []() { std::cout << "Settings clicked\n"; };
        } else if (labels[i] == "Credits") {
            btn.onClick = []() { std::cout << "Credits clicked\n"; };
        }

        buttons.push_back(btn);
    }
}

void MainMenu::handleInput(sf::Event& event) {
    // Handle input for the main menu
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

        // Check each button for clicks
        for (auto& btn : buttons) {
            if (btn.text.getGlobalBounds().contains(mousePos)) {
                btn.onClick();
            }
        }
    }
}

void MainMenu::update() {
    // Update logic for the main menu (if needed)
}

void MainMenu::draw(sf::RenderWindow& window) {
    // Draw the background, logo, and buttons
    window.clear();
    window.draw(background);
    window.draw(logo);

    // Draw each button
    for (auto& btn : buttons) {
        window.draw(btn.shadow); // Draw the shadow first
        window.draw(btn.text); // Draw the main text
    }

    window.display();
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <functional>  


// struct to hold a text button and its shadow
struct TextButton {
    sf::Text text;
    sf::Text shadow;
    std::function<void()> onClick;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Sea vs Humans");
    window.setFramerateLimit(60);

    // load background image
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("assets/images/background.png")) {
        std::cerr << "Error loading background.png\n";
        return -1;
    }
    sf::Sprite background(bgTexture);


    // compute scale factors for X and Y separately
    auto winSize = window.getSize();
    auto texSize = bgTexture.getSize();

    float scaleX = float(winSize.x) / float(texSize.x);
    float scaleY = float(winSize.y) / float(texSize.y);

    // scale background to fill window
    background.setScale(scaleX, scaleY);

    // load logo
    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("assets/images/logo.png")) {
        std::cerr << "Error loading logo.png\n";
        return -1;
    }
    sf::Sprite logo(logoTexture);
    // Center logo at top
    logo.setPosition(
        (window.getSize().x - logo.getGlobalBounds().width) / 2.f, 1.f
    );

    // load font
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/zing.rust-demo-base.otf")) {
        std::cerr << "Error loading zing.rust-demo-base.otf\n";
        return -1;
    }

    // buttons
    std::vector<TextButton> buttons;
    std::vector<std::string> labels = { "Play", "How to Play", "Settings", "Credits"};
    float buttonYStart = logo.getPosition().y + 300.f;
    float spacing = 100.f;

    for (size_t i = 0; i < labels.size(); ++i) {
        TextButton btn;

        // Shadow (drawn first, slightly offset)
        btn.shadow.setFont(font);
        btn.shadow.setString(labels[i]);
        btn.shadow.setCharacterSize(72);
        btn.shadow.setFillColor(sf::Color(0, 0, 0, 150)); // semi-transparent black
        // main text
        btn.text.setFont(font);
        btn.text.setString(labels[i]);
        btn.text.setCharacterSize(72);
        btn.text.setFillColor(sf::Color::White);

        // center horizontally
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

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse click handling
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos(
                    static_cast<float>(event.mouseButton.x),
                    static_cast<float>(event.mouseButton.y)
                );

                // Check each button
                for (auto &btn : buttons) {
                    if (btn.text.getGlobalBounds().contains(mousePos)) {
                        btn.onClick();
                    }
                }
            }
        }

        // Draw everything
        window.clear();
        window.draw(background);
        window.draw(logo);
        for (auto &btn : buttons) {
            window.draw(btn.shadow);
            window.draw(btn.text);
        }
        window.display();
    }

    return 0;
}

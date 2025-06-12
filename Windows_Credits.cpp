#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Crédits", sf::Style::Close);
    window.setFramerateLimit(60);

    // Police
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }

    // Image de fond
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("./background.jpg")) {
        return -1;
    }
    sf::Sprite background(bgTexture);

    // Musique de fond
    sf::Music music;
    if (music.openFromFile("musique.ogg")) {
        music.setLoop(true);
        music.play();
    }

    // Liste des crédits
    std::vector<std::string> credits = {
        "Leila Wilde - Chef de projet",
        "Lorenzo Ottaviani",
        "Samy Belazzoug",
        "Laurent CASSAR"
    };

    // Création des textes
    std::vector<sf::Text> creditTexts;
    float startY = window.getSize().y;
    for (size_t i = 0; i < credits.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(credits[i]);
        text.setCharacterSize(28);
        text.setFillColor(sf::Color::White);
        text.setPosition(150, startY + i * 60);
        creditTexts.push_back(text);
    }

    // Bouton Quitter
    sf::Text quitButton;
    quitButton.setFont(font);
    quitButton.setString("Quitter");
    quitButton.setCharacterSize(24);
    quitButton.setFillColor(sf::Color::Red);
    quitButton.setPosition(window.getSize().x - 120, window.getSize().y - 50);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Gestion du clic sur le bouton "Quitter"
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (quitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(background);

        // Mise à jour du texte
        for (auto& text : creditTexts) {
            text.move(0, -0.8f);  // Vitesse lente
            window.draw(text);
        }

        window.draw(quitButton);
        window.display();

        // Fermeture automatique après le défilement
        if (creditTexts.back().getPosition().y < -50)
            window.close();
    }

    return 0;
}

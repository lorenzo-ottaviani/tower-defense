#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Variables globales pour gérer le plein écran
bool isFullscreen = false;
sf::VideoMode windowedMode(800, 600);
sf::VideoMode fullscreenMode = sf::VideoMode::getDesktopMode();

// Fonction pour basculer entre fenêtré et plein écran
void toggleFullscreen(sf::RenderWindow& window) {
    isFullscreen = !isFullscreen;
    
    if (isFullscreen) {
        window.create(fullscreenMode, "Crédits", sf::Style::Fullscreen);
    } else {
        window.create(windowedMode, "Crédits", sf::Style::Close);
    }
    
    window.setFramerateLimit(60);
}

// Fonction pour repositionner les éléments selon la taille de l'écran
void repositionElements(sf::RenderWindow& window, std::vector<sf::Text>& creditTexts, 
                       sf::Text& quitButton, sf::Text& fullscreenButton, sf::Sprite& background) {
    // Redimensionner le fond pour qu'il couvre tout l'écran sans être coupé
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = background.getTexture()->getSize();
    
    // Calculer l'échelle pour couvrir tout l'écran (prendre le maximum des deux échelles)
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::max(scaleX, scaleY);
    
    background.setScale(scale, scale);
    
    // Centrer le fond d'écran
    sf::FloatRect bgBounds = background.getGlobalBounds();
    background.setPosition(
        (windowSize.x - bgBounds.width) / 2,
        (windowSize.y - bgBounds.height) / 2
    );
    
    // Repositionner le bouton Quitter
    quitButton.setPosition(windowSize.x - 120, windowSize.y - 50);
    
    // Repositionner le bouton plein écran
    fullscreenButton.setPosition(windowSize.x - 250, windowSize.y - 50);
    
    // Ajuster la position horizontale des crédits pour les centrer
    for (auto& text : creditTexts) {
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setPosition((windowSize.x - textBounds.width) / 2, text.getPosition().y);
    }
}

int main() {
    sf::RenderWindow window(windowedMode, "Crédits", sf::Style::Close);
    window.setFramerateLimit(60);
    
    // Police
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    
    // Image de fond
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("background.jpg")) {
        return -1;
    }
    sf::Sprite background(bgTexture);
    
    // Musique de fond
    sf::Music music;
    if (music.openFromFile("Ocean.mp3")) {
        music.setLoop(true);
        music.play();
    }
    
    // Liste des crédits
    std::vector<std::string> credits = {
        "Leila Wilde - Chef de projet",
        "Lorenzo Ottaviani - Master Game Designer",
        "Samy Belazzoug - Master Game Logic",
        "Laurent CASSAR - Secondary Stains Assistant"
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
    
    // Bouton Plein écran
    sf::Text fullscreenButton;
    fullscreenButton.setFont(font);
    fullscreenButton.setString("[ ]");
    fullscreenButton.setCharacterSize(24);
    fullscreenButton.setFillColor(sf::Color::White);
    fullscreenButton.setPosition(window.getSize().x - 250, window.getSize().y - 50);
    
    // Instructions à l'écran
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setString("Double-cliquez ou sur [ ] pour basculer en plein écran");
    instructions.setCharacterSize(16);
    instructions.setFillColor(sf::Color::Yellow);
    instructions.setPosition(10, 10);
    
    // Variables pour détecter le double-clic
    sf::Clock doubleclickTimer;
    int clickCount = 0;
    const float doubleclickDelay = 0.3f; // 300ms pour un double-clic
    
    // Positionnement initial des éléments
    repositionElements(window, creditTexts, quitButton, fullscreenButton, background);
    
    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                
            // Gestion des touches (Échap pour quitter)
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            
            // Gestion du double-clic pour basculer en plein écran
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                // Vérifier si c'est un clic sur le bouton Quitter
                if (quitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    window.close();
                    continue;
                }
                
                // Vérifier si c'est un clic sur le bouton plein écran
                if (fullscreenButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    toggleFullscreen(window);
                    repositionElements(window, creditTexts, quitButton, fullscreenButton, background);
                    continue;
                }
                
                // Détection du double-clic dans la zone de la barre de titre (partie haute de la fenêtre)
                bool isInTitleArea = mousePos.y <= 30; // Zone approximative de la barre de titre
                
                if (isInTitleArea || true) { // Permettre le double-clic partout pour plus de facilité
                    clickCount++;
                    
                    if (clickCount == 1) {
                        doubleclickTimer.restart();
                    } else if (clickCount == 2) {
                        if (doubleclickTimer.getElapsedTime().asSeconds() <= doubleclickDelay) {
                            // Double-clic détecté
                            toggleFullscreen(window);
                            repositionElements(window, creditTexts, quitButton, fullscreenButton, background);
                            clickCount = 0;
                        } else {
                            clickCount = 1;
                            doubleclickTimer.restart();
                        }
                    }
                }
            }
        }
        
        // Reset du compteur de clics après le délai
        if (clickCount > 0 && doubleclickTimer.getElapsedTime().asSeconds() > doubleclickDelay) {
            clickCount = 0;
        }
        
        window.clear();
        window.draw(background);
        
        // Mise à jour et affichage du texte avec boucle infinie
        for (auto& text : creditTexts) {
            text.move(0, -0.8f);  // Vitesse lente
            
            // Si le texte sort par le haut, le remettre en bas pour créer une boucle
            if (text.getPosition().y < -50) {
                text.setPosition(text.getPosition().x, window.getSize().y + 60);
            }
            
            window.draw(text);
        }
        
        window.draw(quitButton);
        window.draw(fullscreenButton);
        window.draw(instructions);
        window.display();
        
        // La fenêtre reste ouverte avec boucle infinie des crédits
    }
    
    return 0;
}
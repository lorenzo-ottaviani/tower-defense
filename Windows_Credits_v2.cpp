#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>

class CreditsScreen {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text titleText;
    sf::Text backText;
    std::vector<sf::Text> creditTexts;
    sf::RectangleShape background;
    sf::RectangleShape overlay;
    
    // Animation variables
    float scrollOffset;
    float scrollSpeed;
    sf::Clock animationClock;
    
    // Background elements for tower defense theme
    std::vector<sf::CircleShape> towers;
    std::vector<sf::RectangleShape> paths;
    sf::RectangleShape castle;
    
    // Particle system for effects
    struct Particle {
        sf::CircleShape shape;
        sf::Vector2f velocity;
        float life;
        float maxLife;
    };
    std::vector<Particle> particles;
    
public:
    CreditsScreen() : window(sf::VideoMode(1200, 800), "Tower Defense - Crédits", sf::Style::Close),
                      scrollOffset(0.0f), scrollSpeed(30.0f) {
        window.setFramerateLimit(60);
        initializeGraphics();
        setupBackground();
        setupParticles();
    }
    
    void initializeGraphics() {
        // Load font (you should replace this with your actual font file)
        if (!font.loadFromFile("arial.ttf")) {
            // If arial.ttf is not found, try to load default system font
            std::cout << "Warning: Could not load arial.ttf, using default font" << std::endl;
        }
        
        // Setup background with gradient
        background.setSize(sf::Vector2f(1200, 800));
        background.setFillColor(sf::Color(20, 30, 40)); // Dark blue base
        
        // Semi-transparent overlay for text readability
        overlay.setSize(sf::Vector2f(1200, 800));
        overlay.setFillColor(sf::Color(0, 0, 0, 100));
        
        // Title setup
        titleText.setFont(font);
        titleText.setString("TOWER DEFENSE");
        titleText.setCharacterSize(72);
        titleText.setFillColor(sf::Color(255, 215, 0)); // Gold
        titleText.setStyle(sf::Text::Bold);
        
        // Center title
        sf::FloatRect titleBounds = titleText.getLocalBounds();
        titleText.setPosition((1200 - titleBounds.width) / 2, 100);
        
        // Add glow effect to title
        titleText.setOutlineThickness(3);
        titleText.setOutlineColor(sf::Color(255, 140, 0));
        
        // Setup credit texts
        std::vector<std::string> credits = {
            "",
            "CRÉDITS",
            "",
            "Chef de Projet",
            "Leila Wilde",
            "",
            "Développeurs",
            "Lorenzo Ottaviani",
            "Samy Belazzoug",
            "Laurent CASSAR",
            "",
            "",
            "Merci d'avoir joué !",
            "",
            "Appuyez sur ÉCHAP pour revenir"
        };
        
        float yPos = 250;
        for (size_t i = 0; i < credits.size(); ++i) {
            sf::Text creditText;
            creditText.setFont(font);
            creditText.setString(credits[i]);
            
            if (credits[i] == "CRÉDITS") {
                creditText.setCharacterSize(48);
                creditText.setFillColor(sf::Color(100, 200, 255)); // Light blue
                creditText.setStyle(sf::Text::Bold);
            } else if (credits[i] == "Chef de Projet" || credits[i] == "Développeurs") {
                creditText.setCharacterSize(32);
                creditText.setFillColor(sf::Color(200, 200, 200)); // Light gray
                creditText.setStyle(sf::Text::Bold);
            } else if (credits[i] == "Leila Wilde" || credits[i] == "Lorenzo Ottaviani" || 
                       credits[i] == "Samy Belazzoug" || credits[i] == "Laurent CASSAR") {
                creditText.setCharacterSize(28);
                creditText.setFillColor(sf::Color(255, 255, 255)); // White
            } else if (credits[i] == "Merci d'avoir joué !") {
                creditText.setCharacterSize(36);
                creditText.setFillColor(sf::Color(255, 215, 0)); // Gold
                creditText.setStyle(sf::Text::Bold);
            } else {
                creditText.setCharacterSize(24);
                creditText.setFillColor(sf::Color(180, 180, 180)); // Gray
            }
            
            // Center text horizontally
            sf::FloatRect textBounds = creditText.getLocalBounds();
            creditText.setPosition((1200 - textBounds.width) / 2, yPos);
            
            creditTexts.push_back(creditText);
            yPos += 50;
        }
        
        // Back instruction text
        backText.setFont(font);
        backText.setString("Appuyez sur ÉCHAP pour revenir au menu");
        backText.setCharacterSize(20);
        backText.setFillColor(sf::Color(150, 150, 150));
        sf::FloatRect backBounds = backText.getLocalBounds();
        backText.setPosition((1200 - backBounds.width) / 2, 750);
    }
    
    void setupBackground() {
        // Create castle at the end of path
        castle.setSize(sf::Vector2f(80, 100));
        castle.setFillColor(sf::Color(139, 69, 19)); // Brown
        castle.setPosition(1050, 350);
        
        // Create path segments
        for (int i = 0; i < 5; ++i) {
            sf::RectangleShape pathSegment;
            pathSegment.setSize(sf::Vector2f(200, 60));
            pathSegment.setFillColor(sf::Color(101, 67, 33)); // Dark brown
            pathSegment.setPosition(i * 200 + 50, 375);
            paths.push_back(pathSegment);
        }
        
        // Create towers around the path
        std::vector<sf::Vector2f> towerPositions = {
            {150, 250}, {350, 200}, {550, 280}, {750, 220}, {950, 260},
            {180, 520}, {380, 580}, {580, 500}, {780, 560}, {980, 510}
        };
        
        for (const auto& pos : towerPositions) {
            sf::CircleShape tower;
            tower.setRadius(25);
            tower.setFillColor(sf::Color(105, 105, 105)); // Gray
            tower.setOutlineThickness(3);
            tower.setOutlineColor(sf::Color(169, 169, 169)); // Light gray
            tower.setPosition(pos.x - 25, pos.y - 25);
            towers.push_back(tower);
        }
    }
    
    void setupParticles() {
        // Initialize some magical particles for atmosphere
        for (int i = 0; i < 50; ++i) {
            Particle particle;
            particle.shape.setRadius(2);
            particle.shape.setFillColor(sf::Color(255, 215, 0, 150)); // Semi-transparent gold
            particle.shape.setPosition(
                static_cast<float>(rand() % 1200),
                static_cast<float>(rand() % 800)
            );
            particle.velocity = sf::Vector2f(
                (rand() % 20 - 10) / 10.0f,
                (rand() % 20 - 10) / 10.0f
            );
            particle.life = static_cast<float>(rand() % 100) / 100.0f;
            particle.maxLife = particle.life;
            particles.push_back(particle);
        }
    }
    
    void updateParticles(float deltaTime) {
        for (auto& particle : particles) {
            // Update position
            particle.shape.move(particle.velocity * deltaTime * 50.0f);
            
            // Update life
            particle.life -= deltaTime * 0.3f;
            if (particle.life <= 0) {
                particle.life = particle.maxLife;
                particle.shape.setPosition(
                    static_cast<float>(rand() % 1200),
                    static_cast<float>(rand() % 800)
                );
            }
            
            // Update alpha based on life
            sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (particle.life / particle.maxLife));
            sf::Color color = particle.shape.getFillColor();
            color.a = alpha;
            particle.shape.setFillColor(color);
            
            // Wrap around screen
            sf::Vector2f pos = particle.shape.getPosition();
            if (pos.x < 0) particle.shape.setPosition(1200, pos.y);
            if (pos.x > 1200) particle.shape.setPosition(0, pos.y);
            if (pos.y < 0) particle.shape.setPosition(pos.x, 800);
            if (pos.y > 800) particle.shape.setPosition(pos.x, 0);
        }
    }
    
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close(); // Or return to main menu
                }
            }
        }
    }
    
    void update() {
        float deltaTime = animationClock.restart().asSeconds();
        //float sin = 0.0
        // Gentle floating animation for credits
        scrollOffset += scrollSpeed * deltaTime;
        if (scrollOffset > 360.0f) scrollOffset = 0.0f;
        
        // Apply floating effect to credit texts
        for (size_t i = 0; i < creditTexts.size(); ++i) {
            sf::Vector2f originalPos = creditTexts[i].getPosition();
            float floatOffset = sin(scrollOffset * 0.01f + i * 0.5f) * 3.0f;
            creditTexts[i].setPosition(originalPos.x, originalPos.y + floatOffset);
        }
        
        // Update particles
        updateParticles(deltaTime);
        
        // Animate title glow
        float glowIntensity = (sin(scrollOffset * 0.02f) + 1.0f) * 0.5f;
        sf::Color glowColor(255, static_cast<sf::Uint8>(140 + glowIntensity * 100), 0);
        titleText.setOutlineColor(glowColor);
    }
    
    void render() {
        window.clear();
        
        // Draw background
        window.draw(background);
        
        // Draw background elements (towers, paths, castle)
        for (const auto& path : paths) {
            window.draw(path);
        }
        
        window.draw(castle);
        
        for (const auto& tower : towers) {
            window.draw(tower);
        }
        
        // Draw particles
        for (const auto& particle : particles) {
            window.draw(particle.shape);
        }
        
        // Draw overlay for text readability
        window.draw(overlay);
        
        // Draw title
        window.draw(titleText);
        
        // Draw credits
        for (const auto& creditText : creditTexts) {
            window.draw(creditText);
        }
        
        // Draw back instruction
        window.draw(backText);
        
        window.display();
    }
    
    void run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }
};

int main() {
    try {
        CreditsScreen creditsScreen;
        creditsScreen.run();
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}

// Compilation command:
// g++ -o credits credits.cpp -lsfml-graphics -lsfml-window -lsfml-system
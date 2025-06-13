#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

int main() {

    //RANDOM Crée un moteur de génération pseudo-aléatoire
    std::random_device rd;  // source d'entropie (hardware si dispo)
    std::mt19937 gen(rd()); // moteur Mersenne Twister (très bon générateur)
    // Crée une distribution uniforme entre 50 et 550
    std::uniform_int_distribution<> distrib(100, 525);
    sf::RenderWindow window(sf::VideoMode(1000,600),"Tower Defense");

    //TEXT

    //SHAPES
    sf::RectangleShape menu;
        float menu_size_x = 1000, menu_size_y = 75;
        float menu_pos_x = 0, menu_pos_y = 0;
        menu.setSize(sf::Vector2f(menu_size_x,menu_size_y));
        menu.setPosition(menu_pos_x,menu_pos_y);
        menu.setFillColor(sf::Color::Black);

    sf::RectangleShape enemy;
        float enemy_size_x = 50,enemy_size_y = 50;
        float enemy_pos_x = 1050;float enemy_pos_y = distrib(gen);
        enemy.setSize(sf::Vector2f(enemy_size_x,enemy_size_y));
        enemy.setPosition(enemy_pos_x,enemy_pos_y);
        enemy.setFillColor(sf::Color::Red);

    sf::RectangleShape beach;
        beach.setSize(sf::Vector2f(200,525));
        beach.setPosition(0,75);
        beach.setFillColor(sf::Color::Yellow);

    //TOWERS
    sf::CircleShape tower;
        float tower_radius = 30;
        float tower_pos_x = 0, tower_pos_y = 5;
        tower.setRadius(tower_radius);
        tower.setPosition(tower_pos_x,tower_pos_y);
        tower.setFillColor(sf::Color::Green);
    sf::CircleShape tower2;
        float tower2_radius = 30;
        float tower2_pos_x = 150, tower2_pos_y = 5;
        tower2.setRadius(tower2_radius);
        tower2.setPosition(tower2_pos_x,tower2_pos_y);
        tower2.setFillColor(sf::Color::Magenta);
    sf::CircleShape tower3;
        float tower3_radius = 30;
        float tower3_pos_x = 300, tower3_pos_y = 5;
        tower3.setRadius(tower3_radius);
        tower3.setPosition(tower3_pos_x,tower3_pos_y);
        tower3.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
        sf::Vector2i mouse_position =  sf::Mouse::getPosition(window);
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    std::cout << mousePos.x << " " << mousePos.y << std::endl;
                    tower_pos_x = mousePos.x;
                    tower_pos_y = mousePos.y;
                    tower.setPosition(tower_pos_x,tower_pos_y);
                }
            }

        enemy_pos_x -= 0.01;

        if (enemy_pos_x <= 200) {
            enemy_pos_x = 1050;
            enemy_pos_y = distrib(gen);
        }

        enemy.setPosition(enemy_pos_x,enemy_pos_y);
        sf::Vector2i local_position =  sf::Mouse::getPosition(window);

        window.clear(sf::Color::Blue);

        window.draw(menu);
        window.draw(beach);
        window.draw(tower);
        window.draw(tower2);
        window.draw(tower3);
        window.draw(enemy);

        window.display();
        }
    return 0;
}
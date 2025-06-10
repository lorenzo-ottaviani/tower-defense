#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <random>

// Configuration

static const int   WINDOW_W   = 900;
static const int   WINDOW_H   = 600;
static const int   ROWS       = 6;
static const int   COLS       = 9;
static const float CELL_W     = WINDOW_W / (float)COLS;
static const float CELL_H     = WINDOW_H / (float)ROWS;
static const float ENEMY_SPEED= 20.f;  // pixels/sec
static const float SPAWN_TIME = 5.f;   // seconds

// Convert grid coords to world coords

sf::Vector2f cellToWorld(int row, int col) {
    return {
        col * CELL_W + CELL_W/2.f,
        row * CELL_H + CELL_H/2.f
    };
}
bool worldToCell(const sf::Vector2f& w, int &row, int &col) {
    col = int(w.x / CELL_W);
    row = int(w.y / CELL_H);
    return (col>=0 && col<COLS && row>=0 && row<ROWS);
}

// Game objects

struct Creature {
    sf::CircleShape sprite;
    int row, col;
    Creature(int r,int c):
        sprite(CELL_W*0.4f), row(r), col(c)
    {
        sprite.setFillColor(sf::Color::Green);
        sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
        sprite.setPosition(cellToWorld(r,c));
    }
};

struct Boat {
    sf::RectangleShape sprite;
    int row;
    Boat(int r):
        sprite({CELL_W*0.6f, CELL_H*0.6f}), row(r)
    {
        sprite.setFillColor(sf::Color::White);
        sprite.setOrigin(sprite.getSize().x/2.f, sprite.getSize().y/2.f);
        // spawn at right edge
        sprite.setPosition(WINDOW_W + sprite.getSize().x, cellToWorld(r,0).y);
    }
    void update(float dt) {
        sprite.move(-ENEMY_SPEED * dt, 0.f);
    }
};

// Main

int main() {
    sf::RenderWindow window({WINDOW_W, WINDOW_H}, "Sea vs Humans");
    window.setFramerateLimit(60);

    // Track occupied cells
    bool occupied[ROWS][COLS] = {};

    // Containers
    std::vector<std::unique_ptr<Creature>> creatures;
    std::vector<std::unique_ptr<Boat>> boats;

    sf::Clock clock, spawnClock;
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> laneDist(0, ROWS-1);

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();

            // Mouse click to create a creature
            if (ev.type == sf::Event::MouseButtonPressed
             && ev.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f wpos = window.mapPixelToCoords({ev.mouseButton.x, ev.mouseButton.y});
                int r,c;
                if (worldToCell(wpos,r,c) && !occupied[r][c]) {
                    creatures.emplace_back(std::make_unique<Creature>(r,c));
                    occupied[r][c] = true;
                }
            }
        }

        // Spawn boats periodically
        if (spawnClock.getElapsedTime().asSeconds() >= SPAWN_TIME) {
            spawnClock.restart();
            int r = laneDist(rng);
            boats.emplace_back(std::make_unique<Boat>(r));
        }

        // Update boats
        for (auto& b : boats) {
            b->update(dt);
        }

        // Remove off-screen boats
        boats.erase(std::remove_if(boats.begin(), boats.end(),
            [](auto& b){
                return b->sprite.getPosition().x < -50.f;
            }), boats.end()
        );

        // Render
        window.clear(sf::Color(0, 155, 200));

        // Draw grid lines
        sf::RectangleShape line;
        line.setFillColor(sf::Color(100,100,255));
        for (int i = 1; i < COLS; i++) {
            line.setSize({2.f, (float)WINDOW_H});
            line.setPosition(i*CELL_W, 0);
            window.draw(line);
        }
        for (int i = 1; i < ROWS; i++) {
            line.setSize({(float)WINDOW_W, 2.f});
            line.setPosition(0, i*CELL_H);
            window.draw(line);
        }

        // Draw creatures & boats
        for (auto& c : creatures)  window.draw(c->sprite);
        for (auto& b : boats) window.draw(b->sprite);

        window.display();
    }

    return 0;
}

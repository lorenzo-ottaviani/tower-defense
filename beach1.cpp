#include <SFML/Graphics.hpp>
#include <vector>

static const int WINDOW_W = 900;
static const int WINDOW_H = 600;

// tiles across
static const int COLS   = 9;
// tiles high: sea and beach
static const int ROWS   = 2;

// each tile’s size in pixels
static const int TILE_W = WINDOW_W  / COLS;
static const int TILE_H = WINDOW_H  / ROWS;

int main()
{
    sf::RenderWindow window({WINDOW_W, WINDOW_H}, "Sea vs Humans");

    // Load sea and beach textures
    sf::Texture seaTex, beachTex;
    if (!seaTex.loadFromFile("sea.png")) return -1;
    if (!beachTex  .loadFromFile("beach.png"  )) return -1;

    // Build two tilemaps
    std::vector<sf::Sprite> tiles;
    tiles.reserve(ROWS * COLS);

    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            sf::Sprite s( (row==0) ? seaTex : beachTex );
            float sx = TILE_W / float(s.getTexture()->getSize().x);
            float sy = TILE_H / float(s.getTexture()->getSize().y);
            s.setScale(sx, sy);
            s.setPosition(col * float(TILE_W), row * float(TILE_H));
            tiles.push_back(s);
        }
    }
    
    sf::View view(sf::FloatRect(0,0,WINDOW_W,WINDOW_H));
    window.setView(view);

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto &t : tiles)
            window.draw(t);
        window.display();
    }
    return 0;
}

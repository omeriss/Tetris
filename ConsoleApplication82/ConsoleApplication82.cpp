#include "LocalUserBoard.h"

vector<std::pair<std::vector<Tile>, sf::Vector2f>> Piece::pices = PiecesVector;
float moveInterval = 1;

int main()
{
    srand(time(NULL));
    sf::Clock c;
    LocalUserBoard p({ 50 * 10, 50 * 20 });
    sf::RenderWindow window(sf::VideoMode(50*10, 50*20), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        p.Update(c.restart().asSeconds());
        p.Draw(window);
        window.display();
    }

    return 0;
}
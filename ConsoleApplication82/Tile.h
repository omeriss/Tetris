#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	Tile(const Tile& other);
	void Draw(sf::RenderWindow& window, sf::Vector2i position);
	void ReSetPosition();
	void Rotate(bool dir, sf::Vector2f origin);
	void Move(sf::Vector2i dis);
	friend class Piece;
private:
	sf::Vector2f position;
	sf::RectangleShape tile;
};


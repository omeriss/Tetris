#include "Tile.h"

Tile::Tile(sf::Vector2f position, sf::Vector2f size, sf::Color color):tile(size)
{
	this->position = position;
	tile.setFillColor(color);
}

Tile::Tile(const Tile& other):tile(other.tile.getSize())
{
	this->position = other.position;
	tile.setFillColor(other.tile.getFillColor());
}

void Tile::Draw(sf::RenderWindow& window, sf::Vector2i position)
{
	this->tile.setPosition({ (this->position.x + position.x )* tile.getSize().x, (this->position.y + position.y)* tile.getSize().y });
	window.draw(this->tile);
}

void Tile::ReSetPosition()
{
	position = { 0,0 };
}

void Tile::Rotate(bool dir, sf::Vector2f origin)
{
	origin -= {0.5, 0.5};
	int t = !dir;
	t = t * 2 - 1;
	position = {(position.y-origin.y) *t + origin.y, (position.x - origin.x) * -t + origin.x};
}

void Tile::Move(sf::Vector2i dis)
{
	position.x += dis.x;
	position.y += dis.y;
}

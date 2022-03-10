#pragma once
#include "Tile.h"
#include <vector>
using std::vector;

class Piece
{
public:
	static vector<std::pair<std::vector<Tile>, sf::Vector2f>> pices;
	Piece(int piceType = -1);
	bool Move(sf::Vector2i dir, vector<vector<Tile*>>& board);
	bool Rotate(bool dir, vector<vector<Tile*>>& board);
	void Draw(sf::RenderWindow& window);
	bool CopyToBoard(vector<vector<Tile*>>& board);
private:
	std::vector<Tile> tiles;
	sf::Vector2i position;
	sf::Vector2f origin;
	size_t piceType;
};


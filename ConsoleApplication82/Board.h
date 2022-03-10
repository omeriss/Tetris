#pragma once
#include "Piece.h"

class Board
{
public:
	Board(sf::Vector2f size);
	void Draw(sf::RenderWindow& window);
	void CleanBoard();
	virtual void Update(float deltaTime) = 0;
protected:
	float timeToMove;
	float timeToInput;
	sf::View view;
	Piece curPice;
	vector<vector<Tile*>> board;
};


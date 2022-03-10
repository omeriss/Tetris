#pragma once
#include "Board.h"

class LocalUserBoard: public Board
{
public:
	LocalUserBoard(sf::Vector2f size) :Board(size) {};
	void Update(float deltaTime);
	sf::Keyboard::Key nextKey;
};


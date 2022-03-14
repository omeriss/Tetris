#pragma once
#include "Board.h"

class LocalUserBoard: public Board
{
public:
	LocalUserBoard(sf::Vector2f size) :Board(size), keys() {};
	void Update(float deltaTime);
	short keys[sf::Keyboard::KeyCount];
};


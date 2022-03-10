#include "LocalUserBoard.h"

void LocalUserBoard::Update(float deltaTime)
{
	this->timeToInput += deltaTime;
	this->timeToMove += deltaTime;
	if (timeToInput >= InputInterval) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			curPice.Move({ 1, 0 }, board);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			curPice.Move({ -1, 0 }, board);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if(curPice.Move({ 0, 1 }, board))
				timeToMove = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			while(curPice.Move({ 0, 1 }, board)){}
			timeToMove = moveInterval;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			curPice.Rotate(true, board);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			curPice.Rotate(false, board);
		}
		timeToInput = 0;
	}
	if (timeToMove >= moveInterval) {
		if (!curPice.Move({ 0, 1 }, board)) {
			if (!curPice.CopyToBoard(board)) {
				std::cout << "You suck\n";
				while(true){}
			}
			curPice = Piece();
			CleanBoard();
		}

		timeToMove = 0;
	}
}

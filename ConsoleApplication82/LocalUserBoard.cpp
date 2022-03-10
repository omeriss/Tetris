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
			curPice.Move({ 0, 1 }, board);
			timeToMove = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

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
			curPice.CopyToBoard(board);
			curPice = Piece();
		}

		timeToMove = 0;
	}
}

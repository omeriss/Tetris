#include "LocalUserBoard.h"

#define NumOfUsedKeys 6
static sf::Keyboard::Key UsedKeys[NumOfUsedKeys] = { sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Space, sf::Keyboard::X, sf::Keyboard::Z};

void LocalUserBoard::Update(float deltaTime)
{
	this->timeToInput += deltaTime;
	this->timeToMove += deltaTime;

	if (timeToInput >= InputInterval) {
		if (keys[sf::Keyboard::Right] *=2) {
			curPice.Move({ 1, 0 }, board);
		}
		if (keys[sf::Keyboard::Left] *= 2) {
			curPice.Move({ -1, 0 }, board);
		}
		if (keys[sf::Keyboard::Down] *= 2) {
			if (curPice.Move({ 0, 1 }, board))
				timeToMove = 0;
		}
		if (keys[sf::Keyboard::Space] *= 2) {
			while (curPice.Move({ 0, 1 }, board)) {}
			timeToMove = moveInterval;
		}
		if (keys[sf::Keyboard::X] *= 2) {
			curPice.Rotate(true, board);
		}
		if (keys[sf::Keyboard::Z] *= 2) {
			curPice.Rotate(false, board);
		}
		timeToInput = 0;
	}
	else{
		for (int i = 0; i < NumOfUsedKeys; i++) {
			keys[UsedKeys[i]] = (keys[UsedKeys[i]] >= 2) ?
				sf::Keyboard::isKeyPressed(UsedKeys[i]) * 2 : 
				keys[UsedKeys[i]] || sf::Keyboard::isKeyPressed(UsedKeys[i]);
		}
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

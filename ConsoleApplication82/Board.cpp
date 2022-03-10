#include "Board.h"

Board::Board(sf::Vector2f size):timeToInput(0), timeToMove(0), view(size/2.0f, size)
{
	board.resize(BoardH);
	for (auto& row : board) {
		row.resize(BoardW);
	}
}

void Board::Draw(sf::RenderWindow& window)
{
	window.setView(view);
	curPice.Draw(window);
	int r = board.size();
	for (int i = 0; i < r; i++) {
		int c = board[i].size();
		for (int j = 0; j < c; j++) {
			if(board[i][j])
				board[i][j]->Draw(window, { j, i });
		}
	}
}

void Board::CleanBoard()
{
}

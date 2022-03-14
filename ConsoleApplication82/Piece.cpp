#include "Piece.h"

Piece::Piece(int piceType)
{
	if (piceType == -1)
		piceType = rand() % pices.size();
	this->piceType = piceType;
	this->tiles = pices[piceType].first;
	this->origin = pices[piceType].second;
	this->position.x = BoardW / 2.0 - origin.x / 2.0;
	this->position.y = -2;
}

bool Piece::Move(sf::Vector2i dir, vector<vector<Tile*>>& board)
{
	position += dir;
	for (auto tile : tiles) {
		if (tile.position.x + position.x >= BoardW || tile.position.x + position.x < 0 ||
			tile.position.y + position.y >= BoardH || (tile.position.y + position.y >=0 && board[tile.position.y + position.y][tile.position.x + position.x])) {
			position -= dir;
			return (tile.position.y >= BoardH || (tile.position.y + position.y >= 0 &&board[tile.position.y + position.y][tile.position.x + position.x]));
		}
	}
	return true;

}

bool Piece::Rotate(bool dir, vector<vector<Tile*>>& board)
{
	int k = 0;
	for (auto& tile : tiles) {
		tile.Rotate(dir, origin);
		if (tile.position.x + position.x >= BoardW || tile.position.x + position.x < 0 ||
			tile.position.y + position.y >= BoardH || (tile.position.y + position.y >= 0 && board[tile.position.y + position.y][tile.position.x + position.x])) {
			dir = !dir;
			for (int i = 0; i <= k; i++) {
				tiles[i].Rotate(dir, origin);
			}
			return (tile.position.y >= BoardH || (tile.position.y + position.y >= 0 &&board[tile.position.y + position.y][tile.position.x + position.x]));
		}
		k++;
	}
	return true;
}

void Piece::Draw(sf::RenderWindow& window)
{
	for (auto& tile : tiles) {
		tile.Draw(window, this->position);
	}
}

bool Piece::CopyToBoard(vector<vector<Tile*>>& board)
{
	bool alive = true;
	for (auto& tile : tiles) {
		if (tile.position.y + position.y < 0) {
			alive = false;
			continue;
		}
		board[tile.position.y + position.y][tile.position.x + position.x] = new Tile(tile);
		board[tile.position.y + position.y][tile.position.x + position.x]->ReSetPosition();
	}
	return alive;
}

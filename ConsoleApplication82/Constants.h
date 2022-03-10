#pragma once
#include <iostream>


#define BoardW 10
#define BoardH 20
#define TileSize 50
#define InputInterval 0.15f
extern float moveInterval;

#define Color0 sf::Color(0, 255, 255)
#define Color1 sf::Color(0, 0, 255)
#define Color2 sf::Color(255, 127, 0)
#define Color3 sf::Color(255, 255, 0)
#define Color4 sf::Color(0, 255, 0)
#define Color5 sf::Color(128, 0, 128)
#define Color6 sf::Color(255, 0, 0)

#define PiecesVector {									\
	{{													\
		Tile({ 0,1 }, { TileSize, TileSize }, Color0),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color0),	\
		Tile({ 2,1 }, { TileSize, TileSize }, Color0),	\
		Tile({ 3,1 }, { TileSize, TileSize }, Color0)},	\
		{2,2}											\
	},													\
	{{													\
		Tile({ 0,0 }, { TileSize, TileSize }, Color1),	\
		Tile({ 0,1 }, { TileSize, TileSize }, Color1),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color1),	\
		Tile({ 2,1 }, { TileSize, TileSize }, Color1)},	\
		{1.5,1.5}										\
	},													\
	{{													\
		Tile({ 0,1 }, { TileSize, TileSize }, Color2),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color2),	\
		Tile({ 2,1 }, { TileSize, TileSize }, Color2),	\
		Tile({ 2,0 }, { TileSize, TileSize }, Color2)},	\
		{1.5,1.5}										\
	},													\
	{{													\
		Tile({ 0,0 }, { TileSize, TileSize }, Color3),	\
		Tile({ 1,0 }, { TileSize, TileSize }, Color3),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color3),	\
		Tile({ 0,1 }, { TileSize, TileSize }, Color3)},	\
		{1,1}											\
	},													\
	{{													\
		Tile({ 0,1 }, { TileSize, TileSize }, Color4),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color4),	\
		Tile({ 1,0 }, { TileSize, TileSize }, Color4),	\
		Tile({ 2,0 }, { TileSize, TileSize }, Color4)},	\
		{1.5,1.5}										\
	},													\
	{{													\
		Tile({ 0,1 }, { TileSize, TileSize }, Color5),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color5),	\
		Tile({ 1,0 }, { TileSize, TileSize }, Color5),	\
		Tile({ 2,1 }, { TileSize, TileSize }, Color5)},	\
		{1.5,1.5}										\
	},													\
	{{													\
		Tile({ 0,0 }, { TileSize, TileSize }, Color6),	\
		Tile({ 1,0 }, { TileSize, TileSize }, Color6),	\
		Tile({ 1,1 }, { TileSize, TileSize }, Color6),	\
		Tile({ 2,1 }, { TileSize, TileSize }, Color6)},	\
		{1.5,1.5}										\
	},													\
}
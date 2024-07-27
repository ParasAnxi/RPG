#pragma once
#include<SFML/Graphics.hpp>
#include "Tile.h"
using namespace sf;


class Map
{
	Texture tileSheetTexture;

	Tile*  tiles;
	int totalTiles;
	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

	static const int mapSize = 6;

	int mapWidth;
	int mapHeight;

	int mapNumbers[mapSize] = {
		120 ,121 ,122,
		144,145,146
	};

	Sprite mapSprites[mapSize];

public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};


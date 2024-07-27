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

	int mapNumbers[6] = {
		120 ,121 ,122,
		144,145,146
	};

	Sprite mapSprites[6];

public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};


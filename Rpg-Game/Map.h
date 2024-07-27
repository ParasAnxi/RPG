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

public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};


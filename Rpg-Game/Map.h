#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Map
{
	Texture tileSheetTexture;
	Sprite sprite[10];

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


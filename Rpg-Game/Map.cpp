#include "Map.h"
#include<iostream>
using namespace std;
Map::Map():
    tileWidth(16),tileHeight(16),totalTilesX(0),totalTilesY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("assests/world/tilesheet.png")) {
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;
        cout << "tile loaded successfully!";
        for (size_t i = 0; i < 10; i++) {
            sprite[i].setTexture(tileSheetTexture);
            sprite[i].setTextureRect(IntRect(i * tileWidth,  0 * tileHeight, tileWidth, tileHeight));
            sprite[i].setScale(Vector2f(5, 5));
            sprite[i].setPosition(Vector2f(100 + i * tileWidth * 5, 100));
        }
    }
    else {
        cout << "tile not loaded!";
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++) {
        window.draw(sprite[i]);
    }
}

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
        
        cout << "tile loaded successfully!";

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        totalTiles = totalTilesX + totalTilesY;

        tiles = new Tile[totalTiles];

        for (size_t y = 0; y < totalTilesY; y++) {
            for (size_t x = 0; x < totalTilesX; x++) {
                int i = x + y * totalTilesX;

                tiles[i].id = i;
                tiles[i].texture = &tileSheetTexture;

                tiles[i].sprite.setTexture(tileSheetTexture);
                tiles[i].sprite.setTextureRect(IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight));

                tiles[i].sprite.setScale(Vector2f(5, 5));
                tiles[i].sprite.setPosition(Vector2f(x * tileWidth * 5, 100 + y * tileWidth * 5));
            }
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
    for (size_t i = 0; i < totalTiles; i++) {
        window.draw(tiles[i].sprite);
    }
}

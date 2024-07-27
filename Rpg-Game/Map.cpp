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

        totalTiles = totalTilesX * totalTilesY;
      

        tiles = new Tile[totalTiles];

        for (size_t y = 0; y < totalTilesY; y++) {
            for (size_t x = 0; x < totalTilesX; x++) {
                int i = x + y * totalTilesX;

                tiles[i].id = i;
                tiles[i].position = Vector2i(x * tileWidth, y * tileHeight);



                //tiles[i].sprite.setTexture(tileSheetTexture);
                

                //tiles[i].sprite.setScale(Vector2f(5, 5));
                //tiles[i].sprite.setPosition(Vector2f(x * tileWidth * 5, 100 + y * tileWidth * 5));
            }
        }
    }
    else {
        cout << "tile not loaded!";
    }
    for (size_t y = 0; y < 2; y++) {
        for (size_t x = 0; x < 3; x++) {

            int i = x + y * 3;

            int index = mapNumbers[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(IntRect(
                    tiles[index].position.x,
                    tiles[index].position.y,
                    tileWidth,
                    tileHeight)
            );
            mapSprites[i].setPosition(Vector2f(x * 16 * 5 , 100 + y * 16 * 5));
            mapSprites[i].setScale(Vector2f(5,5));

        }
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(RenderWindow& window)
{
    for (size_t i = 0; i < 6; i++) {
        window.draw(mapSprites[i]);
    }
}

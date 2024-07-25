#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include "Enemy.h"

using namespace sf;
using namespace std;
class Player
{
private:
	Texture texture;
	vector<RectangleShape>bullets;
	float bulletSpeed = 5.0f;
	RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	Vector2i size;
	float playerSpeed = 1.0f;
public:
	Sprite sprite;
public:
	void Initialize();
	void Load();
	void Update(Enemy &enemy,float deltaTime);
	void Draw(RenderWindow& wondow);
};


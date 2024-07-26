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
	float bulletSpeed;
	RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	Vector2i size;
	float playerSpeed;
public:
	Sprite sprite;
public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(Enemy &enemy,float deltaTime);
	void Draw(RenderWindow& window);
};


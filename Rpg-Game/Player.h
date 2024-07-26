#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include "Enemy.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

class Player
{
private:
	Texture texture;
	RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	Vector2i size;
	float playerSpeed;
	float maxFireRate;
	float fireRateTimer;

public:
	Sprite sprite;
	vector<Bullet>bullets;
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(Enemy &enemy,float deltaTime,Vector2f& mousePosition);
	void Draw(RenderWindow& window);
};


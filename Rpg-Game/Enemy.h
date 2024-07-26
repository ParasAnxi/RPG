#pragma once

#include<SFML/Graphics.hpp>
using namespace sf;

class Enemy
{
private:
	Texture texture;
	RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	Vector2i size;
	Text enemyHealthBar;
	Font font;
public:
	Sprite sprite;
	int health;
public:
	Enemy();
	~Enemy();
	void SetHealth(int hp);
	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(RenderWindow& window);
};
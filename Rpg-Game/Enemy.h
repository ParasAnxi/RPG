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
public:
	Sprite sprite;
public:
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};
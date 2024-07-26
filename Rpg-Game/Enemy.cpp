#include "Enemy.h"
#include<iostream>
using namespace std;
Enemy::Enemy()
{
}
Enemy::~Enemy() {

}
void Enemy::Initialize()
{
    boundingRectangle.setFillColor(Color::Transparent);
    boundingRectangle.setOutlineColor(Color::Blue);
    boundingRectangle.setOutlineThickness(1);
    size = Vector2i(64, 64);
}

void Enemy::Load()
{
    if (texture.loadFromFile("assests/player/textures/enemy.png")) {
        cout << "Sprite loaded successfully!";
        sprite.setTexture(texture);
        sprite.setPosition(Vector2f(1600, 700));
        int xIndex = 0;
        int yIndex = 0;
        sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.scale(Vector2f(4, 4));
        boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        cout << "Sprite not loaded!";
    }
}

void Enemy::Update(double deltaTime)
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::Draw(RenderWindow& window)
{
    window.draw(boundingRectangle);
    window.draw(sprite);
}

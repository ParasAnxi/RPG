#include "Enemy.h"
#include<iostream>
using namespace std;
Enemy::Enemy():
    health(100)
{
}
Enemy::~Enemy() {

}
void Enemy::SetHealth(int hp)
{
    health += hp;
    enemyHealthBar.setString(to_string(health));
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
    if (font.loadFromFile("assests/fonts/Arial.ttf")) {
        cout << "font loaded" << endl;
        enemyHealthBar.setFont(font);
        enemyHealthBar.setString(to_string(health));
    }
    else {
        cout << "font not laoded" << endl;
    }
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
    if (health > 0) {
        boundingRectangle.setPosition(sprite.getPosition());
        enemyHealthBar.setPosition(sprite.getPosition());
    }
}

void Enemy::Draw(RenderWindow& window)
{
    if (health > 0) {
        window.draw(sprite);
        window.draw(enemyHealthBar);
        window.draw(boundingRectangle);
    }
}

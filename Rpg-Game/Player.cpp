#include "Player.h"
#include<iostream>
#include "Math.h"

using namespace std;

Player::Player():
    bulletSpeed(0.5f),
    playerSpeed(1.0f)
{
}
Player::~Player()
{
}
void Player::Load()
{
}
void Player::Initialize()
{
    boundingRectangle.setFillColor(Color::Transparent);
    boundingRectangle.setOutlineColor(Color::Red);
    boundingRectangle.setOutlineThickness(1);
    size = Vector2i(32, 32);

    if (texture.loadFromFile("assests/player/textures/player.png")) {
        cout << "Sprite loaded successfully!";
        sprite.setTexture(texture);
        int xIndex = 0;
        int yIndex = 0;
        sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.setPosition(Vector2f(0, 0));
        sprite.scale(Vector2f(4, 4));
        boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        cout << "Sprite not loaded!";
    }
}
void Player::Update(Enemy &enemy, float deltaTime)
{
    Vector2f position = sprite.getPosition();
    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        sprite.setPosition(position + Vector2f(1, 0) *playerSpeed * deltaTime);

    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
        sprite.setPosition(position + Vector2f(0, -1) * playerSpeed * deltaTime);

    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
        sprite.setPosition(position + Vector2f(0, 1) * playerSpeed * deltaTime);

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
        sprite.setPosition(position + Vector2f(-1, 0) * playerSpeed * deltaTime);

    //if (Mouse::isButtonPressed(Mouse::Button::Left)) {
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        bullets.push_back(RectangleShape(Vector2f(50, 25)));
        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }
    for (size_t i = 0; i < bullets.size(); i++) {
        Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[bullets.size() - 1].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }
    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::CheckRectCollision(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
        cout << "Collistion";
    }
}
void Player:: Draw(RenderWindow& window)
{
    window.draw(boundingRectangle);
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}


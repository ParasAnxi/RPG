#include "Bullet.h"
#include "Math.h"
Bullet::Bullet() :
	speed(0)
{
}

Bullet::~Bullet()
{
}



void Bullet::Initilize(const Vector2f& position, Vector2f& target, float speed)
{
	this->speed = speed;
	rectangleShape.setSize(Vector2f(50, 25));
	rectangleShape.setPosition(position);
	direction = Math::NormalizeVector(target - position);
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(RenderWindow& window)
{
	window.draw(rectangleShape);
}

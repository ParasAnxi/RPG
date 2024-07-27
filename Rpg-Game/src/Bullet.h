#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Bullet
{
private:
	RectangleShape rectangleShape;

public:
	Vector2f direction;
	float speed;
	float fireRate;

	Bullet();
	~Bullet();

	void Initilize(const Vector2f& position, Vector2f& target, float speed);
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	inline const FloatRect GetGlobalBounds() {
		return rectangleShape.getGlobalBounds();
	}
};
#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Math
{
public:
    static Vector2f NormalizeVector(Vector2f vec);
    static bool CheckRectCollision(FloatRect rect1, FloatRect rect2);
};


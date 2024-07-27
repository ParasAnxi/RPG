#pragma once

#include<SFML/Graphics.hpp>
using namespace sf;

struct Tile
{
	int id = -1;
	IntRect rect;
	Vector2i position;
};


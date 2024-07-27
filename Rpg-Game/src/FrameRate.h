#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class FrameRate
{
private:
	Text frameRate;
	Font font;
	float timer;
public:
	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(RenderWindow& window);
};


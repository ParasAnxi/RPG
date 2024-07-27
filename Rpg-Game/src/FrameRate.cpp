#include "FrameRate.h"
#include<iostream>
using namespace std; 
FrameRate::FrameRate() : 
    timer(0)
{
}
FrameRate::~FrameRate()
{
}
void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.loadFromFile("assests/fonts/Arial.ttf")) {
        cout << "font loaded" << endl;
        frameRate.setFont(font);
    }
    else {
        cout << "font not laoded" << endl;
    }
}

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime;
    if (timer >= 100.0) {
        double fps = 1000.0 / deltaTime;
        string frameRateText = "FPS: " + to_string(int(fps)) + "frame time: " + to_string(int(deltaTime));
        frameRate.setString(frameRateText);
        timer = 0;
    }
}

void FrameRate::Draw(RenderWindow& window)
{
    window.draw(frameRate);
}

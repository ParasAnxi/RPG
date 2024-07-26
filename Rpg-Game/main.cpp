#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"
using namespace sf;
using namespace std;
int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920,1080),"RPG Game",Style::Default,settings);
    window.setFramerateLimit(240);
    //------------------------------ INITIALIZE ---------------------------------//  

    Player player;
    Enemy enemy;
    FrameRate frame;
    player.Initialize();
    enemy.Initialize();
    frame.Initialize();

    //------------------------------ LOAD ---------------------------------//
    player.Load();
    enemy.Load();
    frame.Load();
    //------------------------------ UPDATE 
    Clock clock;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Time deltaTimeCounter = clock.restart();
        double deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0;
        frame.Update(deltaTime);
        player.Update(enemy,deltaTime);
        enemy.Update(deltaTime);
    //------------------------------ DRAW  ---------------------------------//
        window.clear(Color::Black);
        player.Draw(window);
        enemy.Draw(window);
        frame.Draw(window);
        window.display();
        
    }
    return 0;
}
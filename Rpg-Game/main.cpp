#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"
#include "Map.h"
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
    Map map;
    player.Initialize();
    enemy.Initialize();
    frame.Initialize();
    map.Initialize();

    //------------------------------ LOAD ---------------------------------//
    player.Load();
    enemy.Load();
    frame.Load();
    map.Load();
    //------------------------------ UPDATE 
    Clock clock;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Vector2f mousePosition = Vector2f(Mouse::getPosition(window));
        Time deltaTimeCounter = clock.restart();
        double deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0;
        frame.Update(deltaTime);
        player.Update(enemy,deltaTime,mousePosition);
        enemy.Update(deltaTime);
        map.Update(deltaTime);
    //------------------------------ DRAW  ---------------------------------//
        window.clear(Color::Black);
        map.Draw(window);
        player.Draw(window);
        enemy.Draw(window);
        frame.Draw(window);
        window.display();
        
    }
    return 0;
}
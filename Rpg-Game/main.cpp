#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;
int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920,1080),"RPG Game",Style::Default,settings);
    window.setFramerateLimit(144);
    //------------------------------ INITIALIZE ---------------------------------//
    Player player;
    Enemy enemy;

    player.Initialize();
    enemy.Initialize();

    //------------------------------ LOAD ---------------------------------//
    player.Load();
    enemy.Load();
    //------------------------------ UPDATE 
    Clock clock;
    while (window.isOpen()) {
        Time deltaTimeCounter = clock.restart();
        float deltaTime = deltaTimeCounter.asMilliseconds();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        
        
        player.Update(enemy,deltaTime);
        enemy.Update(deltaTime);
    //------------------------------ DRAW  ---------------------------------//
        window.clear(Color::Black);
        player.Draw(window);
        enemy.Draw(window);
        
        window.display();
    }
    return 0;
}
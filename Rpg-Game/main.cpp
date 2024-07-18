#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(800,600),"RPG Game",Style::Default,settings);
    CircleShape shape(50.0F);
    //update section
    shape.setFillColor(Color::Red);
    shape.setPosition(Vector2f(100,200));
    shape.setOutlineThickness(20);
    shape.setOutlineColor(Color::Magenta);
    CircleShape triangle(80.f, 80);
    //CircleShape triangle(80.f, 5);
    RectangleShape rectangle(Vector2f(200,200));

    

    while (window.isOpen()) {
        Event event;
        while(window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        //draw
        window.clear(Color::Black);//clearscreen to red
        window.draw(shape);
        //window.draw(rectangle);
        window.draw(triangle);
        window.display();//copy from buffer
        //draw
    }

    return 0;
}
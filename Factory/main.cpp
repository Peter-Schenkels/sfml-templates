#include <iostream>
#include <SFML/Graphics.hpp>
#include "factory.hpp"

int main(){


    sf::RenderWindow window({500,500}, "window");
    window.setFramerateLimit(60);
    Factory factory = Factory("test.json");
    factory.load();
    while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                factory.select(event);
                if (event.type == sf::Event::Closed){
                    factory.save();
                    window.close();
                }
            }
            window.clear();
            factory.update();
            factory.draw(window);
            window.display();

        };



    







}
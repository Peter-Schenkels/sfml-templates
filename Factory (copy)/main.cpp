#include <iostream>
#include <SFML/Graphics.hpp>
#include "factory.hpp"
#include "background_tile.hpp"
#include "sprite.hpp"

int main(){


    sf::RenderWindow window({1000,600}, "window");
    window.setFramerateLimit(60);
    Factory factory = Factory("test.json");
    factory.load();


    std::vector<Sprite> tiles;

    Sprite dog1({0,0}, {1,1}, "ding1.png");
    Sprite dog2({0,0}, {1,1}, "ding2.png");
    Sprite dog3({0,0}, {1,1}, "ding3.png");
    Sprite dog4({0,0}, {1,1}, "ding4.png");


    tiles.push_back(dog1);
    tiles.push_back(dog1);
    tiles.push_back(dog1);
    tiles.push_back(dog2);
    tiles.push_back(dog3);
    tiles.push_back(dog4);

    random_background_tiles background(tiles, {1000,1000});
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
            background.draw(window);
            factory.draw(window);
            window.display();

        };



    







}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"


int main(){
    sf::RenderWindow window{ sf::VideoMode{ WINDOW_SIZE_X, WINDOW_SIZE_Y }, "SFML window" };
    window.setSize({ WINDOW_SIZE_X, WINDOW_SIZE_Y });
    window.setFramerateLimit(60);
    Game game(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        game.main();
    };


}
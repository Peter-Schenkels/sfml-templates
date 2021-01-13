#include <iostream>
#include "tictactoe.hpp"

#ifndef TARGET_ARDUINO
#include "tictactoe_gui.hpp"

int main(){
    sf::RenderWindow window{ sf::VideoMode{ 100, 100 }, "SFML window" };
    window.setFramerateLimit(60);
    TicTacToe game = TicTacToe();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        game.update();
    };
}
#endif
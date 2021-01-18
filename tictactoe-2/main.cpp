#include <iostream>
#include "tictactoe.hpp"
#include <SFML/Graphics.hpp>
#include <thread>
#include <cstring>

int main(int argc, char *argv[]){
    if(argc > 1)
    {
        TicTacToe game = TicTacToe();
        if(std::string(argv[1]) == "cli")
        {
            game.set_game_type(GameType::cli);
            while(true)
            {
                game.update();
            }
        }
        else if(std::string(argv[1]) == "gui")
        {
            sf::RenderWindow window{ sf::VideoMode{ GRID_SIZE*3, GRID_SIZE*3 }, "SFML window" };
            window.setFramerateLimit(60);
            game.set_game_type(GameType::gui);
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed){
                        window.close();
                    }
                }
                game.update(event, window);
                game.draw(window);
                window.display();
            };
        }
        else
        {
            std::cout << "Run ./main.exe and enter type as input argument (cli or gui)" << std::endl;
        }
    }
    else
    {
        std::cout << "Run ./main.exe and enter type as input argument (cli or gui)" << std::endl;
    }
}

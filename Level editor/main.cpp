
#include "game.hpp"


int main() {

    sf::RenderWindow window{ sf::VideoMode{ 1200, 700 }, "SFML window" };
    window.setFramerateLimit(60);
    Game game(window);
z
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                game.save();
                window.close();
            }
        }
        
        game.main();
    };
}
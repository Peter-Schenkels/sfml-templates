#include <iostream>
#include <fstream>
#include <string>
#include "chip8interpreter.hpp"

int main()
{   
    sf::RenderWindow window({500,500}, "window");
	window.setFramerateLimit(60);
    Chip8Interpreter chip8 = Chip8Interpreter(window);
    chip8.initialize();
    while (window.isOpen())
	{
        chip8.cycle();
        window.display();
    }
}
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "game.hpp"

int main() {

    std::ifstream file;
    file.open("jerkel.jrkl");
    if(!(file.is_open())){
        std::cout << "file not found\n";
        std::ofstream newFile;
        newFile.open("jerkel.jrkl");
        newFile.close();
        file.open("jerkel.jrkl");
    }
    std::string name;
    sf::Vector2f position;
    sf::Color color;

    file >> position >> color >> name;

    if(name == "ROUND"){
        std::cout << "Hey I'm round \n";
    }
    std::cout << position.x << std::endl;
    std::cout << position.y << std::endl;



}
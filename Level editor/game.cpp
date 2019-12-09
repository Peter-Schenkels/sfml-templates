#include "game.hpp"


void Game::load(){

    try {
        
        file.open(fileLocation);

        if(!(file.is_open()))
            throw(fileLocation);
        
        std::string type;
        std::string end;
        sf::Vector2f size;
        std::string name = "";
        sf::Vector2f position;
        sf::Color color = sf::Color::White;
        std::string fileLocation;
        file >> end; 

        while (end == "/"){
            
            file >> position;
            file >> size;
            file >> type;
            file >> name;
            file >> color;
            file >> fileLocation;
            file >> end; 
            container.addObject(type, size, position, name, color, fileLocation);

        }

    }

    catch(std::string fileLocation){
        std::cerr << "unable to open file: \"" << fileLocation << "\"\nObject loading failed";
    }

}

void Game::save(){

    try { 

        std::ofstream file;
        file.open(fileLocation);

        if(!file.is_open()){
            throw(fileLocation);
        } 
        
        file << container.exportString();   
        file.close();

    }

    catch (std::string fileLocation){

        std::cerr << "unable to save to file: \"" << fileLocation << "\"\nObject saving failed";

    }
    
}

void Game::main(){
    
    for (auto action : actions){
        action();
    }

    update();
    draw();

}

void Game::draw(){

    window.clear();
    container.draw(window);
    window.display();

}
#include "game.hpp"

std::vector<std::string> ifstreamSeperator(char seperator, std::ifstream & input){

    std::string buffer = "";
    std::vector<std::string> Lines;

    std::string content( 
                            (std::istreambuf_iterator<char>(input)),
                            (std::istreambuf_iterator<char>()) 
                        );

    for (auto character : content){
        if (character == seperator){
            Lines.push_back(buffer);
            buffer = "";
        } else {
            buffer += character;
        }
        
    }
    Lines.push_back(buffer);
    buffer = "";

    return Lines;
}


void Game::load(){

    try {
        
        file.open(fileLocation);

        if(!(file.is_open()))
            throw(fileLocation);
        
        std::string type;
        std::string name = "";
        sf::Vector2f position;
        sf::Color color = sf::Color::White;;

        std::vector<std::string> lines = ifstreamSeperator('\n', file);

        for (auto line : lines){

            line >> type;

            if(type == "Circle"){

                float radius;

                line >> position;
                line >> radius;
                file >> name;
                file >> color;

                container.addCircle(position, radius, name, color);

            } else if(type == "Rectangle"){

                sf::Vector2f size;

                file >> position;
                file >> size;
                file >> name;
                file >> color;

                container.addRectangle(size, position, name, color);

            } else if(type == "Line"){

                sf::Vector2f size;

                file >> position;
                file >> size;
                file >> name;
                file >> color;
                
                container.addLine(size, position, name, color);


            } else if(type == "Sprite"){
                
                std::string imgLocation;
                sf::Vector2f size;

                file >> position;
                file >> size;
                file >> name;
                file >> color;
                file >> imgLocation;

                container.addSprite(size, position, name, color, imgLocation);
                
            } else throw(std::string("Unidentified Type in " + fileLocation));

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
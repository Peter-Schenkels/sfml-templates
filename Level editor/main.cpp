#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
private:
   std::string s;
};


std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
   std::string s;
   input >> s;
   const struct { const char * name; sf::Color color; } colors[]{
       { "yellow", sf::Color::Yellow },
       { "red",    sf::Color::Red },
       { "green", sf::Color::Green },
       { "blue",    sf::Color::Blue }
   };
   for( auto const & color : colors ){
       if( color.name == s ){ 
          rhs = color.color;
          return input;
       }
   }
   throw unknown_color( s );
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs){
    std::string position;
    std::string xPos;
    std::string yPos;
    bool comma = false;
    input >> position;
    unsigned int index;
    for (auto chr : position){
        if (chr == ','){
            comma = true;
            continue;
        }
        if (chr == '('){
            continue;
        }
        if (chr == ')'){
            break;
        }
        if (comma) {
            yPos += chr;
            
        } else {
            xPos += chr;
        }
    }
    rhs.x = strtof((xPos).c_str(),0);
    rhs.y = strtof((yPos).c_str(),0);
    return input;
}

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

#ifndef GAME_OPERATORS_HPP
#define GAME_OPERATORS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>


class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
private:
   std::string s;
};


static std::ifstream &operator>>( std::ifstream & input, sf::Color & rhs ){
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

static std::ifstream &operator>>(std::ifstream & input, sf::Vector2f & rhs){
    std::string position;
    std::string xPos;
    std::string yPos;
    bool comma = false;
    input >> position;
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


#endif
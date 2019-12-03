
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

    if (s[3] != ',' or s[7] != ',' or s[11] != ',')
        throw unknown_color( s );
    
    std::cout << int(s[0] + s[1] + s[2]) << std::endl;
    rhs.r = int(s[0] + s[1] + s[2]);
    rhs.g = int(s[4] + s[5] + s[6]);
    rhs.b = int(s[8] + s[9] + s[10]);
    rhs.a = int(s[12] + s[13] + s[14]);

    return input;

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
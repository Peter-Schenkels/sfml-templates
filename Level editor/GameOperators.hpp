
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

    std::string color[4];
    int pointer = 0;
    for ( auto item : s){

        if (item == ','){
            pointer++;
        }
        else {
            color[pointer] += item;
        }
    }
    
    rhs.r = strtof((color[0]).c_str(),0);
    rhs.g = strtof((color[1]).c_str(),0);
    rhs.b = strtof((color[2]).c_str(),0);
    rhs.a = strtof((color[3]).c_str(),0);


    return input;

}

static std::string &operator>>( std::string & input, sf::Color & rhs ){

    std::string s;
    input >> s;

    std::string color[4];
    int pointer = 0;
    for ( auto item : s){

        if (item == ','){
            pointer++;
        }
        else {
            color[pointer] += item;
        }
    }
    
    rhs.r = strtof((color[0]).c_str(),0);
    rhs.g = strtof((color[1]).c_str(),0);
    rhs.b = strtof((color[2]).c_str(),0);
    rhs.a = strtof((color[3]).c_str(),0);


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
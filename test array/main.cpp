#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>




class Ding  {

protected:
    std::string name;

public: 

    Ding( std::string & name):
        name(name)
    {}

    ~Ding();

    void getName(){
        std::cout << name << std::endl;
    }

    // virtual void draw(sf::RenderWindow & window);
};

class Doos : public Ding {
    sf::RectangleShape & body;

public: 
    Doos(sf::RectangleShape & body, std::string & name):
        Ding(name),
        body(body)
    {}

};

class Rondje : public Ding {
    sf::CircleShape & body;

public: 
    Rondje(sf::CircleShape & body, std::string & name):
        Ding(name),
        body(body)
    {}

};






int main() {

    Ding * container[100];
    auto bodietjeA= sf::RectangleShape{sf::Vector2f{2.0, 3.0}};
    auto bodietjeB= sf::CircleShape{20};
    std::string circle = "cirkonk";
    std::string rectangle = "Doons";
    for(unsigned int i = 0; i < 10; i++){
        if(i % 2 == 0){
            container[i] = new Doos(bodietjeA, rectangle);
        } else {
            container[i] = new Rondje(bodietjeB, circle);
        }
    }

    for (auto item : container){
        item->getName();
    }
}

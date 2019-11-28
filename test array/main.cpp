#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>




class Ding  {

private:
    sf::RectangleShape body;
    std::string name;

public: 

    Ding( sf::RectangleShape & body, std::string & name):
        body(body),
        name(name)
    {}

    void getName(){
        std::cout << name << std::endl;
    }
};







int main() {

    Ding * container[100];
    auto bodietje= sf::RectangleShape{sf::Vector2f{2.0, 3.0}};
    for(unsigned int i = 0; i < 10; i++){
        container[i] = new Ding(bodietje, std::to_string(i));
    }

    for (auto item : container){
        item->getName();
    }
}

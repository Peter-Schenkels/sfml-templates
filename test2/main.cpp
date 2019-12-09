#include <iostream>
#include <SFML/Graphics.hpp>


int main() {

    sf::Color rhs;
    rhs.g = 222;
    rhs.b = 222;
    rhs.r = 222;
    rhs.a = 222;

    int container[] = {rhs.r, rhs.g, rhs.b, rhs.a};

    std::cout << int(rhs.r) << std::endl;
    container[0] = 11;

    std::cout << int(rhs.r) << std::endl;



}
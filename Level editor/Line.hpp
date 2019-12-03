#ifndef LINE_HPP
#define LINE_HPP

#include "object.hpp"
#include <iostream>



class Line : public object {

private:

    sf::Vector2f end;
    sf::Color color;

public:

    Line(  
        sf::Vector2f start, 
        sf::Vector2f end,
        std::string name,
        sf::Color color
    );

    ~Line();

    void setColor(const sf::Color newColor){ color = newColor; };

    void update(){}

    void updateLength(sf::Vector2f newLength){ end = newLength; }

    sf::VertexArray getBody();

    void draw(sf::RenderWindow & window){ window.draw(getBody()); }

	void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection );

    std::string exportString() override;

};


#endif //LINE_HPP
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "object.hpp"
#include <iostream>

class Sprite : public object {

private:
    std::string imgLocation;
    sf::Vector2f sizeFactor;
    sf::Texture texture;
    sf::Sprite body;
    sf::Vector2f size;
    sf::Color color;
    
public:
    Sprite
        (
            sf::Vector2f position, 
            std::string imgLocation,  
            sf::Vector2f sizeFactor,
            std::string name,
            sf::Color color
        );

    ~Sprite();

    void loadTexture();

	void setColor(const sf::Color color) override { body.setColor(color); }

	void update() override { body.setPosition(position); }

	void draw(sf::RenderWindow & window) override { window.draw(body); }

    void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection  ) override;

	std::string exportString() override;



};




#endif
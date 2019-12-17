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

    Sprite()
    {

        sf::Vector2f position = {0,0};
        std::string imgLocation = "/";  
        sf::Vector2f sizeFactor = {1,1};
        std::string name = "Sprite";
        sf::Color color = {255,255,255,255};

    }

    Sprite
        (
            sf::Vector2f position, 
            std::string imgLocation,  
            sf::Vector2f sizeFactor,
            std::string name,
            sf::Color color
        );
    

    void loadTexture();

    void loadTexture(std::string newImageLocation);

	void setColor(const sf::Color color) override { body.setColor(color); }

	void update() override { body.setPosition(position); }

	void draw(sf::RenderWindow & window) override { window.draw(body); }

    void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection  ) override;

	std::string exportString() override;

    void setScale(sf::Vector2f scale) {body.setScale(scale); }

    void redo() {   

        
    }

};




#endif
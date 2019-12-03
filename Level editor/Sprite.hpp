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
    
public:
    Sprite(
            sf::Vector2f position, 
            std::string imgLocation,  
            sf::Vector2f sizeFactor,
            std::string name
        ):
            object(position, name),
            imgLocation(imgLocation),
            sizeFactor(sizeFactor)
        {
            loadTexture();
            body.setScale(sizeFactor);
            size.x = body.getLocalBounds().width;
            size.y = body.getLocalBounds().height;
        }

    ~Sprite();

    void loadTexture(){

        try{
            if(!texture.loadFromFile(imgLocation)){
                throw(imgLocation);
            }
            body.setTexture(texture);
        }
        catch(std::string e)
        {
            std::cout << "Unable to load texture: " << imgLocation << " to " << name << std::endl;
        }

    }

	void setColor(const sf::Color color) override {
        body.setColor(color);
    }

	void update() override {
        body.setPosition(position);
    }

	void draw(sf::RenderWindow & window) override { window.draw(body); }

    void mouseMove( sf::Vector2f mousePosition, bool & mouseSelection  ) override{

		if (body.getGlobalBounds().contains(mousePosition)){
			if(mouseSelection == false){
				selected = true;
				mouseSelection = true;
			}

			if (selected){
				move(sf::Vector2f(
					mousePosition.x - 20,
					mousePosition.y  - 20
					)
				);
			}

		}
	}

	std::string exportString() override {
    	std::string exportStr = "1 (" +
		std::to_string(position.x) + "," +
		std::to_string(position.y) + ") (" +
		std::to_string(sizeFactor.x) + "," +
		std::to_string(sizeFactor.y) + ") Sprite " +
		name + " " + imgLocation;

		return exportStr;        

    };



};




#endif
#include "Sprite.hpp"


Sprite::Sprite
    (
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

void Sprite::mouseMove( sf::Vector2f mousePosition, bool & mouseSelection  ) {

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

std::string Sprite::exportString() {

    std::string exportStr = "1 (" +
    std::to_string(position.x) + "," +
    std::to_string(position.y) + ") (" +
    std::to_string(sizeFactor.x) + "," +
    std::to_string(sizeFactor.y) + ") Sprite " +
    name + " " + imgLocation;

    return exportStr;        

};

void Sprite::loadTexture(){

    try{

        if(!texture.loadFromFile(imgLocation)){
            throw(imgLocation);
        }

        body.setTexture(texture);

    }

    catch(std::string e){

        std::cout << "Unable to load texture: " << imgLocation << " to " << name << std::endl;

    }

}
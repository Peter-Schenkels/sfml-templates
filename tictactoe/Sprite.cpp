#include "Sprite.hpp"


Sprite::Sprite
    (
        sf::Vector2f position, 
        std::string imgLocation,  
        sf::Vector2f sizeFactor = {1,1},
        std::string name = "Sprite",
        sf::Color color = {255,255,255,255}
    ):
        object(position, name),
        imgLocation(imgLocation),
        sizeFactor(sizeFactor),
        color(color)
{
    loadTexture();
    body.setScale(sizeFactor);
    size.x = body.getLocalBounds().width;
    size.y = body.getLocalBounds().height;
    setColor(color);
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
    std::to_string(sizeFactor.y) + ") Sprite " + name     
    + " " + std::to_string(color.r)
    + "," + std::to_string(color.g) 
    + ',' + std::to_string(color.b) 
    + "," + std::to_string(color.a)
    + " " + imgLocation;

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
//
// Created by pieper on 01-01-20.
//

#include "sprite.hpp"




void Sprite::set_texture(std::string img_location){
    texture.loadFromFile(img_location);
    body.setTexture(texture);
}

void Sprite::update(){
    body.setPosition(position);
    fake.setPosition(position);
    if (selected){
        fake.setOutlineThickness(2);
    } else {
        fake.setOutlineThickness(0);
    }
}

void Sprite::draw(sf::RenderWindow & window){
    window.draw(fake);
    window.draw(body);
}

json Sprite::export_to_json(json object) {  

    object["location"] = img_location;
    vector2f_to_json(object["factor"], size_factor);
    vector2f_to_json(object["position"], position);
    object["type"] = "Sprite";

    return object;

}
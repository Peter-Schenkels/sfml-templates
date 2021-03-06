//
// Created by pieper on 01-01-20.
//

#ifndef SFML_TEMPLATES_SPRITE_HPP
#define SFML_TEMPLATES_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

using namespace nlohmann;




///\brief 
/// drawable with an image
class Sprite : public Object{

    sf::Texture texture;
    sf::Sprite body;
    sf::RectangleShape fake;


public:
    sf::Vector2f size_factor;
    std::string img_location;

    Sprite(
        sf::Vector2f i_position,
        sf::Vector2f size_factor,
        std::string img_location
    ):
        Object({0,0}, {0,0}),
        size_factor(size_factor),
        img_location(img_location)
    {
        set_texture(img_location);
        body.setScale(size_factor);
        position  = i_position;
        size = sf::Vector2f(texture.getSize().x * size_factor.x, texture.getSize().y * size_factor.y);
        fake.setSize(size);
        fake.setOutlineThickness(0);
        fake.setOutlineColor(sf::Color::White);
    }
    
    void set_texture(std::string img_location);

    void update() override;

    void draw(sf::RenderWindow & window) override ;

    json export_to_json(json object) override;

};





#endif //SFML_TEMPLATES_SPRITE_HPP

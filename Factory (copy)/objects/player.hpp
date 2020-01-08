
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "object.hpp"
#include "sprite.hpp"
#include <SFML/Graphics.hpp>

class Player : public Object{

private:
    sf::Vector2f speed = {0,0};
    Sprite* body;
    float gravity = 0.5;


public:

    Player():
        Object(position, size)
    {}

    Player(sf::Vector2f start_position, sf::Vector2f size, Sprite*sprite):
        Object(position, size)
    {
        init(start_position, size, sprite);
    }

    void init(sf::Vector2f start_position, sf::Vector2f size, Sprite*sprite){
        body = sprite;
        body->set_sprite_size(size);
    }

    void draw(sf::RenderWindow & window){
        body->draw(window);
    }

    void update(){
        speed.y += gravity;
        position += speed;
        collision_box.update(position);
        body->set_position(position);
        body->update();
    }

    void collision(Object *object) override 
    { 
        collision_box.update(position); 

        if (collision_box.bottomSideIntersect(object->get_boundaries()) or 
            collision_box.topSideIntersect(object->get_boundaries())){
            speed.y = 0;
            std::cout << "daar" << std::endl;
        }

        if (collision_box.leftSideIntersect(object->get_boundaries())){
            if (collision_box.rightSideIntersect(object->get_boundaries())){
                speed.x = 0;
                std::cout << "daar gaan we" << std::endl;
            }
        }
            
        
    }

    json export_to_json(json object){ return ""; }

    

};



#endif
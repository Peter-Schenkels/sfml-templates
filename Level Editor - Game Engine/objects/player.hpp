
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "object.hpp"
#include "sprite.hpp"
#include <SFML/Graphics.hpp>

class Player : public Object
{

private:
    sf::Vector2f speed = {0, 0};
    Sprite *body;
    float gravity = 0.5;
    float resistance = 2;
    bool floating = false;
    bool on_ground = false;

public:
    Player(sf::Vector2f position, sf::Vector2f size) : Object(position, size)
    {
    }

    Player(sf::Vector2f position, sf::Vector2f size, Sprite *sprite) : Object(position, size)
    {
        init(sprite);
    }

    void init(Sprite *sprite)
    {
        body = sprite;
        body->set_sprite_size(size);
        body->set_position(position);
    }

    void draw(sf::RenderWindow &window)
    {
        body->draw(window);
        collision_box.draw(window);
    }

    void update()
    {
        if (!floating){
            speed.y += gravity;
            position += speed;
        }

        collision_box.update(position);
        body->set_position(position);
        body->update();
    }


    void set_static(bool boolean){
        floating = boolean;
    }


    //handles all input events
    void input(sf::Event event){
        //if key up is pressed: jump!
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && on_ground){
            speed.y = -20;
        } 
        //if key left is pressed: move left!
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            speed.x = -7;
        } else if (speed.x < 0) {
            speed.x += 5;
            if (speed.x > 0){
                speed.x = 0;
            }
        }
        //if key right is pressed: move right!
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            speed.x = 7;
        } else if (speed.x > 0) {
            speed.x -= 5;
            if (speed.x < 0){
                speed.x = 0;
            }
        }
    }

    //collision detection between a player and a sf::FloatRect
    void collision(sf::FloatRect rect) override
    {
        //check if a sf::FloatRect collides with the bottom  or top of the hitbox
        if (collision_box.bottomSideIntersect(rect) or
            collision_box.topSideIntersect(rect))
        {
            position.y -= speed.y;
            speed.y= 0;
            on_ground = true;
        } else {
            on_ground = false;
        }

        //check if a sf::FloatRect collides with the right  or left side of the hitbox
        if (collision_box.leftSideIntersect(rect))
        {
            speed.x = 0;
            position.x -= speed.x;
        }
        if (collision_box.rightSideIntersect(rect))
        {
            speed.x = 0;
            position.x -= speed.x;
        }
    }

    json export_to_json(json object) { return ""; }
};

#endif
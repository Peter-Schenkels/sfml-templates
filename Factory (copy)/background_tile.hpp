#ifndef background_tile_hpp
#define background_tile_hpp

#include "object.hpp"
#include "sprite.hpp"
#include "settings.hpp"



class background_tiles : public Object{

    Sprite body;

public:

    background_tiles(std::string location, sf::Vector2f sprite_size):
        Object(position, {WINDOW_SIZE_X, WINDOW_SIZE_Y}),
        body({0,0}, {1,1}, location)

    {
        body.set_sprite_size( sprite_size);
    }

    void draw(sf::RenderWindow & window){

        sf::Vector2i current_position;

        for(float x = 0; x < WINDOW_SIZE_X; x+=body.get_size().x){
            for(float y = 0;  y < WINDOW_SIZE_Y; y+=body.get_size().y){
                body.set_position({x,y});
                body.update();
                body.draw(window);
            }
        }

        body.set_position({0,0});

    }

    void update(){};

    json export_to_json(json object){ return "a"; };

};

class random_background_tiles : public Object{

    std::vector<Sprite> tiles;
    int seed[WINDOW_SIZE_X * WINDOW_SIZE_Y];

public:

    random_background_tiles(std::vector<Sprite> tiles, sf::Vector2f sprite_size):
        Object(position, {WINDOW_SIZE_X, WINDOW_SIZE_Y}),

        tiles(tiles)

    {

        for(auto sprite : tiles){
            sprite.set_sprite_size(sprite_size);
        }
        int iterations = WINDOW_SIZE_X * WINDOW_SIZE_Y;
        for(int i = 0; i < iterations; i++){
            seed[i] = rand_range(0, tiles.size()-1);

        }


    }


    void draw(sf::RenderWindow & window){

        sf::Vector2i current_position;
        int nr = 0;
        for(float x = 0; x < WINDOW_SIZE_X; x+=tiles[0].get_size().x){
            for(float y = 0;  y < WINDOW_SIZE_Y; y+=tiles[0].get_size().y){
                tiles[seed[nr]].set_position({x,y});
                tiles[seed[nr]].update();
                tiles[seed[nr]].draw(window);
                nr++;
            }
            nr++;
        }

    }

    void update(){};

    json export_to_json(json object){ return "a"; };

};






#endif
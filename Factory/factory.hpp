#ifndef factory_hpp
#define factory_hpp

#include "json.hpp"
#include <memory>
#include <iostream>
#include <fstream>
#include "object.hpp"
#include "rectangle.hpp"
#include "sprite.hpp"
#include "circle.hpp"

using namespace nlohmann;



///\brief
/// Class that acts following the factory pattern and reads json files
///\details
/// Class that acts following the factory pattern and reads json files
class Factory{

    std::vector<std::unique_ptr<Object>> container;
    json parsed;
    std::string filelocation;

public:
    ///\brief
    /// Filelocation: is file location of json file in std::string
    Factory(std::string filelocation):filelocation(filelocation){
        std::cout << "constructor: 1" << std::endl;
        std::ifstream file;
        file.open(filelocation);
        std::string s(std::istreambuf_iterator<char>(file), {});
        parsed = parsed.parse(s);
        std::cout << "constructor: 2" << std::endl;
    }

    ///\brief
    /// reads the json file and parses all the 
    /// read objects into an array as unique pointers
    void load(){
        std::cout << "load: 1" << std::endl;
        for (auto object : parsed){
            std::cout << "load" << std::endl;
            if (object["type"] == "Circle"){
                std::string color = color;
                container.push_back(std::unique_ptr<Circle>(
                    new Circle(
                        json_to_vector2f(object["position"]),
                        float(object["radius"]), 
                        json_to_color(object["color"])
                    )
                ));
            }
            else if (object["type"] == "Rectangle"){
                container.push_back(std::unique_ptr<Rectangle>(
                    new Rectangle(
                        json_to_vector2f(object["position"]), 
                        json_to_vector2f(object["size"]), 
                        json_to_color(object["color"]))
                    )
                );
            }
            else if (object["type"] == "Sprite"){
                container.push_back(std::unique_ptr<Sprite>(
                    new Sprite(
                        json_to_vector2f(object["position"]), 
                        json_to_vector2f(object["factor"]), 
                        object["location"])
                    )
                );
            } else {
                std::cout << "Unknown object type: " << object["type"] << std::endl;
            }
        }
    }

    ///\brief
    /// calls the update function on all the objects in the array
    void update(){
        for (auto & object : container){
            object->update();
        }
    }

    ///\brief
    /// calls the select function on all the objects in the array
    void select(sf::Event event){
        for (auto & object : container){
            object->select(event);
        }
    }

    ///\brief
    /// calls the draw function on all the objects in the array
    void draw(sf::RenderWindow & window){
        for (auto & object : container){
            object->draw(window);
        }
    }



    void save(){
        
        std::ofstream file;
        file.open(filelocation);
        json export_file;
        for (unsigned int i = 0; i < container.size(); i++){
            export_file[i] = container[i]->export_to_json(export_file[i]);
        }

        file << export_file;
        file.close();

    }




};


#endif
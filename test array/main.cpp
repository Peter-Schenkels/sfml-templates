#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>




class Ding  {

protected:
    std::string name;

public: 

    Ding( std::string & name):
        name(name)
    {}

    ~Ding();

    void getName(){
        std::cout << name << std::endl;
    }

    // virtual void draw(sf::RenderWindow & window);
};

class Doos : public Ding {
    sf::RectangleShape & body;

public: 
    Doos(sf::RectangleShape & body, std::string & name):
        Ding(name),
        body(body)
    {}

};

class Rondje : public Ding {
    sf::CircleShape & body;

public: 
    Rondje(sf::CircleShape & body, std::string & name):
        Ding(name),
        body(body)
    {}

};

class jerkel{
    
public:
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(10, 0);
    lines[1].position = sf::Vector2f(50, 20);





}





int main() {

    // Ding * container[100];
    // auto bodietjeA= sf::RectangleShape{sf::Vector2f{2.0, 3.0}};
    // auto bodietjeB= sf::CircleShape{20};
    // sf::RenderWindow window{ sf::VideoMode{ 1200, 700 }, "SFML window" };
    // std::string circle = "cirkonk";
    // std::string rectangle = "Doons";
    // for(unsigned int i = 0; i < 10; i++){
    //     if(i % 2 == 0){
    //         container[i] = new Doos(bodietjeA, rectangle);
    //     } else {
    //         container[i] = new Rondje(bodietjeB, circle);
    //     }
    // }

    // for (auto item : container){
    //     item->getName();
    // }


    sf::RenderWindow window{sf::VideoMode{640, 480}, "window"};
    window.setFramerateLimit(60);
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(10, 0);
    lines[1].position = sf::Vector2f(50, 20);

    while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(lines);
            window.display();   

        }
}

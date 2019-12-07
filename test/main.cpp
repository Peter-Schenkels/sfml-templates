#include <SFML/Graphics.hpp>
int sizeBalletjes = 0;




class balletje : public sf::CircleShape{


    sf::RenderWindow &window;
    public: 
    balletje(sf::RenderWindow &window):
    CircleShape(20),
    window(window)
    {}
    
    int speedX = 1;
    int speedY = 1;

    void update(){
        move(speedX, speedY);
        sizeBalletjes++;
    }

    void draw(){
        
        window.draw(*this);
    }

};



void updateDrawables(balletje balletjes[]){
    for(unsigned int bal = 0; bal < sizeBalletjes; bal++){

        balletjes[bal].draw();
       
    }



}

int main()
{

    sf::RenderWindow window{sf::VideoMode{640, 480}, "window"};
    window.setFramerateLimit(60);
    balletje balletje1(window);
    balletje balletje2(window);

    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(10, 0);
    lines[1].position = sf::Vector2f(500, 500);
    lines[0].color = {223,122,222,110};


    balletje2.setPosition(0, 100);
    balletje2.setFillColor(sf::Color::Blue);
    balletje2.speedY = -1;

    balletje balletjes[] = {balletje1, balletje2};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        updateDrawables(balletjes);
        window.draw(lines);
        window.display();   
        if(balletje1.getPosition() == balletje2.getPosition()){
            balletje1.speedY *= -1;
            balletje2.speedY *= -1;
        }
    }
}

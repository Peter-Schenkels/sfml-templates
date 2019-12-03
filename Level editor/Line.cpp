#include "Line.hpp"

Line::Line(
    sf::Vector2f start, 
    sf::Vector2f end,
    std::string name,
    sf::Color color
):
    object(start, name),
    end(end),
    color(color)
{
    setColor(color);
}


void Line::mouseMove( sf::Vector2f mousePosition, bool & mouseSelection ){

    if (getBody().getBounds().contains(mousePosition)){
        if(mouseSelection == false){
            selected = true;
            mouseSelection = true;
        }
        if (selected){
            move(sf::Vector2f(
                mousePosition.x - end.x / 2,
                mousePosition.y - end.y / 2
                )
            );
        }
    }

}


std::string Line::exportString() {
		std::string exportStr = "1 (" +
		std::to_string(position.x) + "," +
		std::to_string(position.y) + ") (" +
		std::to_string(end.x) + "," +
		std::to_string(end.y) + ") Line " + name 
        + " " + std::to_string(color.r)
        + "," + std::to_string(color.g) 
        + ',' + std::to_string(color.b) 
        + "," + std::to_string(color.a)
        + " /";

		return exportStr;
	}

sf::VertexArray Line::getBody(){
    sf::VertexArray body(sf::LinesStrip, 2);
    body[0].position = position;
    body[0].color = color;
    body[1].position = position + end;
    body[1].color = color;

    return body;
}


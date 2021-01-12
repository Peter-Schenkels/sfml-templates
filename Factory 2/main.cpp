#include "factory.hpp"

int main( int argc, char *argv[] )
{
	std::string save_file = "test.pipi";
	std::vector<Object*> drawables = import_objects(save_file);

	sf::RenderWindow window({500,500}, "window");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			objects_select(event, drawables);
			if (event.type == sf::Event::Closed)
			{
				window.close();
				export_save_file(save_file, drawables);		
			}	
		}
		for(auto object : drawables){
			object->draw(window);
		}
		window.display();
	};	
}


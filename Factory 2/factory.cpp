#include "factory.hpp"


void export_save_file(std::string & save_file_location, std::vector<Object*> & objects)
{
    std::ofstream save_file;
    save_file.open("test.pipi");
    if(save_file.is_open())
    {
        for(auto object : objects)
        {
            save_file << *object;
            std::cout << *object;
        }
        save_file.close();
    }
}

std::vector<std::vector<std::string>> parse_save_file(std::ifstream & save_file)
{
	std::string line;
	std::vector<std::vector<std::string>> objects;
	while(std::getline(save_file, line))
	{
		std::string feature_buffer = "";
		std::vector<std::string> object_buffer;
		std::cout << line << std::endl;
		if(line.back() == '>' && line.front() == '<')
		{
			for(auto character : line)
			{
				if(character == '>' || character == '<')
				{
					continue;
				}
				else if(character == ';')
				{
					object_buffer.push_back(feature_buffer);
					feature_buffer.clear();
				}
				else
				{
					feature_buffer += character;
				}
			}
			
			objects.push_back(object_buffer);
			object_buffer.clear();
		}				
		else
		{
			throw InvalidPinterPinkleburgFile();
		}

	}
	return objects;
}

Circle* parse_circle(std::vector<std::string> object)
{
	try
	{
		float position_x = std::stof(object[1]);
		float position_y = std::stof(object[2]);
		float diameter = std::stof(object[3]);
		uint8_t color_r = std::stoi(object[4]);
		uint8_t color_g = std::stoi(object[5]);
		uint8_t color_b = std::stoi(object[6]);
		uint8_t alpha = std::stoi(object[7]);
		return new Circle({position_x, position_y}, diameter, {color_r, color_g, color_b, alpha});
	}
	catch(std::exception & e)
	{
		std::cerr << "Something went wrong parsing object: " << object[0] << std::endl;
		std::cerr << e.what() << std::endl;
		return new Circle(sf::Vector2f{0,0}, 0, sf::Color::White);
	}
}


Picture* parse_picture(std::vector<std::string> object)
{
	try
	{
        if(object.size() == 6)
		{
            float position_x = std::stof(object[1]);
            float position_y = std::stof(object[2]);
            float size_x = std::stof(object[3]);
            float size_y = std::stof(object[4]);
            return new Picture({position_x, position_y}, {size_x, size_y}, object[5]);
        }
        else 
        {
            throw InvalidAmountOfParameters();
            return new Picture({0,0},{0,0}, "");
        }
	}
	catch(std::exception & e)
	{
		std::cerr << "Something went wrong parsing object: " << object[0] << std::endl;
		std::cerr << e.what() << std::endl;
		return new Picture({0,0},{0,0}, "");
	}
}

Line* parse_line(std::vector<std::string> object)
{
	try
	{
		if(object.size() == 9)
		{
			float position_x = std::stof(object[1]);
			float position_y = std::stof(object[2]);
			float end_x = std::stof(object[3]);
			float end_y = std::stof(object[4]);
			uint8_t color_r = std::stoi(object[5]);
			uint8_t color_g = std::stoi(object[6]);
			uint8_t color_b = std::stoi(object[7]);
			uint8_t alpha = std::stoi(object[8]);
			std::cout << end_x << " " << end_y << std::endl;
			return new Line({position_x, position_y}, {end_x, end_y}, {color_r, color_g, color_b, alpha});
		}
		else
		{
            throw InvalidAmountOfParameters();
			return new Line({0,0},{0,0}, sf::Color::White);
		}
	}
	catch(std::exception & e)
	{
		std::cerr << "Something went wrong parsing object: " << object[0] << std::endl;
		std::cerr << e.what() << std::endl;
		return new Line({0,0},{0,0}, sf::Color::White);
	}
}

Rectangle* parse_rectangle(std::vector<std::string> object)
{
	try
	{
        if(object.size() == 9)
        {
            float position_x = std::stof(object[1]);
            float position_y = std::stof(object[2]);
            float size_x = std::stof(object[3]);
            float size_y = std::stof(object[4]);
            uint8_t color_r = std::stoi(object[5]);
            uint8_t color_g = std::stoi(object[6]);
            uint8_t color_b = std::stoi(object[7]);
            uint8_t alpha = std::stoi(object[8]);
            return new Rectangle({position_x, position_y}, {size_x, size_y}, {color_r, color_g, color_b, alpha});
        }
        else
        {
            throw InvalidAmountOfParameters();
            return new Rectangle({0,0},{0,0}, sf::Color::White);
        }
	}
	catch(std::exception & e)
	{
		std::cerr << "Something went wrong parsing object: " << object[0] << std::endl;
		std::cerr << e.what() << std::endl;
		return new Rectangle({0,0},{0,0}, sf::Color::White);
	}
}

std::vector<Object*> convert_to_objects(std::vector<std::vector<std::string>> parsed_objects)
{
	std::vector<Object*> objects;
	for(auto object : parsed_objects)
	{
		try
		{
            if(object.size() > 0)
            {  
                if(object[0] == "Rectangle") objects.push_back(parse_rectangle(object));
                else if(object[0] == "Circle") objects.push_back(parse_circle(object));
                else if(object[0] == "Picture") objects.push_back(parse_picture(object));
                else if(object[0] == "Line") objects.push_back(parse_line(object));
                else
                {
                    throw UnknowObjectException();
                }
            }
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return objects;
}

void objects_select(sf::Event event, std::vector<Object*> drawables){
	for(auto object : drawables)
	{
		object->select(event);
	}
}

std::vector<Object*> import_objects(std::string & save_file_location)
{   
    std::ifstream save_file;
    save_file.open(save_file_location);
	std::vector<Object*> drawables;
	if( save_file.is_open() )
	{		
		std::cout <<"daar gaan we " << std::endl;
		std::vector<std::vector<std::string>> objects;
		objects = parse_save_file(save_file);				
		drawables = convert_to_objects(objects);	
	}
	save_file.close();
	return drawables;
}
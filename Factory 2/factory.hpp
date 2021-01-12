#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rectangle.hpp"
#include "circle.hpp"
#include "picture.hpp"
#include <sys/stat.h>
#include <unistd.h>
#include "line.hpp"


struct UnknowObjectException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Unknown Object";
    }
};

struct InvalidPinterPinkleburgFile : public std::exception
{
	const char * what () const throw ()
    {
    	return "invalid markup";
    }
};

struct InvalidAmountOfParameters : public std::exception
{
	const char * what () const throw ()
    {
    	return "The amount of given parameters is invalid";
    }
};

/**
 * @brief  Exports objects to a save file
 * @param  {std::string} save_file : The save file location
 * @param  {std::vector<Object*>} objects : The objects to export
 */
void export_save_file(std::string & save_file, std::vector<Object*> & objects);
/**
 * @brief  Parses the objects from the given savefile in PinterPinkleburg format to an std::vector<string>
 * @param  {std::string} save_file_location         : The save file location
 * @return {std::vector<std::vector<std::string>>}  : The imported string objects
 */
std::vector<std::vector<std::string>> parse_save_file(std::string & save_file_location);
/**
 * @brief  Parses a string in PinterPinkleburg format to an object
 * @param  {std::vector<std::string>} object : Given string object in PinterPinkleburg Format
 * @return {Circle*}                         : The derived object from the string
 */
Circle* parse_circle(std::vector<std::string> object);
/**
 * @brief  Parses a string in PinterPinkleburg format to an object
 * @param  {std::vector<std::string>} object : Given string vector in PinterPinkleburg Format
 * @return {Picture*}                        : Returns pointer to an object generated from the string file
 */
Picture* parse_picture(std::vector<std::string> object);
/**
 * @brief  Parses a string in PinterPinkleburg format to an object
 * @param  {std::vector<std::string>} object : Given string vector in PinterPinkleburg Format
 * @return {Line*}                           : Returns pointer to an object generated from the string file
 */
Line* parse_line(std::vector<std::string> object);
/**
 * @brief  Parses a string in PinterPinkleburg format to an object
 * @param  {std::vector<std::string>} object : Given string vector in PinterPinkleburg Format
 * @return {Rectangle*}                      : Returns pointer to an object generated from the string file
 */
Rectangle* parse_rectangle(std::vector<std::string> object);
/**
 * @brief  Parses a string in PinterPinkleburg format to an object
 * @param  {std::vector<std::string>} object : Given string vector in PinterPinkleburg Format
 * @return {Circle*}                         : Returns pointer to an object generated from the string file
 */
std::vector<Object*> convert_to_objects(std::vector<std::vector<std::string>> parsed_objects);
/**
 * @brief  Convert the string vector to objects
 * @param  {sf::Event} event       : 
 * @param  {std::vector<Object*} > : 
 */
void objects_select(sf::Event event, std::vector<Object*> drawables);
/**
 * @brief  Parses the objects from the given savefile in PinterPinkleburg format to objects
 * @param  {std::string} save_file : 
 * @return {std::vector<Object>*}  : 
 */
std::vector<Object*> import_objects(std::string & save_file);

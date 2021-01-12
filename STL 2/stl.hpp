#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <numeric>
#include <map>
#include <iterator>


struct sort_on_value {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};
/**
 * @brief Counts the lines and prints the amount on the terminal
 * @param  {std::vector<char>} bible_characters : The bible in a vector 
 */
void count_lines(std::vector<char> & bible_characters);
/**
 * @brief Counts the number of alphabetic characters in the vector and print the amount on the terminal
 * @param  {std::vector<char>} bible_characters : The bible in a vector
 */
void count_alpha(std::vector<char> & bible_characters);
/**
 * @brief Counts the amount of times an alphabetic characters appears in the vector and prints them sorted on key and value
 * @param  {std::vector<char>} bible_characters : The bible in a vector
 */
void sort_on_size_and_alphabet(std::vector<char> & bible_characters);
/**
 * @brief Counts the amount of times a word appears in the vector and prints the top 10 most common words.
 * @param  {std::vector<char>} bible_characters : The bible in a vector
 */
void print_top_10_most_common_words(std::vector<char> & bible_characters);
#include "stl.hpp"

void count_lines(std::vector<char> & bible_characters)
{
    int amount = std::count(bible_characters.begin(), bible_characters.end(), '\n'); 
    std::cout << "\nAmount of lines: " << amount << std::endl;
}

bool isAlphaNum(unsigned char x){return std::isalnum(x);}

void count_alpha(std::vector<char> & bible_characters)
{
        auto amount = std::count_if(bible_characters.begin(), 
            bible_characters.end(),
                isAlphaNum
                ) ;
        std::cout << "\nAmount of alphabetic characters: " << amount << std::endl;  
}

void sort_on_size_and_alphabet(std::vector<char> & bible_characters)
{
    std::map<char, int> library;
    for(auto character : bible_characters)
    {
        if(std::isalpha(character))
        {
            library[character] += 1;
        }
    }

    std::cout << "\nSorted on alphabet" << std::endl;
    for(auto letter : library){
        std::cout << letter.first << " | " << letter.second << std::endl;
    }

    std::cout << "\nSorted on size" << std::endl;
    std::vector<std::pair<char, int> > library_sorted(library.begin(), library.end());
    std::sort
    (
        library_sorted.begin(), 
        library_sorted.end(), 
        [](auto &left, auto &right) 
        {
            return left.second > right.second;
        }
    );
    for(auto letter : library_sorted){
        std::cout << letter.first << " | " << letter.second << std::endl;
    }
}

void print_top_10_most_common_words(std::vector<char> & bible_characters)
{
    std::string word_buffer;
    std::map<std::string, int> words;
    for(auto character : bible_characters)
    {
        if(std::isalpha(character)) 
        {
            word_buffer += character;
        }
        else 
        {
            if(word_buffer != "")
            {
                words[word_buffer] += 1;
                word_buffer = "";
            }
        }
    }
    std::vector<std::pair<std::string, int> > words_sorted(words.begin(), words.end());
    std::sort
    (
        words_sorted.begin(), 
        words_sorted.end(), 
        [](auto &left, auto &right) 
        {
            return left.second > right.second;
        }
    );

    std::cout << "\nTop 10 most common words:" << std::endl;
    for (uint8_t i = 0; i < 10; ++i)
    {
        std::cout << words_sorted[i].first << " | " << words_sorted[i].second << std::endl;
    }   
}



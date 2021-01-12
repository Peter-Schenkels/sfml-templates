#include "stl.hpp"

int main()
{
    std::ifstream file;
    file.open("pg10.txt");
    if(file.is_open())
    {
        //Read all characters and put them in a vector
        std::vector<char> bible_characters ((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());; 
        std::cout << "\nAmount of characters: " << bible_characters.size() << std::endl;
        //Count lines
        count_lines(bible_characters);
        //Count alphabetic characters
        count_alpha(bible_characters);
        //All to lowercase
        std::for_each( bible_characters.begin(), bible_characters.end(), [](char & c){c = std::tolower(c);});
        //Sort on size and alphabet alphabet
        sort_on_size_and_alphabet(bible_characters);
        //Print the 10 most common words;
        print_top_10_most_common_words(bible_characters);

    }
}
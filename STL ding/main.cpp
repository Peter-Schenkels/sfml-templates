#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <numeric>
#include <map>
#include "STL.hpp"


int main(){


    std::ifstream file;
    openFile(file, "pg10.txt");
    
    std::vector<char> characters ((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    unsigned int amountCharacters = characters.size();
    unsigned int amountLines = std::count(characters.begin(), characters.end(), '\n'); 
    unsigned int amountAlpha = getNoAlpha(characters);
    converToLowercase(characters);
    getAmountAlphabetic(characters);
    file.close();
    openFile(file, "pg10.txt");
    countAndPrintWords(file);


}
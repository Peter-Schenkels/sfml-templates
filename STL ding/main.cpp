#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <numeric>
#include <map>

void openFile(std::ifstream & file, std::string directory){

    try{
        file.open(directory);
        if (!file.is_open()){
            throw(directory);
        }
    }
    catch(std::string file){
        std::cerr << "File failed to open:" << directory << std::endl;
    }

}

int getNoAlpha(const std::vector<char> & characters){

    int amount = 0;

    for(auto item : characters){
        if(std::isalpha(item))amount++;
    }

    return amount;
}

void converToLowercase(std::vector<char> & characters){
    for(auto & item : characters){
        if(item > 64 && item < 91)item += 'a' - 'A';     
    }
}

class CharCounter{

private:
    int characters[123] = {0};

public:
    CharCounter(){};

    void add(const char& character){
        if (character < 123)
            characters[character]++;
    }

    int get(const char character){      
        if (character < 123)
            return characters[character];
    }

};


void getAmountAlphabetic(std::vector<char> characters){

    CharCounter counter;
    
    for(auto item : characters){
        counter.add(item);
    }
    for(unsigned int i = 65; i < 91; i++){
        if(std::isalpha(i))
            std::cout << char(i) << ":" << counter.get(i) + counter.get(i + ('a' - 'A')) << std::endl;
    }
    
}


void countAndPrintWords(std::ifstream & file){
    
    std::string s;
    std::map<std::string, int> counters; // store each word and an associated counter
    
    // read the input, keeping track of each word and how often we see it
    while (file >> s)
        ++counters[s];
    
    // write the words and associated counts
    int count = 0;
    for (auto item : counters)
    {
        std::cout << item.first << "\t" << item.second << std::endl;
    }
}

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
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <numeric>
#include <map>

#ifndef STL_HPP
#define STL_HPP

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

typedef std::pair<std::string,int> pair;
void countAndPrintWords(std::ifstream & file){
    
    std::string s;
    std::map<std::string, int> counters; 
    
    while (file >> s)
        ++counters[s];

    std::vector<std::pair<std::string,int>> vec;
    std::copy(
            counters.begin(), 
            counters.end(), 
            std::back_inserter<std::vector<pair>>(vec)
        );

        std::sort(
            vec.begin(), 
            vec.end(),
            [](const pair& fi, const pair& r) {
                
                if(fi.second != r.second)
                    return fi.second > r.second;

                return fi.first > r.first;
        
            }
        );
        
        int count =0;
        for (auto const &item: vec) {
            if(count==10)break;
            std::cout << item.first << " " << item.second << std::endl;\
            count++;
        }
        


}

#endif
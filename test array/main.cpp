#include <iostream>
#include <string>
#include <vector>









int main(){

    std::string ding = "ohoho\nahahaha\nnenenee e ";
    std::string buffer = "";
    std::vector<std::string> Lines;

    for (auto character : ding){
        if (character == '\n'){
            Lines.push_back(buffer);
            buffer = "";
        } else {
            buffer += character;
        }
        
    }
    Lines.push_back(buffer);
    buffer = "";

    for (auto line : Lines){
        std::cout << line << std::endl;
    }



}
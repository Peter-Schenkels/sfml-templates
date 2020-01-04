#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>




class bird{
    std::string name;

public:
    bird(std::string name):
        name(name)
    {
        std::cout << "there we fliegt " << name << std::endl;
    }
    ~bird(){
        std::cout << "there goes " << name << std::endl;
    }

    void nothing(){};
};

template <typename T>
class deleter{
    T * body;

public:
    deleter(T * body):
        body(body)
    {}

    ~deleter(){
        delete body;
    }

    T *operator*() const{
        return * body;
    }

    T *operator->() const{
        return body;
    }
};







int main()
{
    bird jekrel = bird("jerkel");
    auto kinkel = std::make_unique<bird>("kinkel");
    jekrel.nothing();
    kinkel->nothing();
    kinkel.reset(new bird("jerke"));



}
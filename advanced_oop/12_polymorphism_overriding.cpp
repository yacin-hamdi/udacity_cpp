#include<iostream>
#include<string>
#include<cassert>

class Animal{
    public:
        virtual std::string talk() const = 0;
};

class Cat:public Animal{
    public:
        std::string talk() const override{
            return std::string("meaw");
        }
};

class Dog:public Animal{
    public:
    std::string talk() const override{
        return std::string("oww");
    }
};




int main(){
    Cat cat;
    Dog dog;
    std::cout << cat.talk() << std::endl;
    std::cout << dog.talk() << std::endl;

}
#include<iostream>
#include<string>
#include<cassert>


class Animal{
    public:
        int age;
};

class Pet{
    public:
        std::string name;
};


class Dog:public Animal, public Pet{
    public:
        std::string color;

};

class Cat:public Animal, public Pet{
    public:
        std::string color;
};


int main(){
    Dog dog;
    Cat cat;

    dog.age = 12;
    dog.name = "smith";
    dog.color = "black";

    cat.age = 13;
    cat.name = "big D";
    cat.color = "white";

    assert(dog.age == 12);
    assert(dog.name == "smith");
    assert(dog.color == "black");

    assert(cat.age == 13);
    assert(cat.name == "big D");
    assert(cat.color == "white");

}

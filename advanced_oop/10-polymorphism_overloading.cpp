#include<iostream>
#include<string>

class Human{};
class Dog{};
class Cat{};
class Plant{};

void hello(){
    std::cout << "hello world\n";
}

void hello(Human human){
    std::cout << "hello human\n";
}
void hello(Dog dog){
    std::cout << "hello dog\n";
}

void hello(Cat cat){
    std::cout << "hello cat\n";
}

void hello(Plant plant){
    std::cout << "hello plant\n";
}


int main(){
    hello();
    hello(Human());
    hello(Plant());
    hello(Dog());
    hello(Cat());
}
#include<iostream>
#include<memory>

class MyClass{
    public:
        void methodClass(){
            std::cout << "MyClass::methodClass()" << std::endl;
        }
};


int main(){
    std::unique_ptr<MyClass> ptr1(new MyClass);

    ptr1->methodClass();
    std::cout << ptr1.get() << std::endl;

    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    ptr2->methodClass();
    
    std::cout << ptr1.get() << std::endl;
    std::cout << ptr2.get() << std::endl;

    std::unique_ptr<MyClass> ptr3 = std::move(ptr2);
    ptr3->methodClass();

    std::cout << ptr1.get() << std::endl;
    std::cout << ptr2.get() << std::endl;
    std::cout << ptr3.get() << std::endl;

    return 0;

}
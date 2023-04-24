#include<iostream>
#include<memory>

class MyClass{
    public:
        void method(){
            std::cout << "MyClass::method()" << std::endl;
        }
};


int main(){
    std::shared_ptr<MyClass> ptr1(new MyClass);
    ptr1->method();
    std::cout << ptr1.get() << std::endl;

    std::shared_ptr<MyClass> ptr2 = ptr1;
    ptr2->method();
    ptr1->method();
    std::cout << ptr1.get() << std::endl;
    std::cout << ptr2.get() << std::endl;

    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;

    ptr1.reset();
    std::cout << ptr1.get() << std::endl;
    std::cout << ptr2.get() << std::endl;

    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;





    return 0;
}
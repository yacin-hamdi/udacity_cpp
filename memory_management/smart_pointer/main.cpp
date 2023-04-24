#include<iostream>
#include<memory>
#include<vector>


class TestUnique{
    private:
        std::unique_ptr<int> ptr_;
    
    public:
        TestUnique(int val):ptr_(new int(val)){}
        TestUnique():ptr_(new int(0)){}

        int getVal() const{
            return *ptr_;
        }

};


int main(){

    std::vector<std::shared_ptr<TestUnique>> pointer_container;
    pointer_container.push_back(std::make_shared<TestUnique>(TestUnique(52)));
    pointer_container.push_back(std::make_shared<TestUnique>(TestUnique(11)));

    for (int i=0;i<pointer_container.size();i++){
        std::cout << &pointer_container[i] << ":"<<  (*pointer_container[i]).getVal() << std::endl;
    }
    // std::unique_ptr<int> ptr1(new int);
    // *ptr1 = 10;
    // std::cout << "address: " << &ptr1 << ", value: " << *ptr1 << std::endl;
    // std::unique_ptr<int> ptr2=std::move(ptr1);

    // std::cout << "address: " << ptr2.get()<< ", value: " << *ptr2 << std::endl;
 

    // std::shared_ptr<int> ptr1(new int(20));
    // std::shared_ptr<int> ptr2 = ptr1;
    // std::cout << "ptr1 address: " << ptr1.get() << ", value: " << *ptr1<< std::endl;
    // std::cout << "ptr2 address: " << ptr2.get() << ", value: " << *ptr2 << std::endl;
    

}
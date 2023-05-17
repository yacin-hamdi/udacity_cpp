#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    std::vector<float> vec {1,2,3,4,5};
    std::for_each(vec.begin(), vec.end(),[](float a){
        std::cout << a << " ";
    });
    std::cout << std::endl;

    return 0;
}
#include<iostream>

template <typename Type> Type sum(Type a, Type b){
    return a + b;
}

template<typename Type> Type sub(Type a, Type b){
    return a - b;
}

template<typename Type>Type mul(Type a, Type b){
    return a * b;
}

template<typename Type> Type div(Type a, Type b){
    return a/b;
}

template<typename T>T returnMax(T a, T b){
    if(a>b)
        return a;
    else
        return b;
}

int main(){

    std::cout << sum<double>(1.2, 1.4) << std::endl;
    std::cout << mul<int>(3, 4) << std::endl;
    std::cout << div<float>(5,1) << std::endl;
    std::cout << sub<int>('B', 'A') << std::endl;

    std::cout << returnMax(1, 2) << std::endl;
}
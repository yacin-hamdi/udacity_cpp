#include<iostream>
#include<vector>
#include<algorithm>

template<typename T> void print(std::vector<T> v){
    for(int i=0;i<v.size();i++)
        std::cout<< v[i] << std::endl;
}

template<typename T> bool sorting(T a, T b){
    return a > b;
}

int main(){
    std::vector vect {1,2,3,4,5};
    print(vect);
    std::sort(vect.begin(), vect.end(), sorting<int>);
    std::cout << "------------------\n";
    print(vect);
    std::vector chars{'a', 'b', 'c', 'd', 'e'};
    std::cout << "------------------\n";
    print(chars);
    std::sort(chars.begin(), chars.end(), sorting<char>);
    std::cout << "------------------\n";
    print(chars);

}
#include<iostream>
#include<cstring>
#include<cstdlib>


int main(){
    int *ptr = nullptr;
    ptr = (int*) malloc(4*sizeof(int));

    for (int i=0;i<4;i++){
        memset(&ptr[i], 'A'+i, 1);
    }

    for(int i=0;i<4;i++){
        std::cout << "address: " << &ptr[i] << ", value: " << char(ptr[i]) << std::endl;
    }


    return 0;
}
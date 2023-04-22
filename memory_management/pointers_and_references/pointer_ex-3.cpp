/* LAB 3
 * 
 * - Objectives 3
 * 
 * In this example we are going to try to create dynamic array for integers. 
 * With this we can get primitive overview of how some of the popular container libraries 
 * in C++ work, such as : vector, queqe, stack etc. We know that dynamic declaration of 
 * array was initially supported in C++, but we don't have option to do resize or 
 * similar operation once array has been declared. Via pointers and access to memory 
 * it is pretty simple. So we are going to try to create couple of functions. 
 * First one is "createArr" which will create our array with specified size as input. 
 * Second one is going to be "resizeArr" which will resize our array and preserve our data. 
 * For the purpose of this example, to preserve simplicity 
 * we will only allow to expand our array to specified number of places.
 * */

#include<iostream>


int *createArr(int size){
    return new int[size];
}

void pushArray(int *arr, int size){
    for (int i=0;i<size;i++){
        arr[i] = i;
    }
}

void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int *resizeArr(int*arr, int size, int new_size){
    int*new_arr =new int[new_size];
    for(int i=0;i<size;i++){
        new_arr[i] = arr[i];
    }
    delete arr;
    return new_arr;
}



int main(){
    int size;
    std::cout << "size: ";
    std::cin >> size;
    int* arr = createArr(size);
    pushArray(arr, size);
    printArray(arr, size);

    int new_size;
    std::cout << "new_size > " << size << " : ";
    std::cin >> new_size;
    int *new_arr = resizeArr(arr, size, new_size);
    printArray(new_arr, new_size);
    pushArray(new_arr, new_size);
    printArray(new_arr, new_size);

    
}
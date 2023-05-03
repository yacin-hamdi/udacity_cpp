#include<iostream>
#include<thread>
#include<vector>




int main(){
    std::vector<std::thread> threads;

    for(int i=0;i<10;i++){
        threads.emplace_back(std::thread([i](){
            std::this_thread::sleep_for(std::chrono::milliseconds(10*i));
            std::cout << "thread id is "<< i  << std::endl;
        }));
    }
    for(auto &t:threads){
        t.join();
    }

    return 0;
}
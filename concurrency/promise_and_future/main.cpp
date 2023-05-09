#include<iostream>
#include<thread>
#include<future>
#include<cmath>


void divVal(std::promise<double>&&prms, double num, double denom){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    try{
        if(denom == 0){
            throw std::runtime_error("division by zero");
        }else{
            prms.set_value(num/denom);
        }

    }catch(...){
        prms.set_exception(std::current_exception());

    }
}

int main(){

    double num = 15;
    double denom = 1;
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(divVal, std::move(prms), num, denom);
    
    try{
        std::cout << " result = " <<  ftr.get() << std::endl;
    }catch(std::runtime_error e){
        std::cout << e.what() << std::endl;
    }

    t.join();


    

   


    return 0;
}
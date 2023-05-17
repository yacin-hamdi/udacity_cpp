#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <memory>
#include <algorithm>
#include <future>


class Vehicle{
    public:
        Vehicle(int id):_id(id){}
        int getId(){return this->_id;}

    private:
        int _id;
};


class WatingVehicle{
    public:
        WatingVehicle(){}

        bool dataIsAvailable(){
            std::lock_guard<std::mutex> lck(mtx);
            return !_vehicles.empty();
        }


        Vehicle popBack(){
            std::lock_guard<std::mutex> lck(mtx);
            Vehicle v = std::move(_vehicles.back());
            _vehicles.pop_back();
            _counterV--;
            return v;
        }



        void pushBack(Vehicle &&v){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::lock_guard<std::mutex> lck(mtx);
            std::cout << "vehicle#" << v.getId() << " will be added to the queue" << std::endl;
            _vehicles.emplace_back(std::move(v));
            ++_counterV;

            
        } 

        int getCounter(){
            std::lock_guard<std::mutex> lck(mtx);
            return _counterV;}






    private:
        std::vector<Vehicle> _vehicles;
        std::mutex mtx;
        int _counterV=0;

};



int main(){

    std::shared_ptr<WatingVehicle> queue(new WatingVehicle);
    std::vector<std::future<void>> futures;
    for (int i=0;i<10;i++){
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WatingVehicle::pushBack, queue, std::move(v)));
    }

    while(true){
        if(queue->dataIsAvailable()){
            
            Vehicle v = queue->popBack();
            std::cout << "vehicle#" << v.getId() << " has been remove from the queue" << std::endl;
            
            if(queue->getCounter() <=0){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "finished processing queue" << std::endl;
                break;
            }
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr){
        ftr.wait();
    });

    std::cout << "left " << queue->getCounter() << " vehicle in the queue" << std::endl;

    
    return 0;
}
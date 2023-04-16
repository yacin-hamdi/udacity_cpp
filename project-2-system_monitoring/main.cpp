#include <algorithm>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include "constants.h"
#include "util.h"

float get_sys_active_cpu_time(std::vector<std::string> values)
{
    return (stof(values[CPUStates::S_USER]) +
            stof(values[CPUStates::S_NICE]) +
            stof(values[CPUStates::S_SYSTEM]) +
            stof(values[CPUStates::S_IRQ]) +
            stof(values[CPUStates::S_SOFTIRQ]) +
            stof(values[CPUStates::S_STEAL]) +
            stof(values[CPUStates::S_GUEST]) +
            stof(values[CPUStates::S_GUEST_NICE]));
}

float get_sys_idle_cpu_time(std::vector<std::string>values)
{
    return (stof(values[CPUStates::S_IDLE]) + stof(values[CPUStates::S_IOWAIT]));
}

class ProcessParser{
    public:
        static std::string getCmd(std::string pid);
        static long int getSysUpTime();
        static std::string getProcUpTime(std::string pid);
        static std::string getProcUser(std::string pid);
        static std::string getVmSize(std::string pid);
        static std::string getCpuPercent(std::string pid);
        static std::vector<std::string> getPidList();
        static int getNumberOfCores();
        static std::vector<std::string> getSysCpuPercent(std::string core_number);
};


std::vector<std::string> ProcessParser::getSysCpuPercent(std::string core_number){
    std::string path = Path::basePath() + Path::statPath();
    std::string name = "cpu" + core_number;
    std::ifstream stream = Util::getStream(path);
    std::string line;
    while(getline(stream, line)){
        if(line.compare(0, name.size(), name) == 0){
            std::istringstream mystream(line);
            std::istream_iterator<std::string> beg(mystream), end;
            std::vector<std::string>results(beg, end);
            return results;
        }
    }

    return std::vector<std::string>{};

}


int ProcessParser::getNumberOfCores(){
    std::string path = Path::basePath() + "cpuinfo";
    std::ifstream stream = Util::getStream(path);
    std::string line;
    std::string name = "cpu cores";
    int result = 0;
    while(getline(stream, line)){
        if(line.compare(0, name.size(), name) == 0){
            std::istringstream mystream(line);
            std::istream_iterator<std::string>beg(mystream), end;
            std::vector<std::string> results(beg, end);
            result = stoi(results[3]);
            break;
        }
    }

    return result;
}

std::vector<std::string> ProcessParser::getPidList(){
    DIR *dir;
    std::vector<std::string> container{};

    if(!(dir = opendir("/proc")))
        throw std::runtime_error(std::strerror(errno));
    
    while(dirent* dirp = readdir(dir)){
        if(dirp->d_type != DT_DIR)
            continue;
        
        if (std::all_of(dirp->d_name, dirp->d_name + std::strlen(dirp->d_name), [](char c){ return std::isdigit(c); })) {
           container.push_back(dirp->d_name);
        }
    }

    if(closedir(dir))
        throw std::runtime_error(std::strerror(errno));
    
    return container;
}

std::string ProcessParser::getCpuPercent(std::string pid){
    std::string path = Path::basePath() + pid + "/" + Path::statPath();
    std::ifstream stream = Util::getStream(path);
    std::string line;
    getline(stream, line);
    std::istringstream mystream(line);
    std::istream_iterator<std::string>beg(mystream), end;
    std::vector<std::string> results(beg, end);
    
    float utime = stof(ProcessParser::getProcUpTime(pid));
    float uptime = ProcessParser::getSysUpTime();
    float stime = stof(results[14]);
    float cutime = stof(results[15]);
    float cstime = stof(results[16]);
    float starttime = stof(results[21]);
    float freq = sysconf(_SC_CLK_TCK);

    float total_time = utime + stime + cutime + cstime;
    float seconds = uptime - (starttime/freq);
    std::string result = std::to_string(100.0 * ((total_time)/freq)/seconds);
    return result;


}

std::string ProcessParser::getVmSize(std::string pid){
    std::string path = Path::basePath() + pid + Path::statusPath();
    std::ifstream stream = Util::getStream(path);
    std::string line;
    std::string name = "VmData:";
    std::string result;
    
    while(getline(stream, line)){
        if(line.compare(0, name.size(), name) == 0){
            std::istringstream my_stream(line);
            std::istream_iterator<std::string>beg(my_stream), end;
            std::vector<std::string> results(beg, end);
            result = std::to_string(stof(results[1])/float(1024*1024));
            break;

        }
    }

    return result;
}

std::string ProcessParser::getProcUser(std::string pid){
    std::string path = Path::basePath() + pid + Path::statusPath();
    std::ifstream stream = Util::getStream(path);
    std::string line;
    std::string name {"Uid:"};
    std::string result;
    while(getline(stream, line)){
        if(line.compare(0, name.size(), name) == 0){
            std::istringstream my_stream(line);
            std::istream_iterator<std::string>beg(my_stream), end;
            std::vector<std::string> results(beg, end);
            result = results[1];
            break;
        }
    }

    name = ":x:"+result;
    stream = Util::getStream("/etc/passwd");
    while(getline(stream, line)){
        if(line.find(name) != std::string::npos){
            result = line.substr(0, line.find(":"));
            return result;
        }
    }



    return " ";
}

std::string ProcessParser::getCmd(std::string pid){
    std::string path = Path::basePath() + pid + Path::cmdPath();
    std::ifstream stream = Util::getStream(path);
    std::string cmd;
    getline(stream, cmd);
    return cmd;

}


long int ProcessParser::getSysUpTime(){
    long int tm = 0;
    std::string path = Path::basePath() + Path::upTimePath();
    std::ifstream stream = Util::getStream(path);
    std::string time;
    getline(stream, time);
    std::istringstream my_stream(time);
    my_stream >> tm;


    return tm;
}

std::string ProcessParser::getProcUpTime(std::string pid){
    std::string path = Path::basePath() + pid + "/" + Path::statPath();
    std::ifstream stream = Util::getStream(path);
    std::string line;
    getline(stream, line);
    std::istringstream buf(line);
    std::istream_iterator<std::string>beg(buf), end;
    std::vector<std::string> results(beg, end);
    return std::to_string(float(stof(results[13])/sysconf(_SC_CLK_TCK)));
}



int main(){
    std::vector<std::string> results = ProcessParser::getSysCpuPercent("0");
    for(auto s:results){
        std::cout << s << " ";
    }

    std::cout << std::endl;

    std::cout << get_sys_active_cpu_time(results);
    

    return 0;
}

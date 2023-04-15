#include<iostream>
#include<cassert>
#include<string>
#include "util.h"
#include "constants.h"
#include<vector>
#include<sstream>
#include<unistd.h>
#include<iterator>
class ProcessParser{
    public:
        static std::string getCmd(std::string pid);
        static long int getSysUpTime();
        static std::string getProcUpTime(std::string pid);
        static std::string getProcUser(std::string pid);
};

std::string ProcessParser::getProcUser(std::string pid){
    std::string name = "Uid:";
    std::string path = Path::basePath() + pid + Path::statusPath();
    std::ifstream stream = Util::getStream(path);
    std::string line;
    std::string result;
    while(getline(stream, line)){
        if(line.compare(0, name.size(), name) == 0){
            std::istringstream buf(line);
            std::istream_iterator<std::string>beg(buf), end;
            std::vector<std::string> results(beg, end);
            result = results[1];
            break;
        }
    }

    stream = Util::getStream("/etc/passwd");
    name = "x:"+result;
    while(getline(stream, line)){
        if(line.compare(0,name.size(), name)==1){
            result = line;
            break;
        }
    }

    return result;
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
    std::cout << ProcessParser::getProcUser("6048") << std::endl;
    return 0;
}

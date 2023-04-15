#include<fstream>
#include<string>


class Util{
    public:
        static std::ifstream getStream(std::string path);
        static std::string convertToTime(long int seconds);
        static std::string getProgressBar(std::string percent);
};

std::ifstream Util::getStream(std::string path){
    std::ifstream stream(path);
    if(!stream)
        throw std::runtime_error("non existing PID!");
    else    
        return stream;
}

std::string Util::convertToTime(long int input_seconds){
    long minutes = input_seconds / 60;
    long hours = minutes / 60;
    long seconds = int(input_seconds%60);
    minutes = int(minutes%60);

    std::string time = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
    return time;
}

std::string Util::getProgressBar(std::string percent){
    int _size = 50;
    std::string result {"0% "};
    int boundaries = (stof(percent)/100)*_size;
    for (int i=0;i<_size;i++){
        if(i <= boundaries)
            result +="|";
        else    
            result += " ";
    }

    result += " " + percent.substr(0, 5) + "/100%";

    return result;
}
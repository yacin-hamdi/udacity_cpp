#include<string>
#include "processparser.h"

class Process{
    private:
        std::string pid;
        std::string user;
        std::string uptime;
        std::string mem;
        std::string cmd;
        std::string cpu;
    
    public:
        Process(std::string pid){
            this->pid = pid;
            this->user = ProcessParser::getProcUser(pid);
            this->uptime = ProcessParser::getProcUpTime(pid);
            this->mem = ProcessParser::getVmSize(pid);
            this->cmd = ProcessParser::getCmd(pid);
            this->cpu = ProcessParser::getCpuPercent(pid);
        }

        void setPid(std::string pid);
        std::string getPid() const;
        std::string getUser() const;
        std::string getUptime() const;
        std::string getMem() const;
        std::string getCmd() const;
        std::string getCpu() const;

        std::string getProcess();
        
};

void Process::setPid(std::string pid){
    this->pid = pid;
}

std::string Process::getPid() const{ return this->pid; }
std::string Process::getUser() const{ return this->user; }
std::string Process::getUptime() const{ return this->uptime; }
std::string Process::getMem() const { return this->mem; }
std::string Process::getCmd() const { return this->cmd; }
std::string Process::getCpu() const { return this->cpu; }

std::string Process::getProcess(){
    this->mem = ProcessParser::getVmSize(this->pid);
    this->uptime = ProcessParser::getProcUpTime(this->pid);
    this->cpu = ProcessParser::getCpuPercent(this->pid);

    return this->pid + " " 
            + this->user + " " 
            + this->mem.substr(0,5) + " " 
            + this->cpu.substr(0,5) + " " 
            + this->uptime.substr(0,5) + " " 
            + this->cmd.substr(0,30)
            + "...";

}




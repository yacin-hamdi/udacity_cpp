
#pragma once

#include "processparser.h"

class SysInfo{

    private:
        std::vector<std::string> lastCpuStats;
        std::vector<std::string> currentCpuStats;
        std::vector<std::string> coresStats;
        std::vector<std::vector<std::string>> lastCpuCoresStats;
        std::vector<std::vector<std::string>> currentCpuCoresStats;
        std::string cpuPercent;
        float memPercent;
        std::string osName;
        std::string kernelVer;
        long upTime;
        int totalProc;
        int runningProc;
        int threads;
    public:
        SysInfo(){
            this->getOtherCores(ProcessParser::getNumberOfCores());
            this->setLastCpuMeasures();
            this->setAttributes();
            this->osName = ProcessParser::getOsName();
            this->kernelVer = ProcessParser::getSysKernelVersion();
        }


        void setAttributes();
        void setLastCpuMeasures();
        std::string getMemPercent() const;
        long getUpTime() const;
        std::string getThreads() const;
        std::string getTotalProc() const;
        std::string getRunningProc() const;
        std::string getKernelVersion() const;
        std::string getOsName() const;
        std::string getCpuPercent() const;
        void getOtherCores(int _size);
        void setCpuCoresStats();
        std::vector<std::string> getCoresStats() const;
        


};

std::vector<std::string> SysInfo::getCoresStats() const{
    std::vector<std::string> result = std::vector<std::string>();
    for (int i = 0; i < this->coresStats.size() ;i++) {
        std::string temp = ("cpu" + std::to_string(i) +": ");
        float check = stof(this->coresStats[i]);
        if (!check || this->coresStats[i] == "nan") {
            return std::vector<std::string>();
        }
        temp += Util::getProgressBar(this->coresStats[i]);
        result.push_back(temp);
    }
    return result;
}

void SysInfo::setCpuCoresStats(){
    for(int i = 0; i < this->currentCpuCoresStats.size(); i++) {
        this->currentCpuCoresStats[i] = ProcessParser::getSysCpuPercent(std::to_string(i));
    }
    for(int i = 0; i < this->currentCpuCoresStats.size(); i++) {
        this->coresStats[i] = ProcessParser::printCpuStats(this->lastCpuCoresStats[i],this->currentCpuCoresStats[i]);
    }
    this->lastCpuCoresStats = this->currentCpuCoresStats;
}

void SysInfo::getOtherCores(int _size){
    this->coresStats = std::vector<std::string>();
    this->coresStats.resize(_size);
    this->lastCpuCoresStats = std::vector<std::vector<std::string>>();
    this->lastCpuCoresStats.resize(_size);
    this->currentCpuCoresStats = std::vector<std::vector<std::string>>();
    this->currentCpuCoresStats.resize(_size);
    for (int i = 0; i < _size; i++) {
        this->lastCpuCoresStats[i] = ProcessParser::getSysCpuPercent(std::to_string(i));
    }
}

void SysInfo::setLastCpuMeasures(){
    this->lastCpuStats = ProcessParser::getSysCpuPercent();
}

void SysInfo::setAttributes(){
    this->memPercent = ProcessParser::getSysRamPercent();
    this->upTime = ProcessParser::getSysUpTime();
    this->threads = ProcessParser::getTotalThreads();
    this->totalProc = ProcessParser::getTotalNumberOfProcesses();
    this->runningProc = ProcessParser::getNumberOfRunningProcesses();
    this->currentCpuStats = ProcessParser::getSysCpuPercent();
    this->cpuPercent = ProcessParser::printCpuStats(this->lastCpuStats, this->currentCpuStats);
    this->lastCpuStats = this->currentCpuStats;
    this->setCpuCoresStats();

}

std::string SysInfo::getCpuPercent()const{
    return this->cpuPercent;
}

std::string SysInfo::getOsName() const{
    return this->osName;
}

std::string SysInfo::getKernelVersion() const{
    return this->kernelVer;
}

std::string SysInfo::getRunningProc()const{
    return std::to_string(this->runningProc);
}

std::string SysInfo::getTotalProc()const{
    return std::to_string(this->totalProc);
}

std::string SysInfo::getThreads()const{
    return std::to_string(this->threads);
}

long SysInfo::getUpTime()const{
    return this->upTime;
}


std::string SysInfo::getMemPercent()const{
    return std::to_string(this->memPercent);
}


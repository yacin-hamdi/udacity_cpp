#pragma once

#include "process.h"


class ProcessContainer{
    private:
        std::vector<Process> list_;

    public:
        ProcessContainer(){
            this->refreshList();
        }
        void refreshList();
        std::string printList();
        std::vector<std::string> getList();

};

std::vector<std::string> ProcessContainer::getList(){
    std::vector<std::string> values;
    for (int i = (this->list_.size()-10); i < this->list_.size(); i++){
        values.push_back(this->list_[i].getProcess());
    }
    return values;
}

void ProcessContainer::refreshList(){
    std::vector<std::string> pids = ProcessParser::getPidList();
    list_.clear();
    for(int i=0;i<pids.size();i++){
        Process proc(pids[i]);
        this->list_.push_back(proc);
    }
}

std::string ProcessContainer::printList(){
    std::string result="";
    for (auto i : list_) {
        result += i.getProcess();
    }
    return result;
}
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

void ProcessContainer::refreshList(){
    std::vector<std::string> pids = ProcessParser::getPidList();
    list_.clear();
    for(int i=0;i<pids.size();i++){
        Process proc(pids[i]);
        this->list_.push_back(proc);
    }
}

std::string ProcessContainer::printList(){
    
}
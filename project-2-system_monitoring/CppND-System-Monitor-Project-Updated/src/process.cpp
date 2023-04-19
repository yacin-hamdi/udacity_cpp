#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;


Process::Process(int pid){
    this->pid_ = pid;
    this->user_ = LinuxParser::User(this->pid_);
    this->cmd_ = LinuxParser::Command(this->pid_);
    this->ram_ = LinuxParser::Ram(this->pid_);
    this->uptime_ = LinuxParser::UpTime(this->pid_);

    long totaltime = LinuxParser::ActiveJiffies(this->pid_);
    long seconds = LinuxParser::UpTime() - this->uptime_;

    this->cpu_ = totaltime/seconds;
}

// TODO: Return this process's ID
int Process::Pid()const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const{ return cpu_; }

// TODO: Return the command that generated this process
string Process::Command() const { return cmd_; }

// TODO: Return this process's memory utilization
string Process::Ram() const { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() const { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { return uptime_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return CpuUtilization() < a.CpuUtilization();
}
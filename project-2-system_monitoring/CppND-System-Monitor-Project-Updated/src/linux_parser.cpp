#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iterator>


#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  string path = LinuxParser::kProcDirectory + LinuxParser::kMeminfoFilename;
  
  string memTotal = "MemTotal";
  string memAv = "MemAvailable";
  string key;
  float tot_mem, av_mem;
  

  std::ifstream stream(path);
  string line;
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, memTotal.size(), memTotal) == 0){
        std::istringstream mystream(line);
        mystream >> key >> tot_mem;


      }else if(line.compare(0, memAv.size(), memAv) == 0){
        std::istringstream mystream(line);
        mystream >> key >> av_mem;


      }
    }
  }
  
  return (tot_mem - av_mem) / tot_mem; 
  }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  string uptime, othertime;
  string path = LinuxParser::kProcDirectory + LinuxParser::kUptimeFilename;
  std::ifstream stream(path);
  string line;
  if(stream.is_open()){
    std::getline(stream, line);
    std::istringstream mystream(line);
    mystream >> uptime;
  }
  return stol(uptime);
  
  

   }

long LinuxParser::Jiffies() {
  return LinuxParser::ActiveJiffies() + LinuxParser::IdleJiffies();
}

// Read and return the number of active jiffies for a PID
long LinuxParser::ActiveJiffies(int pid) {
  long totaltime;
  string line, value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
      values.push_back(value);
    }
  }

  // make sure parsing was correct and values was read
  long utime = 0, stime = 0 , cutime = 0, cstime = 0;
  if (std::all_of(values[13].begin(), values[13].end(), isdigit))
    utime = stol(values[13]);
  if (std::all_of(values[14].begin(), values[14].end(), isdigit))
    stime = stol(values[14]);
  if (std::all_of(values[15].begin(), values[15].end(), isdigit))
    cutime = stol(values[15]);
  if (std::all_of(values[16].begin(), values[16].end(), isdigit))
    cstime = stol(values[16]);

  totaltime = utime + stime + cutime + cstime;
  return totaltime / sysconf(_SC_CLK_TCK);
}

long LinuxParser::ActiveJiffies() {
  // Read and return the number of active jiffies for the system
  auto jiffies = CpuUtilization();

  return stol(jiffies[CPUStates::kUser_]) + stol(jiffies[CPUStates::kNice_]) +
         stol(jiffies[CPUStates::kSystem_]) + stol(jiffies[CPUStates::kIRQ_]) +
         stol(jiffies[CPUStates::kSoftIRQ_]) +
         stol(jiffies[CPUStates::kSteal_]);
}

long LinuxParser::IdleJiffies() {
  // Read and return the number of idle jiffies for the system
  auto jiffies = CpuUtilization();
  return stol(jiffies[CPUStates::kIdle_]) + stol(jiffies[CPUStates::kIOwait_]);
}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 

  string path = kProcDirectory + kStatFilename;
  string line;
  string key = "cpu";
  string value;
  std::ifstream stream(path);
  std::vector<string> jiffies{};
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, key.size(), key) == 0){
        std::istringstream mystream(line);
        mystream >> key;
        while(mystream >> value){
          jiffies.push_back(value);
        }
        break;
      }
    }
  }
  
  return jiffies; 
  }

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  string path = LinuxParser::kProcDirectory + LinuxParser::kStatFilename;
  string name = "processes";
  string line, key;
  int total = 0;
  std::ifstream stream(path);

  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, name.size(), name) == 0){
        std::istringstream my_stream(line);
        my_stream >> key >> total;
        break;
      }
    }
  }
  
   return total; 
   
   }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  string path = LinuxParser::kProcDirectory + LinuxParser::kStatFilename;
  string name = "procs_running";
  string line, key;
  int running_proc = 0;
  std::ifstream stream(path);
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, name.size(), name) == 0){
        std::istringstream mystream(line);
        mystream >> key >> running_proc;
        break;
      }
    }
  }
  return running_proc; 
  }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid[[maybe_unused]]) { 
  string path = kProcDirectory + to_string(pid) + kCmdlineFilename;
  string cmd;
  std::ifstream stream(path);
  if(stream.is_open()){
    getline(stream, cmd);
  }
  
  return cmd; 
  }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) {
  string path = kProcDirectory + to_string(pid) + kStatusFilename;
  string key = "VmSize:";
  string line;
  string ram;
  std::ifstream stream(path);
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, key.size(), key) == 0){
          std::istringstream my_stream(line);
          my_stream >> key >> ram;
          ram = to_string(stol(ram)/1024);
      }
    }
  }
   return ram; 
   }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) { 

  string path = kProcDirectory + to_string(pid) + kStatusFilename;
  string uid,line;
  string key = "Uid:";

  std::ifstream stream(path);
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.compare(0, key.size(), key) == 0){
        std::istringstream mystream(line);
        mystream >> key >> uid;
      }
    }
  }
  
  return uid; 
  }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) { 
  string line, user;
  std::ifstream stream(kPasswordPath);
  string key = "x:" + LinuxParser::Uid(pid);
  if(stream.is_open()){
    while(getline(stream, line)){
      if(line.find(key) != std::string::npos){
          user = line.substr(0, line.find(":"));
      }
    }
  }
  
  return user; 
  }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) {

  string path = kProcDirectory + to_string(pid) + kStatFilename;
  string line;
  std::ifstream stream(path);
  long uptime;
  if(stream.is_open()){
    getline(stream, line);
    std::istringstream mystream(line);
    std::istream_iterator<std::string>beg(mystream), end;
    std::vector<string> values(beg, end);
    uptime = float(stof(values[21])/sysconf(_SC_CLK_TCK) * 100);
  }
  
   return uptime; 
   }

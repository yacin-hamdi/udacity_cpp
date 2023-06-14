#include "databasedetails.h"
#include<fstream>
#include <iostream>


void Details::setDetailsFromFile(std::string filename){
    std::ifstream file(filename);
    std::string line;
    std::string name;
    std::cout << "details" << std::endl;

    if(file){
        while(getline(file, line)){
            name = line.substr(line.find("::")+2, line.size());
        if( line.substr(0, line.find("::")) == "hostname")
            this->_hostname = name;
        else if(line.substr(0, line.find("::")) == "user")
            this->_user = name;
        else if(line.substr(0, line.find("::")) == "password")
            this->_password = name;
        else if(line.substr(0, line.find("::")) == "database")
            this->_database = name;
    }
    }else{
        throw std::runtime_error("file not found");
    }
    
}

std::string Details::getHostname(){return _hostname;}
std::string Details::getUser(){return _user;}
std::string Details::getPassword(){return _password;}
std::string Details::getDatabase(){return _database;}
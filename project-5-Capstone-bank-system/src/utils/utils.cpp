#include "utils.h"
#include<iostream>


bool Util::stringIsDigit(std::string str){
    for(int i = 0;i<str.size();i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}



std::string Util::increamentNumber(std::vector<Account> numbs){
    std::string temp = "0";
    int size = numbs.size();
    for(int i=0;i<size;i++){
        if(stoi(numbs[i].getNumber()) > stoi(temp)){
            temp = numbs[i].getNumber();
        }

    }
    temp = std::to_string(stoi(temp) + 1);
    size = 6-temp.size();
    
    for(int i=0;i<size;i++){
        temp = "0"+temp;
    }

    return temp;
}

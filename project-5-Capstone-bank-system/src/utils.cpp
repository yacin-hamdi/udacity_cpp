#include "utils.h"

bool Util::stringIsDigit(std::string str){
    for(int i = 0;i<str.size();i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}
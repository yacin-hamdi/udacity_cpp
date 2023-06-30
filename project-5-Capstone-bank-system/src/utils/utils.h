#ifndef HELPERFUNCTION_H
#define HELPERFUNCITON_H

#include<string>
#include<vector>
#include "../account/account.h"

class Util{
    public:
        static bool stringIsDigit(std::string str);
        static std::string increamentNumber(std::vector<Account> nmbs);

};




#endif
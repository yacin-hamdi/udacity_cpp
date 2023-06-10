#ifndef BASE_H
#define BASE_H

#include "interface.h"
#include "databasehelper.h"
#include "constants.h"

class Base{
    public:
        Base(){}
        void checkLogin();

    private:
        void closeAccount();
        void deleteUser();
        void addAccount();
        void userAccount();
        void adminAccount();
        void login();

        Interface _interface;
        DatabaseHelper _dbHelper{DATABASE_DETAILS};
        bool _login_success = false;
        int _num = 0;
        bool _exit = false;
        Auth _auth;
        
};

#endif
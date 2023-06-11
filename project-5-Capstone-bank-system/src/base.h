#ifndef BASE_H
#define BASE_H
#include "databasehelper.h"
#include "interface.h"

class Base{
    public:
        Base(){}
        void start();

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
        bool _is_connected = false;
        int _num = 0;
        bool _exit = false;
        Auth _auth;
        std::vector<std::vector<std::string>> _all_user_details;
        std::vector<std::string> _user_details;

        std::vector<std::string> _temp;
        bool _state;
        
};

#endif
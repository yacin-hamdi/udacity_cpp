#include "base.h"

void Base::checkLogin(){
    _dbHelper.dbConnect();
    _interface.connectToDatabaseInterface(_dbHelper.isConnected());
    int a;

    
    while(_dbHelper.isConnected() && !_exit){
        if(_login_success){
            if(_dbHelper.getUserDetails()[9]=="1"){
                adminAccount();
            }else{
                userAccount();
            }
            
        }else{   
            login();     
        }

    }
    
    

    
    
}


void Base::closeAccount(){
    std::string sure = _interface.closeAccountInterface();
    bool account_deleted = false;
    if(sure == "y" || sure == "yes"){
        _auth = _interface.loginInterface();
        account_deleted = _dbHelper.closeMyAccount(_auth.username, _auth.password);
        if(account_deleted){
            _interface.byeAccountInterface();
            _num = 6;
        }
        
    }else{
        _num = 0;
    }
}

void Base::deleteUser(){
    _dbHelper.getAllUser();
    std::vector<std::vector<std::string>> all_user_details = _dbHelper.getAllUserDetails();
    int id = _interface.deleteUserInterface(all_user_details);
    if (id != 0)
        _dbHelper.removeUser(std::to_string(id));
    _num = 0;
}

void Base::addAccount(){
    Customer customer = _interface.addUserInterface();
    int state = _dbHelper.addUser(customer);
    _num = _interface.addUserSuccess(state);
}

void Base::userAccount(){
    if(_num <= 0 || _num > 6)
        _num = _interface.userInterface();
    else if(_num == 1)
        _num = _interface.userAccountDetailsInterface(_dbHelper.getUserDetails());
    else if(_num == 5){
        closeAccount();
    }else if(_num == 6){
        _exit = true;
    }
}

void Base::adminAccount(){
    if(_num == 0 ){
        _num = _interface.adminInterface();
    }else if(_num == 1){
        _dbHelper.getAllUser();
        _num = _interface.allUserAccountDetailsInterface(_dbHelper.getAllUserDetails());
    }else if(_num == 2){
        addAccount();
    }else if(_num == 3){
        _dbHelper.updateUser("phone", "152", "moose");
        _num = 0;
    }else if(_num == 4){
        deleteUser();    
    }else if(_num == 5){
        _exit = true;
    }
        
}

void Base::login(){
    _auth = _interface.loginInterface();
    bool success = _dbHelper.checkLogin( _auth.username, _auth.password);
    _login_success = _interface.loginSuccess(success);
}
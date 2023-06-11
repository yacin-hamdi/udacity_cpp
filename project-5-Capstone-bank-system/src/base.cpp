#include "base.h"

void Base::start(){
    _dbHelper.dbConnect();
    _is_connected = _dbHelper.isConnected();
    _interface.connectToDatabaseInterface(_is_connected);

    
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
    else if(_num == 1){
        _temp = _dbHelper.getUserDetails();
        _num = _interface.userAccountDetailsInterface(_temp);

    }else if(_num == 3){
        _temp = _dbHelper.getUserDetails();
        _interface.userAccountDetailsInterface(_temp);
        _temp = _interface.updateUserInterface();
        _state = _dbHelper.updateUser(_temp[0], _temp[1], _auth.username);
        _num = _interface.updateUserSuccess(_state);

        
    }else if(_num == 5){
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
        _all_user_details = _dbHelper.getAllUserDetails();
        _num = _interface.allUserAccountDetailsInterface(_all_user_details);
    }else if(_num == 2){
        addAccount();
    }else if(_num == 3){
        _dbHelper.getAllUser();
        _all_user_details = _dbHelper.getAllUserDetails();
        _interface.allUserAccountDetailsInterface(_all_user_details);
        _temp = _interface.updateAdminUserInterface();
        _state = _dbHelper.updateUser(_temp[1], _temp[2], _temp[0]);
        _num = _interface.updateUserSuccess(_state);
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
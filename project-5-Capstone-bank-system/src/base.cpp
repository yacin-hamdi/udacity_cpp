#include "base.h"
#include "utils/utils.h"

void Base::start(){
    _dbHelper.dbConnect();
    _is_connected = _dbHelper.isConnected();
    _interface.connectToDatabaseInterface(_is_connected);

    
    while(_dbHelper.isConnected() && !_exit){
        if(_login_success){
            if(_dbHelper.getCustomerDetails().getAdmin()==ADMIN_PRIVILEGE){
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
        account_deleted = _dbHelper.removeUser(_dbHelper.getCustomerDetails().getId());
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
    _all_customer_details = _dbHelper.getAllCustomerDetails();
    int id = _interface.deleteUserInterface(_all_customer_details);
    if (id != 0){
        _state = _dbHelper.removeUser(std::to_string(id));
        _num = _interface.deleteUserSuccessInterface(_state);
    }
        
}

void Base::addAccount(){
    std::vector<Account> acc = _dbHelper.getAllAccountDetails();
    std::string num = Util::increamentNumber(acc);
    std::cout << num << std::endl;
    _customer_details = _interface.addUserInterface();
    _account_details = _interface.addAccountInterface();
    _account_details.setNumber(Util::increamentNumber(_dbHelper.getAllAccountDetails()));
    _state = _dbHelper.addUser(_customer_details, _account_details);
    _num = _interface.addUserSuccess(_state);
}

void Base::sendMoney(){
    _transaction_details = _interface.sendMoneyInterface();
    _transaction_details.setFrom(_dbHelper.getAccountDetails("username", 
                                    _dbHelper.getCustomerDetails().getLogin()).getNumber());
    _transaction_details.setAccountId(_dbHelper.getAccountDetails("username", 
                                        _dbHelper.getCustomerDetails().getLogin()).getNumber());
        
    _temp_int = stoi(_dbHelper.getAccountDetails("balance", _transaction_details.getFrom()).getBalance()) 
                - stoi(_transaction_details.getAmount());
    std::cout << _temp_int << std::endl;
    _state = false;
    if(_temp_int > 0){
        int new_balance = stoi(_dbHelper.getAccountDetails("number", _transaction_details.getTo()).getBalance());
            new_balance += stoi(_transaction_details.getAmount());
        _dbHelper.setAccountDetails(_transaction_details.getFrom(), "balance", std::to_string(_temp_int));
        _dbHelper.setAccountDetails(_transaction_details.getTo(), "balance", std::to_string(new_balance));
        _state = _dbHelper.addTransaction(_transaction_details);

    }
        
    
    _num = _interface.sendMoneySuccess(_state);
}

void Base::userAccount(){
    if(_num <= 0 || _num > 6)
        _num = _interface.userInterface();
    else if(_num == 1){
        sendMoney();

    }else if(_num == 2){
        _all_transaction_details = _dbHelper.getTransactionDetails();
        _num = _interface.TransactionHistoInterface(_all_transaction_details);
        
    }else if(_num == 3){
        _customer_details = _dbHelper.getCustomerDetails();

        _account_details = _dbHelper.getAccountDetails("username", _dbHelper.getCustomerDetails().getLogin());
        _num = _interface.userAccountDetailsInterface(_customer_details, _account_details);
        
        
    }else if(_num == 4){
        _customer_details = _dbHelper.getCustomerDetails();
        _interface.userAccountDetailsInterface(_customer_details, _account_details);
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
        _all_customer_details = _dbHelper.getAllCustomerDetails();
        _all_account_details = _dbHelper.getAllAccountDetails();
        _num = _interface.allUserAccountDetailsInterface(_all_customer_details, _all_account_details);
    }else if(_num == 2){
        addAccount();
    }else if(_num == 3){
        _dbHelper.getAllUser();
        _all_customer_details = _dbHelper.getAllCustomerDetails();
        _all_account_details = _dbHelper.getAllAccountDetails();
        _interface.allUserAccountDetailsInterface(_all_customer_details, _all_account_details);
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
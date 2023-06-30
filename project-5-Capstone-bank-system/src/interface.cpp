#include "interface.h"
#include "utils/utils.h"
#include <stdlib.h>


Interface::Interface(){

}
bool Interface::connectToDatabaseInterface(bool &connected){
    std::cout << "connecting to database..." << std::endl;
    if(connected){
        std::cout << "you are connected"<< std::endl;
    }else{
        std::cout << "failed to connected to database please check database.dat file" << std::endl; 
    }
    std::cout << "=============================================\n\n";
    std::cout << "==============welcome to my bank=============\n";
    return connected;
}



Auth Interface::loginInterface(){
    
    
    
    std::cout << "enter your username: ";
    std::cin >> _auth.username;
    std::cout << "enter your password: ";
    std::cin >> _auth.password;
    std::cout << "\n\n";
    return _auth;
}



bool Interface::loginSuccess(bool &success){
    if(success){
        std::cout << "welcome to your account\n\n" << std::endl;
    }else{
        std::cout << "wrong username or password try again\n\n" << std::endl;
    }
    return success;
}

int Interface::adminInterface(){
    std::cout << "\n\n=============================================\n\n";
    std::cout << "::ADMIN INTERFACE::\n\n";
    std::cout << "1.List Accounts" << std::endl;
    std::cout << "2.Add Account" << std::endl;
    std::cout << "3.Modify Account" << std::endl;
    std::cout << "4.Remove Account" << std::endl;
    std::cout << "5.Exit" << std::endl;
    std::cout << "\n\n=============================================\n\n";
    std::cout << "enter a number 1-5:";
    std::cin >> _temp;
    std::cout << "\n\n=============================================\n\n";
    
    if(!Util::stringIsDigit(_temp) || stoi(_temp) < 1 || stoi(_temp) > 5){
        std::cout << "please try again enter a number between 1 and 5\n\n";
        return 0;
    }
    
    
    return stoi(_temp);
}

std::string Interface::closeAccountInterface(){
    
    std::cout << "=============================================\n\n";
    std::cout << "::CLOSE YOU ACCOUNT::\n\n";
    std::cout << "are you sure you want to close your account y/n:";
    std::cin >> _temp;
    std::cout << std::endl;

    return _temp;
    
}

void Interface::byeAccountInterface(){
    std::cout << "=============================================\n\n";
    std::cout << "your account has been removed forever\n";
    std::cout << "thanks for using our bank\n\n";
    std::cout << "bye!\n";
}

int Interface::userAccountDetailsInterface(Customer &customer, Account & account){

    TextTable _table( '-', '|', '+' );
    for(int i=1;i<customer.getAllDetails().size()+account.getAccountDetails().size();i++){
        if(i < customer.getAllDetails().size()){
            _table.add(CUSTOMER_COLUMNS[i]);
            _table.add(customer.getAllDetails()[i]);
            _table.endOfRow();
        }else{
            _table.add(ACCOUNT_COLUMNS[i - CUSTOMER_COLUMNS.size()]);
            _table.add(account.getAccountDetails()[i - CUSTOMER_COLUMNS.size()]);
            _table.endOfRow();
        }
        
    }
    

    
    _table.setAlignment( 2, TextTable::Alignment::LEFT );
    std::cout << _table;
    return 0;
}

int Interface::allUserAccountDetailsInterface(std::vector<Customer> &all_customer_details, 
                                                std::vector<Account> &all_account_details){

        std::cout << "::BANK USERS::\n\n";
        TextTable _table( '-', '|', '+' );
    for(int i=0;i<CUSTOMER_COLUMNS.size()+ACCOUNT_COLUMNS.size();i++){
        if(i < CUSTOMER_COLUMNS.size())
            _table.add(CUSTOMER_COLUMNS[i]);
        else
            _table.add(ACCOUNT_COLUMNS[i-CUSTOMER_COLUMNS.size()]);
    }

    _table.endOfRow();
    for(int i=0;i<all_customer_details.size();i++){
        if(!(all_customer_details[i].getAdmin() == ADMIN_PRIVILEGE)){
            for(int j=0;j<all_customer_details[i].getAllDetails().size();j++){
            
                _table.add(all_customer_details[i].getAllDetails()[j]);
            }
            _table.endOfRow();
        }
        
    }
    _table.setAlignment(3, TextTable::Alignment::LEFT);
    std::cout << _table;
    return 0;
}

int Interface::userInterface(){
    std::cout << "=============================================\n\n";
    std::cout << "::USER INTERFACE::\n\n";
    std::cout << "1.send money" << std::endl;
    std::cout << "2.transaction history" << std::endl;
    std::cout << "3.Account Details" << std::endl;
    std::cout << "4.Modify Your Account" << std::endl;
    std::cout << "5.Close Your Account" << std::endl;
    std::cout << "6.Exit" << std::endl;
    std::cout << "=============================================\n\n";
    std::cout << "enter a number 1-6:";
    std::cin >> _temp;
    std::cout << "\n\n=============================================\n\n";

    if(!Util::stringIsDigit(_temp) || stoi(_temp) <1 || stoi(_temp) >6){
        std::cout << "please try again enter a number between 1 and 6\n\n";
        return 0;
    }
    return stoi(_temp);
}

//check user input length to prevent buffer overflow

Customer Interface::addUserInterface(){
    std::cout << "::ADD USER::\n";
    std::cout << "enter your name: ";
    std::cin >> _temp;
    _customer.setName(_temp);

    std::cout << "enter you email: ";
    std::cin >> _temp;
    _customer.setEmail(_temp);

    std::cout << "enter your phone: ";
    std::cin >> _temp;
    _customer.setPhone(_temp);

    std::cout << "enter your day of birth (yyyy-mm-dd): ";
    std::cin >> _temp;
    _customer.setDob(_temp);

    std::cout << "enter your location: ";
    std::cin >> _temp;
    _customer.setCity(_temp);

    std::cout << "enter your pin code: ";
    std::cin >> _temp;
    _customer.setPinCode(_temp);
    
    std::cout << "enter your username: ";
    std::cin >> _temp;
    _customer.setLogin(_temp);

    std::cout << "enter your password: ";
    std::cin >> _temp;
    _customer.setPassword(_temp);

    std::cout << "is this account admin y/n: ";
    std::cin >> _temp;
    if(_temp == "y")
        _temp = "1";
    else
        _temp = "0";
    _customer.setAdmin(_temp);
    
    return _customer;

}

Account Interface::addAccountInterface(){
    std::cout << "enter account balance: ";
    std::cin >> _temp;
    _account.setBalance(_temp);
    std::cout << "enter account type(saving/checking): ";
    std::cin >> _temp;
    _account.setType(_temp);
    std::cout << "enter account status(active/blocked): ";
    std::cin >> _temp;
    _account.setStatus(_temp);
    _account.setUsername(_customer.getLogin());
    _account.setCreationDate("2023-2-2");

    return _account;
}

int Interface::addUserSuccess(bool &state){
    if(state){
        std::cout << "added customer successfully\n";
        std::cout << "would you like to add another customer (y/n): ";

    }else{
        std::cout << "\nfailed to add user\n";
        std::cout << "would you like to try again (y/n): ";
    }
    
    std::cin >> _temp;
    std::cout << "\n\n=============================================\n\n";

    if(_temp == "y" || _temp == "yes"){
        return 2;
    }

    return 0;


}

int Interface::deleteUserInterface(std::vector<Customer> &all_user_details){
    std::cout << "::BANK USERS::\n\n";
    TextTable _table( '-', '|', '+' );
    for(int j=0;j<2;j++){
        _table.add(CUSTOMER_COLUMNS[j]);
    }
    _table.endOfRow();

    for(int i=0;i<all_user_details.size();i++){

        if((all_user_details[i].getAdmin() == ADMIN_PRIVILEGE))
            continue;

        for(int j=0;j<2;j++)
            _table.add(all_user_details[i].getAllDetails()[j]);
        
        _table.endOfRow();
    }
    _table.setAlignment(2, TextTable::Alignment::RIGHT);
    std::cout << _table;
    std::cout << "enter account id you want to remove: ";
    std::cin >> _temp;
    if(!Util::stringIsDigit(_temp)){
        std::cout << "the id you enter is not found or its not a number try again" << std::endl;
        return 0;
    }
    
    return stoi(_temp);
}

int Interface::deleteUserSuccessInterface(bool &success){
    if(success){
        std::cout << "account deleted successfully\n\n";
    }else{
        std::cout << "failed to remove account it maybe you're trying to delete an admin account\n";
    }
    
    return 0;
}

std::vector<std::string> Interface::updateAdminUserInterface(){
    _details_temp.clear();
    std::cout << "enter username: ";
    std::cin >> _temp;
    _details_temp.push_back(_temp);
    std::cout << "enter the column you want to change: ";
    std::cin >> _temp;
    _details_temp.push_back(_temp);
    std::cout << "enter the new value of the column: ";
    std::cin >> _temp;
    _details_temp.push_back(_temp);
    return _details_temp;
}

std::vector<std::string> Interface::updateUserInterface(){
    _details_temp.clear();
    std::cout << "enter the column you want to change: ";
    std::cin >> _temp;
    _details_temp.push_back(_temp);
    std::cout << "enter the new value of the column: ";
    std::cin >> _temp;
    _details_temp.push_back(_temp);
    return _details_temp;
}

int Interface::updateUserSuccess(bool &state){
    if(state){
        std::cout << "update successfully\n";
        std::cout << "would you like to update another column (y/n): ";
        
    }else{
        std::cout << "update failed please check username, column or the value\n";
        std::cout << "would you like to try again (y/n): ";
    }

    std::cin >> _temp;
    if(_temp == "y" || _temp == "yes"){
        return 3;
    }

    return 0;
    
}


Transaction Interface::sendMoneyInterface(){
    std::cout << "=============================================\n\n";
    std::cout << "::Transaction::\n\n";
    std::cout << "how much money you want to send(1$-100$): " <<std::endl;
    std::cin >> _temp;
    if(Util::stringIsDigit(_temp)){
        _transaction.setAmount(_temp);            
    }
    
    std::cout << "account number you want to send money to: ";
    std::cin >> _temp;
    _transaction.setTo(_temp);
    _transaction.setDate("2023-2-2");

    return _transaction;

}

int Interface::sendMoneySuccess(bool &state){
    if(state){
        std::cout << "transaction succeed" << std::endl;
        
    }else{
        std::cout << "transaction failed" << std::endl;
    }

    return 0;
}

int Interface::TransactionHistoInterface(std::vector<Transaction> transactions){
    std::cout << "=============================================\n\n";
    std::cout << "::Transaction History::\n\n";
    TextTable _table( '-', '|', '+' );
    for(int i=0;i<TRANSACTION_COLUMNS.size();i++){
        _table.add(TRANSACTION_COLUMNS[i]);
    }

    _table.endOfRow();
    for(int i=0;i<transactions.size();i++){
        for(int j=0;j<transactions[i].getTransactionDetails().size();j++){
            
            _table.add(transactions[i].getTransactionDetails()[j]);
        }
            _table.endOfRow();
        
    }
    _table.setAlignment(3, TextTable::Alignment::LEFT);
    std::cout << _table;
    return 0;

}

// template<typename t> int Interface::showTable(std::vector<t> vec){
//     for(int i=0;i<ACCOUNT_COLUMNS;i++){
//         _table.add(ACCOUNT_COLUMNS[i]);
//     }

//     _table.endOfRow();
//     for(int i=0;i<all_customer_details.size();i++){
//         if(!(all_customer_details[i].getAdmin() == ADMIN_PRIVILEGE)){
//             for(int j=0;j<all_customer_details[i].getAllDetails().size();j++){
            
//                 _table.add(all_customer_details[i].getAllDetails()[j]);
//             }
//             _table.endOfRow();
//         }
        
//     }
//     _table.setAlignment(3, TextTable::Alignment::LEFT);
//     std::cout << _table;
//     return 0;
// }
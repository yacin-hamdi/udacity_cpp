#include "interface.h"
#include "helper.h"


bool Interface::connectToDatabaseInterface(bool connected){
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

int Interface::userInterface(){
    std::string num = "";
    std::cout << "=============================================\n\n";
    std::cout << "::USER INTERFACE::\n\n";
    std::cout << "1.Account Details" << std::endl;
    std::cout << "2.Withdraw Amount" << std::endl;
    std::cout << "3.Balance Enquiry" << std::endl;
    std::cout << "4.Modify Your Account" << std::endl;
    std::cout << "5.Close Your Account" << std::endl;
    std::cout << "6.Exit" << std::endl;
    std::cout << "=============================================\n\n";
    std::cout << "enter a number 1-6:";
    std::cin >> num;
    std::cout << "\n\n=============================================\n\n";

    if(!stringIsDigit(num) || stoi(num) <1 || stoi(num) >6){
        std::cout << "please try again enter a number between 1 and 6\n\n";
        return 0;
    }
    return stoi(num);
}

int Interface::adminInterface(){
    std::string num = "";
    std::cout << "\n\n=============================================\n\n";
    std::cout << "::ADMIN INTERFACE::\n\n";
    std::cout << "1.List Accounts" << std::endl;
    std::cout << "2.Add Account" << std::endl;
    std::cout << "3.Modify Account" << std::endl;
    std::cout << "4.Remove Account" << std::endl;
    std::cout << "5.Exit" << std::endl;
    std::cout << "\n\n=============================================\n\n";
    std::cout << "enter a number 1-5:";
    std::cin >> num;
    std::cout << "\n\n=============================================\n\n";
    
    if(!stringIsDigit(num) || stoi(num) < 1 || stoi(num) > 5){
        std::cout << "please try again enter a number between 1 and 6\n\n";
        return 0;
    }
    
    
    return stoi(num);
}

std::string Interface::closeAccountInterface(){
    
    std::string sure = "n";
    std::cout << "=============================================\n\n";
    std::cout << "::CLOSE YOU ACCOUNT::\n\n";
    std::cout << "are you sure you want to close your account y/n:";
    std::cin >> sure;
    std::cout << std::endl;

    return sure;
    
}

void Interface::byeAccountInterface(){
    std::cout << "=============================================\n\n";
    std::cout << "your account has been removed forever\n";
    std::cout << "thanks for using our bank\n\n";
    std::cout << "bye!\n";
}

int Interface::userAccountDetailsInterface(std::vector<std::string> user_details){

    for(int i=1;i<user_details.size() - 1;i++){
        std::cout << CUSTOMER_COLUMNS[i] << " : "<< user_details[i] << "\n";
    }
    std::cout << std::endl;
    return 0;
}

int Interface::allUserAccountDetailsInterface(std::vector<std::vector<std::string>> all_user_details){

        std::cout << "::BANK USERS::\n\n";
    for(int j=0;j<CUSTOMER_COLUMNS.size();j++){
            std::cout << CUSTOMER_COLUMNS[j] << "\t";
    }
    std::cout << std::endl;
    for(int i=0;i<all_user_details.size();i++){
        
        for(int j=0;j<all_user_details[0].size();j++){
            
            std::cout << all_user_details[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}

Customer Interface::addUserInterface(){
    std::string temp;
    Customer customer;
    std::cout << "::ADD USER::\n";
    std::cout << "enter your name: ";
    std::cin >> temp;
    customer.setName(temp);

    std::cout << "enter you email: ";
    std::cin >> temp;
    customer.setEmail(temp);

    std::cout << "enter your phone: ";
    std::cin >> temp;
    customer.setPhone(temp);

    std::cout << "enter your day of birth (yyyy-mm-dd): ";
    std::cin >> temp;
    customer.setDob(temp);

    std::cout << "enter your location: ";
    std::cin >> temp;
    customer.setCity(temp);

    std::cout << "enter your pin code: ";
    std::cin >> temp;
    customer.setPinCode(temp);
    
    std::cout << "enter your username: ";
    std::cin >> temp;
    customer.setLogin(temp);

    std::cout << "enter your password: ";
    std::cin >> temp;
    customer.setPassword(temp);

    std::cout << "is this account admin y/n: ";
    std::cin >> temp;
    if(temp == "y")
        temp = "1";
    else
        temp = "0";
    customer.setAdmin(temp);
    
    return customer;

}

int Interface::addUserSuccess(int &state){
    std::string sure;
    if(state == 0){
        std::cout << "added customer successfully\n";
        std::cout << "would you like to add another customer (y/n): ";

    }else{
        std::cout << "\nfailed to add user\n";
        std::cout << "would you like to try again (y/n): ";
    }
    
    std::cin >> sure;
    std::cout << "\n\n=============================================\n\n";

    if(sure == "y" || sure == "yes"){
        return 2;
    }

    return 0;


}

int Interface::deleteUserInterface(std::vector<std::vector<std::string>> &all_user_details){
    std::string id;
    std::cout << "::BANK USERS::\n\n";
    for(int j=0;j<2;j++){
            std::cout << CUSTOMER_COLUMNS[j] << "\t";
    }
    std::cout << std::endl;
    for(int i=0;i<all_user_details.size();i++){
        
        for(int j=0;j<2;j++){
            
            std::cout << all_user_details[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "enter account id you want to remove: ";
    std::cin >> id;
    if(!stringIsDigit(id)){
        std::cout << "the id you enter is not found or its not a number try again" << std::endl;
        return 0;
    }
    std::cout << "account deleted successfully\n\n";
    return stoi(id);
}
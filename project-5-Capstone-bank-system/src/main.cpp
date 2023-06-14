/*
CREATE TABLE `bankUsers` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `accountnum` varchar(30) Not NULL,
    `username` varchar(30) NOT NULL,
    `name` varchar(50) NOT NULL,
    `email` varchar(255) NOT NULL UNIQUE,
    `password` varchar(255) NOT NULL,
    PRIMARY KEY (`id`)
);

INSERT INTO tblUsers(name, surname, email, password) VALUES ("mike", "wowzowski", "mike@gmail.com", "password");
INSERT INTO tblUsers(name, surname, email, password) VALUES ("luke", "bordom", "luke@gmail.com", "password2");
INSERT INTO tblUsers(name, surname, email, password) VALUES ("sam", "dally", "sam@gmail.com", "password3");

INSERT INTO customer(name, email, phone, dob, city, pincode, login, password) VALUES ("sam", "dally@gmail.com", 
"25562452", "1995-2-1", "tunis", "8100", "dally", "azerty");
 */

//ubuntu
//g++ main.cpp -o test `mysql_config --cflags --libs`

#include<iostream>
#include "base.h"
#include "account/accountdbhelper.h"

//todo when remove user account i need to 
//check i the account i want to remove is not my account or admin account
//also check if the account exist

int main(){
    
    // std::string filename = "database.dat";
    
    // Base base;
    // base.start();

    AccountDBHelper accountDBHelper;
    Account account = accountDBHelper.getAccountDetails("aycin");

    std::cout << account.getNumber() << std::endl;
    

    return 0;
}
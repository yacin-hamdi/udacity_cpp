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
#include "transaction/transactiondbhelper.h"
#include "databasehelper.h"
#include "transaction/transaction.h"
#include <string>
#include "utils/utils.h"

//todo when remove user account i need to 
//check i the account i want to remove is not my account or admin account
//also check if the account exist

int main(){
    DatabaseHelper dbHelper;
    dbHelper.dbConnect();

    
    // AccountDBHelper db;
    // bool status = db.getAllAccountDB(dbHelper.getMysqlConnection());
    // std::vector<Account> acc = db.getAllAccount();

    // for(int i=0;i<acc.size();i++){
    //     std::cout << acc[i].getNumber() << std::endl;
    // }

    // std::string num = Util::increamentNumber(acc);
    // std::cout << num << std::endl;




    
    // bool status = transdb.updateTransactionDB(dbHelper.getMysqlConnection(), "1", "transaction_amount", "9333");

   

    // bool status = transdb.getAllTransactionDB(dbHelper.getMysqlConnection());
    // std::vector<Transaction> trans = transdb.getAllTransaction();

    // for(int i=0;i<trans.size();i++){
    //     for(int j=0;j < trans[i].getTransactionDetails().size();j++){
    //         std::cout << trans[i].getTransactionDetails()[j] << "\t";
    //     }
    //     std::cout << std::endl;
    // }
    


    
    // std::cout << status << std::endl;

    
    
    // std::string filename = "database.dat";
    
    Base base;
    base.start();

    // AccountDBHelper accountDBHelper;
    // Account account = accountDBHelper.getAccountDetails("aycin");

    // std::cout << account.getNumber() << std::endl;
    

    return 0;
}
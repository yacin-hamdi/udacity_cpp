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


//todo when remove user account i need to 
//check i the account i want to remove is not my account or admin account
//also check if the account exist

int main(){
    // TextTable t( '-', '|', '+' );

    // t.add( "" );
    // t.add( "Sex" );
    // t.add( "Age" );
    // t.endOfRow();

    // t.add( "Moses" );
    // t.add( "male" );
    // t.add( "4556" );
    // t.endOfRow();

    // t.add( "Jesus" );
    // t.add( "male" );
    // t.add( "2016" );
    // t.endOfRow();

    // t.add( "Debora" );
    // t.add( "female" );
    // t.add( "3001" );
    // t.endOfRow();

    // t.add( "Bob" );
    // t.add( "male" );
    // t.add( "25" );
    // t.endOfRow();

    // t.setAlignment( 2, TextTable::Alignment::RIGHT );
    // std::cout << t;
    std::string filename = "database.dat";
    
    Base base;
    base.start();
 
    // DatabaseHelper databaseHelper(filename);
    // databaseHelper.dbConnect();
    // if(databaseHelper.getMysqlConnection())
    //     std::cout << "you are connected" << std::endl;
    // else
    //     std::cout << "you aren't connected to database" << std::endl;
    // Customer customer("mss", "moos@gmail.com", "25325622", "1988-1-2", "tunis", "750", "helm", "123456789");

    // int state = databaseHelper.insertData(customer, "customer");
    // if(state == 0){
    //     std::cout << "client inserted successfully" << std::endl;
    // }else{
    //     std::cout << "failed to add client" << std::endl;
    // }

    // databaseHelper.displayData("customer");

    return 0;
}
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


 */

//ubuntu
//g++ main.cpp -o test `mysql_config --cflags --libs`

#include<iostream>
#include "databasehelper.h"
#include "client.h"




int main(){
    std::string hostname = "localhost";
    std::string dbuser = "yacin";
    std::string password = "password";
    std::string database = "test1";
    DatabaseHelper databaseHelper(hostname, dbuser, password, database);
    databaseHelper.dbConnect();
    if(databaseHelper.getMysqlConnection())
        std::cout << "you are connected" << std::endl;
    else
        std::cout << "you aren't connected to database" << std::endl;
    Client user("mss", "moos", "ay@gmail.com", "pass", "123456");

    int state = databaseHelper.insertData(user, "bankUsers");
    if(state == 0){
        std::cout << "client inserted successfully" << std::endl;
    }else{
        std::cout << "failed to add client" << std::endl;
    }

    return 0;
}
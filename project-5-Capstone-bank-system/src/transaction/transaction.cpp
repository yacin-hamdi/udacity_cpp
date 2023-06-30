#include "transaction.h"

#include <iostream>
Transaction::Transaction(std::string transaction_id, std::string account_id, std::string from,
    std::string to, std::string date, std::string amount){

    setTransactionId(transaction_id);
    setAccountId(account_id);
    setFrom(from);
    setTo(to);
    setDate(date);
    setAmount(amount);
}

std::string Transaction::getTransactionId(){return _transaction_id;}
std::string Transaction::getAccountId(){return _account_id;}
std::string Transaction::getFrom(){return _from;}
std::string Transaction::getTo(){return _to;}
std::string Transaction::getDate(){return _date;}
std::string Transaction::getAmount(){return _amount;}

std::vector<std::string> Transaction::getTransactionDetails(){
    return std::vector{
        getTransactionId(), getAccountId(), getFrom(), 
        getTo(), getDate(), getAmount()
    };
}




void Transaction::setTransactionId(std::string transaction_id){_transaction_id = transaction_id;}
void Transaction::setAccountId(std::string account_id){_account_id = account_id;}
void Transaction::setFrom(std::string from){_from = from;}
void Transaction::setTo(std::string to){_to = to;}
void Transaction::setDate(std::string date){_date = date;}
void Transaction::setAmount(std::string amount){_amount = amount;}

void Transaction::setTransactionsDetails(MYSQL_ROW row){
    setTransactionId(row[0]);
    setAccountId(row[1]);
    setFrom(row[2]);
    setTo(row[3]);
    setDate(row[4]);
    
    setAmount(row[5]);
    
}
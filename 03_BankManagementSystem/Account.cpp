#include "Account.h"
#include<iostream>
#include<iomanip>

using namespace std;

Account::Account(int accNum, const string &name, double bal):
 accountNumber(accNum), accountHolderName(name), balance(bal)
 {
    
 }

 void Account::deposit(double amount)
 {
    if(amount > 0)
    {
        balance += amount;
        transactionHistory.emplace_back("Deposit", amount);
    }

 }

 void Account::withdraw(double amount)
 {
    if(amount<= balance)
    {
        balance -= amount;
        transactionHistory.emplace_back("Withdraw", amount);

    }else{

        cout<<"Insufficcient Balance.\n";

        }
 }

 void Account::display() const{ //Constant member functions

    cout<<"Account Number: "<<accountNumber<<"\n";
    cout<<"Account Holder Name: "<<accountHolderName<<"\n";
    cout<<"Balance: "<<balance<<"\n";

 }

 void Account::displayTransactionHistory() const{
    cout<<"Transaction history for account: "<<accountNumber<<"\n";
    for(const auto &transaction : transactionHistory)
    {
        transaction.display();
    }
 }

 int Account::getAccountNumber() const{
    return accountNumber;
 }

 double Account::getBalance() const {
    return balance;
 }

 void Account::updateAccountHolderName(const string &newName){
    accountHolderName = newName;
 }
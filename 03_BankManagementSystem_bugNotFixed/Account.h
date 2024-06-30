#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

class Account {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    Account(int accNum = 0, const std::string &name = "", double bal = 0.0)
        : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
    int getAccountNumber() const { return accountNumber; }
    const std::string& getAccountHolderName() const { return accountHolderName; }  // Add this method
    double getBalance() const { return balance; }
    const std::vector<Transaction>& getTransactionHistory() const { return transactionHistory; }
    void serialize(std::ofstream &out) const;
    void deserialize(std::ifstream &in);
};

#endif

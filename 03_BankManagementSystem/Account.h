#define ACCOUNT_H

#include <string>
#include<vector>
#include "Transaction.h"
using namespace std;

class Account{

private:

    int accountNumber;
    string accountHolderName;
    double balance;
    vector<Transaction> transactionHistory;

public:

    Account(int accNum, const std::string &name, double bal = 0.0);
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
    void displayTransactionHistory() const;
    int getAccountNumber() const;
    double getBalance() const;
    string getAccountHolderName() const;
    void updateAccountHolderName(const string &newName);
    
};
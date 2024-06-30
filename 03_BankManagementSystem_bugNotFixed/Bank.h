#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"

class Bank {
private:
    std::vector<Account> accounts;

public:
    void createAccount(int accountNumber, const std::string &accountHolderName, double initialBalance);
    void depositToAccount(int accountNumber, double amount);
    void withdrawFromAccount(int accountNumber, double amount);
    void displayAllAccounts() const;
    void deleteAccount(int accountNumber);
    Account* findAccount(int accountNumber);
    const std::vector<Account>& getAccounts() const;  // Add this method
};

#endif

#include "Bank.h"
#include <algorithm>
#include <iostream>

void Bank::createAccount(int accountNumber, const std::string &accountHolderName, double initialBalance) {
    accounts.emplace_back(accountNumber, accountHolderName, initialBalance);
}

void Bank::depositToAccount(int accountNumber, double amount) {
    Account* account = findAccount(accountNumber);
    if (account) {
        account->deposit(amount);
    } else {
        std::cerr << "Account not found.\n";
    }
}

void Bank::withdrawFromAccount(int accountNumber, double amount) {
    Account* account = findAccount(accountNumber);
    if (account) {
        account->withdraw(amount);
    } else {
        std::cerr << "Account not found.\n";
    }
}

void Bank::displayAllAccounts() const {
    for (const auto& account : accounts) {
        account.display();
        std::cout << "-----------------------\n";
    }
}

void Bank::deleteAccount(int accountNumber) {
    auto it = std::remove_if(accounts.begin(), accounts.end(), 
        [accountNumber](const Account &acc) { return acc.getAccountNumber() == accountNumber; });
    
    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
    } else {
        std::cerr << "Account not found.\n";
    }
}

Account* Bank::findAccount(int accountNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

const std::vector<Account>& Bank::getAccounts() const {  // Implement this method
    return accounts;
}

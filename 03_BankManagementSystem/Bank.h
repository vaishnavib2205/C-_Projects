#define BANK_H

#include "Account.h"
#include<vector>
#include<stdexcept> //defines a set of standard exceptions
using namespace std;

class Bank{

private:
    vector<Account> accounts;
    int generateAccountNumber() const;

public:
    void createAccount(const string &name, double initialDeposit);
    void deposit(int accountNumber, double amount);
    void withdraw(int accountNumber, double amount);
    void displayAllAccounts() const;
    void deleteAllAccounts() const;
    void deleteAccount(int accountNumber);
    Account* searchAccountByNumber(int accountNumber);
    Account* searchAccountByName(const string &name);
    void updateAccount(int accountNumber, const string &newName);
    void displayTransationHistory(int accountNUmber) const;
    vector <Account> getAccounts() const;
    void addAccount(const Account &account);


};
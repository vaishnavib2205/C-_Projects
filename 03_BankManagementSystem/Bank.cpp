#include "Bank.h"
#include<iostream>
#include<algorithm>

using namespace std;

int Bank::generateAccountNumber() const{
    return accounts.size() + 1;

}

void Bank::createAccount(const string &name, double initialDeposit);
{
    int accountNumber = generateAccountNumber();
    Account newAccount(accountNumber, name, initialDeposit);
    accounts.push_back(newAccount);
    cout<<"Account created successfully.\n";

}

void Bank::deposit(int accountNumber, double amount)
{
    Account* account = searchAccountByNumber(accountNumber);
    if(account)
    {
        account->deposit(ammount);
        cout<<"Deposit Successful.\n";
    }else
    {
        cerr<<"Account not found. \n";
    }
}

void Bank::withdraw(int accountNumber, double amount)
{
    Account* account = searchAccountByNumber(accountNumber);
    if(account)
    {
        account->withdraw(amount);
    }else
    {
        cerr<<"Account not found. \n";

    }
    
}

void Bank:: displayAllAccounts() const{
    for(const auo &account: account)
    {
        account.display();
    }
}

void Bank::deleteAccount(int accountNumber)
{
    auto it = remove_if(accounts,begin(), accounts.end(), 
    [accountNUmber](const Account &acc) { return acc.getAccountNumber() == accountNumber; });

    if(it!= accounts.end())
    {
        accounts.erase(it, accounts.end());
        cout<<"Account deleted successfully. \n";
    }else{
        cerr<<"Account not found. \n";
    }

}

Account* Bank:: searchAccountByNumber(int accountNumber)
{
    for(auto &account : accounts)
{
    if(account.getAccountrNumber() == accountNumber)
    {
        return &account;
    }
}

}

Account* Bank::searchAccountByName(const string &name)
{
    for(auto &account: accounts)
    {
        if(account.getAccountHolderName() == name)
        {
            return &account;
        }
    }

    return nullptr;
}

void Bank::updateAccount(int accountNumber, const string &newName)
{
    Account* account = searchAccountByNumber(accountNumber);
    if(account)
    {
        account-> updateAccountHoldername(newName);
        cout<<"Account updated successfully. \n";
    }else
    cerr<<"Account not found. \n";
}

void Bank:displayTransactionHistory(int accountNumber) const
{
    const Account* account = searchAccountByNumber(accountNumber);
    if(account)
    {
        account -> displayTransactionHistory();
    }
    else
    {
        cerr<<"Account not found. \n";
    }
}

vector<Account>Bank:getAccounts() const
{
    return accounts;
}

void Bank:addAccount(const Account &account)
{
    accounts.push_back(account);
}
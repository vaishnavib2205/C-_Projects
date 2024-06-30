#include "FileHandler.h"
#include<fstream>
#include<iostream>

void FileHandler::saveAccountsToFile(const vector<Account> &accounts, const string &filename)
{
    ofstream file(filename);
    if(!file){
    cerr<<"Error opening file for writing. \n";
    return;
}

for (const auto &account : accounts) {
        file << account.getAccountNumber() << " "
             << account.getAccountHolderName() << " "
             << account.getBalance() << "\n";
}

file.close();
}

vector<Account> FileHandler::loadAccountsFromFile(const string &filename)
{
    ifstream file(filename);
    vector<Account> accounts;

    if(!file)
    {
        cerr<<"Error opening file for reading. \n";
        return accounts;
    }

    int accountNumber;
    string accountHolderName;
    double balance;

    while(file >> accountNumber >> accountHolderName >> balance)
    {
        accounts.emplace_back(accountNumber, accountHolderName, balance);
    }

    file.close();
    return accounts;

}
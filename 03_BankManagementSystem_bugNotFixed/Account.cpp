#include "Account.h"

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionHistory.emplace_back("Deposit", amount);
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactionHistory.emplace_back("Withdraw", amount);
    }
}

void Account::display() const {
    std::cout << "Account Number: " << accountNumber
              << ", Account Holder: " << accountHolderName
              << ", Balance: " << balance << "\n";

    std::cout << "Transaction History:\n";
    for (const auto& transaction : transactionHistory) {
        std::cout << transaction.type << ": " << transaction.amount << "\n";
    }
}

void Account::serialize(std::ofstream &out) const {
    out.write(reinterpret_cast<const char*>(&accountNumber), sizeof(accountNumber));
    size_t nameLength = accountHolderName.size();
    out.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    out.write(accountHolderName.c_str(), nameLength);
    out.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
    
    size_t historySize = transactionHistory.size();
    out.write(reinterpret_cast<const char*>(&historySize), sizeof(historySize));
    for (const auto& transaction : transactionHistory) {
        transaction.serialize(out);
    }
}

void Account::deserialize(std::ifstream &in) {
    in.read(reinterpret_cast<char*>(&accountNumber), sizeof(accountNumber));
    
    size_t nameLength;
    in.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    accountHolderName.resize(nameLength);
    in.read(&accountHolderName[0], nameLength);
    
    in.read(reinterpret_cast<char*>(&balance), sizeof(balance));
    
    size_t historySize;
    in.read(reinterpret_cast<char*>(&historySize), sizeof(historySize));
    transactionHistory.resize(historySize);
    for (auto& transaction : transactionHistory) {
        transaction.deserialize(in);
    }
}

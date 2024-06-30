#include "FileHandler.h"
#include <fstream>

void FileHandler::saveToFile(const Bank& bank, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Unable to open file for saving.");
    }

    const std::vector<Account>& accounts = bank.getAccounts();
    size_t numAccounts = accounts.size();
    outFile.write(reinterpret_cast<const char*>(&numAccounts), sizeof(numAccounts));
    for (const auto& account : accounts) {
        account.serialize(outFile);
    }
}

void FileHandler::loadFromFile(Bank& bank, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Unable to open file for loading.");
    }

    size_t numAccounts;
    inFile.read(reinterpret_cast<char*>(&numAccounts), sizeof(numAccounts));
    for (size_t i = 0; i < numAccounts; ++i) {
        Account account;
        account.deserialize(inFile);
        bank.createAccount(account.getAccountNumber(), account.getAccountHolderName(), account.getBalance());
    }
}

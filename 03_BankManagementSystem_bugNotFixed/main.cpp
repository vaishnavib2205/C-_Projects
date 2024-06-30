#include <iostream>
#include "Bank.h"
#include "FileHandler.h"

void displayMenu() {
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Display All Accounts\n";
    std::cout << "5. Delete Account\n";
    std::cout << "6. Save to File\n";
    std::cout << "7. Load from File\n";
    std::cout << "0. Exit\n";
}

int main() {
    Bank bank;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int accountNumber;
                    std::string accountHolderName;
                    double initialBalance;
                    std::cout << "Enter Account Number: ";
                    std::cin >> accountNumber;
                    std::cout << "Enter Account Holder Name: ";
                    std::cin.ignore();
                    std::getline(std::cin, accountHolderName);
                    std::cout << "Enter Initial Balance: ";
                    std::cin >> initialBalance;
                    bank.createAccount(accountNumber, accountHolderName, initialBalance);
                    break;
                }
                case 2: {
                    int accountNumber;
                    double amount;
                    std::cout << "Enter Account Number: ";
                    std::cin >> accountNumber;
                    std::cout << "Enter Amount to Deposit: ";
                    std::cin >> amount;
                    bank.depositToAccount(accountNumber, amount);
                    break;
                }
                case 3: {
                    int accountNumber;
                    double amount;
                    std::cout << "Enter Account Number: ";
                    std::cin >> accountNumber;
                    std::cout << "Enter Amount to Withdraw: ";
                    std::cin >> amount;
                    bank.withdrawFromAccount(accountNumber, amount);
                    break;
                }
                case 4: {
                    bank.displayAllAccounts();
                    break;
                }
                case 5: {
                    int accountNumber;
                    std::cout << "Enter Account Number: ";
                    std::cin >> accountNumber;
                    bank.deleteAccount(accountNumber);
                    break;
                }
                case 6: {
                    std::string filename;
                    std::cout << "Enter filename to save: ";
                    std::cin >> filename;
                    FileHandler::saveToFile(bank, filename);
                    break;
                }
                case 7: {
                    std::string filename;
                    std::cout << "Enter filename to load: ";
                    std::cin >> filename;
                    FileHandler::loadFromFile(bank, filename);
                    break;
                }
                case 0: {
                    std::cout << "Exiting...\n";
                    break;
                }
                default: {
                    std::cerr << "Invalid choice. Please try again.\n";
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}

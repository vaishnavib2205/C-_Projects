#include <iostream>
#include <vector>
#include "Account.h"
#include "FileHandler.h"
using namespace std;

// Function prototypes
void displayMenu();
void createAccount(vector<Account>& accounts);
void depositToAccount(vector<Account>& accounts);
void displayAllAccounts(const vector<Account>& accounts);
void deleteAccount(vector<Account>& accounts);

int main() {
    vector<Account> accounts = FileHandler::loadAccounts();
    int choice;

    do {
        displayMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    createAccount(accounts);
                    break;
                case 2:
                    depositToAccount(accounts);
                    break;
                case 3:
                    displayAllAccounts(accounts);
                    break;
                case 4:
                    deleteAccount(accounts);
                    break;
                case 5:
                    FileHandler::saveAccounts(accounts);
                    cout << "Accounts saved successfully. Exiting...\n";
                    break;
                default:
                    cerr << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n--- Bank Management System ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit to Account\n";
    cout << "3. Display All Accounts\n";
    cout << "4. Delete Account\n";
    cout << "5. Save and Exit\n";
    cout << "Enter your choice: ";
}

void createAccount(vector<Account>& accounts) {
    int accNum;
    string name;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cin.ignore();  // Ignore the newline character left in the buffer

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    accounts.emplace_back(accNum, name, initialBalance);
    std::cout << "Account created successfully.\n";
}

void depositToAccount(std::vector<Account>& accounts) {
    int accNum;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accNum;

    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            account.deposit(amount);
            std::cout << "Deposit successful.\n";
            return;
        }
    }

    std::cerr << "Account not found.\n";
}

void displayAllAccounts(const std::vector<Account>& accounts) {
    if (accounts.empty()) {
        std::cout << "No accounts to display.\n";
        return;
    }

    for (const auto& account : accounts) {
        account.display();
    }
}

void deleteAccount(std::vector<Account>& accounts) {
    int accNum;

    std::cout << "Enter account number to delete: ";
    std::cin >> accNum;

    auto it = std::remove_if(accounts.begin(), accounts.end(),
        [accNum](const Account& acc) { return acc.getAccountNumber() == accNum; });

    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        std::cout << "Account deleted successfully.\n";
    } else {
        std::cerr << "Account not found.\n";
    }
}

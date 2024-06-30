#include "ContactManager.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Add Contact" << std::endl;
    std::cout << "2. Display All Contacts" << std::endl;
    std::cout << "3. Search Contact" << std::endl;
    std::cout << "4. Delete Contact" << std::endl; // New menu option
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ContactManager manager;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string name, phone, email;
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter Phone: ";
            std::cin >> phone;
            std::cout << "Enter Email: ";
            std::cin >> email;
            manager.addContact(Contact(name, phone, email));
        } else if (choice == 2) {
            manager.displayContacts();
        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter Name to Search: ";
            std::cin >> name;
            manager.searchContact(name);
        } else if (choice == 4) { // Handling delete contact option
            std::string name;
            std::cout << "Enter Name to Delete: ";
            std::cin >> name;
            manager.deleteContact(name);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

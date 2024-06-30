#include "ContactManager.h"
#include <fstream>
#include <iostream>
using namespace std;

ContactManager::ContactManager() {
    loadContacts();
}

void ContactManager::loadContacts() {
    std::ifstream file("contacts.txt");
    if (file.is_open()) {
        std::string name, phone, email;
        while (file >> name >> phone >> email) {
            contacts.emplace_back(name, phone, email);
        }
        file.close();
    }
}

void ContactManager::saveContacts() {
    std::ofstream file("contacts.txt");
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.getName() << " " << contact.getPhone() << " " << contact.getEmail() << std::endl;
        }
        file.close();
    }
}

void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
    saveContacts();
}

void ContactManager::deleteContact(const std::string& name){
    for (auto contact = contacts.begin(); contact <= contacts.end(); ++contact) {
        if (contact->getName() == name) {
            contacts.erase(contact);
            saveContacts();
            std::cout << "Contact deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}
void ContactManager::displayContacts() const {
    for (const auto& contact : contacts) {
        contact.display();
    }
}

void ContactManager::searchContact(const std::string& name) const {
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            contact.display();
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

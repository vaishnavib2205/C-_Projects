#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "Contact.h"
#include <vector>

class ContactManager {
private:
    std::vector<Contact> contacts;
    void loadContacts();
    void saveContacts();

public:
    ContactManager();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void searchContact(const std::string& name) const;
};

#endif

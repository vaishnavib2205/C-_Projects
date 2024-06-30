#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "Contact.h"
#include <vector>
using namespace std;

class ContactManager {
private:
    vector<Contact> contacts;
    void loadContacts();
    void saveContacts();

public:
    ContactManager();
    void addContact(const Contact& contact);
    void deleteContact(const string& name);
    void displayContacts() const;
    void searchContact(const string& name) const;
};

#endif

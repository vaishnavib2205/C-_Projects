// user.cpp
#include "user.h"
#include "database.h"

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

bool User::authenticate(const std::string& username, const std::string& password) {
    // Implement SQL query to check username and password
    return false; // Placeholder for simplicity
}

void User::registerUser(const std::string& username, const std::string& password) {
    // Implement SQL query to insert new user
}


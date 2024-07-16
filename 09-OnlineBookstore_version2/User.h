#ifndef USER_H
#define USER_H

#include "Database.h"
#include <vector>
#include <string>

class User {
public:
    User(Database& db);
    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    bool updateUser(int userId, const std::string& newUsername, const std::string& newPassword);
    bool deleteUser(int userId);
    std::vector<std::vector<std::string>> getUsers();

private:
    Database& db;
};

#endif

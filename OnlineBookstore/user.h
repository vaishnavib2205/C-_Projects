// user.h
#pragma once
#include <string>

class User {
public:
    User(const std::string& username, const std::string& password);

    static bool authenticate(const std::string& username, const std::string& password);
    static void registerUser(const std::string& username, const std::string& password);

private:
    std::string username;
    std::string password;
};


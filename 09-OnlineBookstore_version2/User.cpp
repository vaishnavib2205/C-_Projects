#include "User.h"
#include <iostream>
#include <sqlite3.h>

User::User(Database& db) : db(db) {}

bool User::registerUser(const std::string& username, const std::string& password) {
    std::string sql = "INSERT INTO Users (username, password) VALUES ('" + username + "', '" + password + "');";
    return db.execute(sql);
}

bool User::login(const std::string& username, const std::string& password) {
    sqlite3_stmt* stmt;
    std::string sql = "SELECT * FROM Users WHERE username = '" + username + "' AND password = '" + password + "';";
    if (sqlite3_prepare_v2(db.getDb(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db.getDb()) << std::endl;
        return false;
    }
    bool result = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "User logged in successfully" << std::endl;
        result = true;
    }
    else {
        std::cout << "Invalid username or password" << std::endl;
    }
    sqlite3_finalize(stmt);
    return result;
}

bool User::updateUser(int userId, const std::string& newUsername, const std::string& newPassword) {
    std::string sql = "UPDATE Users SET username = '" + newUsername + "', password = '" + newPassword + "' WHERE id = " + std::to_string(userId) + ";";
    return db.execute(sql);
}

bool User::deleteUser(int userId) {
    std::string sql = "DELETE FROM Users WHERE id = " + std::to_string(userId) + ";";
    return db.execute(sql);
}

std::vector<std::vector<std::string>> User::getUsers() {
    std::vector<std::vector<std::string>> users;
    sqlite3_stmt* stmt;
    std::string sql = "SELECT * FROM Users;";
    if (sqlite3_prepare_v2(db.getDb(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db.getDb()) << std::endl;
        return users;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> user;
        user.push_back(std::to_string(sqlite3_column_int(stmt, 0)));
        user.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        user.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        users.push_back(user);
    }
    sqlite3_finalize(stmt);
    return users;
}

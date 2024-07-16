#ifndef DATABASE_H
#define DATABASE_H

#include "C:\sqlite\sqlite3.h"
#include <string>

class Database {
public:
    Database(const std::string& db_name);
    ~Database();

    bool execute(const std::string& sql);
    sqlite3* getDb() const;

private:
    sqlite3* db;
    char* err_msg;
};

#endif

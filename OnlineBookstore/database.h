// database.h
#pragma once
#include <string>

class Database {
public:
    static void init(const std::string& filename);
    static void executeQuery(const std::string& query);
};


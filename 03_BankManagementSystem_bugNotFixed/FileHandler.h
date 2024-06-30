#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Bank.h"
#include <string>

class FileHandler {
public:
    static void saveToFile(const Bank& bank, const std::string& filename);
    static void loadFromFile(Bank& bank, const std::string& filename);
};

#endif

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <fstream>

class Transaction {
public:
    std::string type;
    double amount;

    Transaction(const std::string& type = "", double amount = 0.0) 
        : type(type), amount(amount) {}

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);
};

#endif

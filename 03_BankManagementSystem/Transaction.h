#define TRANSACTION_H

#include<string>
using namespace std;

class Transaction{
    private:
    string type;
    double amount;

    public:
    Transaction(const std::string &type, double amount);
    void display() const;
};

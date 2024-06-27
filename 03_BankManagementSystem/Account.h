#define ACCOUNT_H

#include <string>
#include<vector>
#include "Transaction.h"
using namespace std;

class Account{

private:

    int accountNumber;
    string accountHolderName;
    double balace;
    vector<Transaction> transactionHistory;

    

};
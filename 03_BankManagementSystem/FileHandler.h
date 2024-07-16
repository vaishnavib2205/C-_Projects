#define FILEHANDLER_H

#include "Account.h"
#include<vector>
#include<string>

using namespace std;

class FileHandler
{
    public:
    static void saveAccountsToFile(const vector<Account> &accounts, const string &filename);
    static vector<Account> loadAccountsFromFile(const string &filename);

};


#include"Transaction.h"
#include <iostream>
#include<iomanip>
using namespace std;


Transaction::Transaction(const string &type, double amount)
: type(type), amount(amount){

}

void Transaction::display() const{
    cout<<setw(10)<<type<<": "<<"\n";
    
}
#ifndef ORDER_H
#define ORDER_H

#include "Database.h"
#include <vector>
#include <string>

class Order {
public:
    Order(Database& db);
    bool placeOrder(int userId, int bookId);
    std::vector<std::vector<std::string>> getOrders();

private:
    Database& db;
};

#endif

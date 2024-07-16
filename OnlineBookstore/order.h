// order.h
#pragma once
#include <vector>

class Order {
public:
    Order(int userId, const std::vector<int>& bookIds);

    static void createOrder(int userId, const std::vector<int>& bookIds);
};


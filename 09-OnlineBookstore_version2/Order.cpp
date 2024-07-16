#include "Order.h"
#include<iostream>
#include<vector>
#include<string>

Order::Order(Database& db) : db(db) {}

bool Order::placeOrder(int userId, int bookId) {
    std::string sql = "INSERT INTO Orders (user_id, book_id) VALUES (" + std::to_string(userId) + ", " + std::to_string(bookId) + ");";
    return db.execute(sql);
}

std::vector<std::vector<std::string>> Order::getOrders() {
    std::vector<std::vector<std::string>> orders;
    sqlite3_stmt* stmt;
    std::string sql = "SELECT * FROM Orders;";
    if (sqlite3_prepare_v2(db.getDb(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db.getDb()) << std::endl;
        return orders;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> order;
        order.push_back(std::to_string(sqlite3_column_int(stmt, 0)));
        order.push_back(std::to_string(sqlite3_column_int(stmt, 1)));
        order.push_back(std::to_string(sqlite3_column_int(stmt, 2)));
        orders.push_back(order);
    }
    sqlite3_finalize(stmt);
    return orders;
}

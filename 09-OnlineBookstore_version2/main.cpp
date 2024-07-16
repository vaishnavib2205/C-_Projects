#include <iostream>
#include "Database.h"
#include "User.h"
#include "Book.h"
#include "Order.h"

void printUsers(const std::vector<std::vector<std::string>>& users) {
    for (const auto& user : users) {
        std::cout << "ID: " << user[0] << ", Username: " << user[1] << ", Password: " << user[2] << std::endl;
    }
}

void printBooks(const std::vector<std::vector<std::string>>& books) {
    for (const auto& book : books) {
        std::cout << "ID: " << book[0] << ", Title: " << book[1] << ", Author: " << book[2] << ", Price: " << book[3] << std::endl;
    }
}

void printOrders(const std::vector<std::vector<std::string>>& orders) {
    for (const auto& order : orders) {
        std::cout << "ID: " << order[0] << ", User ID: " << order[1] << ", Book ID: " << order[2] << std::endl;
    }
}

int main() {
    Database db("bookstore.db");

    // Create tables
    db.execute("CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY, username TEXT, password TEXT);");
    db.execute("CREATE TABLE IF NOT EXISTS Books (id INTEGER PRIMARY KEY, title TEXT, author TEXT, price REAL);");
    db.execute("CREATE TABLE IF NOT EXISTS Orders (id INTEGER PRIMARY KEY, user_id INTEGER, book_id INTEGER);");

    // Users
    User user(db);
    user.registerUser("john_doe", "password123");
    user.registerUser("jane_smith", "mypassword");

    std::cout << "Users:" << std::endl;
    printUsers(user.getUsers());

    user.updateUser(1, "john_doe_updated", "newpassword123");
    std::cout << "Users after update:" << std::endl;
    printUsers(user.getUsers());

    user.deleteUser(2);
    std::cout << "Users after deletion:" << std::endl;
    printUsers(user.getUsers());

    // Books
    Book book(db);
    book.addBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
    book.addBook("1984", "George Orwell", 8.99);

    std::cout << "Books:" << std::endl;
    printBooks(book.getBooks());

    book.updateBook(1, "The Great Gatsby - Updated", "F. Scott Fitzgerald", 12.99);
    std::cout << "Books after update:" << std::endl;
    printBooks(book.getBooks());

    book.deleteBook(2);
    std::cout << "Books after deletion:" << std::endl;
    printBooks(book.getBooks());

    // Orders
    Order order(db);
    order.placeOrder(1, 1);

    std::cout << "Orders:" << std::endl;
    printOrders(order.getOrders());

    return 0;
}

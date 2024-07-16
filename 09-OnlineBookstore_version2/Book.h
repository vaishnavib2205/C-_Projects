#ifndef BOOK_H
#define BOOK_H

#include "Database.h"
#include <vector>
#include <string>

class Book {
public:
    Book(Database& db);
    bool addBook(const std::string& title, const std::string& author, double price);
    bool updateBook(int bookId, const std::string& newTitle, const std::string& newAuthor, double newPrice);
    bool deleteBook(int bookId);
    std::vector<std::vector<std::string>> getBooks();

private:
    Database& db;
};

#endif

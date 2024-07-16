// book.h
#pragma once
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, double price);

    static void listBooks();
};


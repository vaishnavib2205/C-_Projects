#include "Book.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

Book::Book(Database& db) : db(db) {}

bool Book::addBook(const string& title, const string& author, double price) {
    string sql = "INSERT INTO Books (title, author, price) VALUES ('" + title + "', '" + author + "', " + to_string(price) + ");";
    return db.execute(sql);
}

bool Book::updateBook(int bookId, const string& newTitle, const string& newAuthor, double newPrice) {
    string sql = "UPDATE Books SET title = '" + newTitle + "', author = '" + newAuthor + "', price = " + to_string(newPrice) + " WHERE id = " + to_string(bookId) + ";";
    return db.execute(sql);
}

bool Book::deleteBook(int bookId) {
    string sql = "DELETE FROM Books WHERE id = " + to_string(bookId) + ";";
    return db.execute(sql);
}

vector<vector<string>> Book::getBooks() {
    vector<vector<string>> books;
    sqlite3_stmt* stmt;
    string sql = "SELECT * FROM Books;";
    if (sqlite3_prepare_v2(db.getDb(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to execute statement: " << sqlite3_errmsg(db.getDb()) << endl;
        return books;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        vector<string> book;
        book.push_back(to_string(sqlite3_column_int(stmt, 0)));
        book.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        book.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        book.push_back(to_string(sqlite3_column_double(stmt, 3)));
        books.push_back(book);
    }
    sqlite3_finalize(stmt);
    return books;
}

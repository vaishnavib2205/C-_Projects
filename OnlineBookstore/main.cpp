#include <iostream>
#include "database.h"
#include "user.h"
#include "book.h"
#include "order.h"

int main() {
    // Initialize SQLite database
    Database::init("sqlite.db");

    // Example usage
    User::registerUser("user1", "password1");
    /*bool authenticated = User::authenticate("user1", "password1");
    if (authenticated) {
        std::cout << "Login successful!\n";
    }
    else {
        std::cout << "Invalid username or password.\n";
    }*/

    Book::listBooks();

    return 0;
}

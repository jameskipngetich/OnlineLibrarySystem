#include "Library.hpp"
#include <iostream>

// This is our test file
// use this to confitm that our system works as expected
int main() {
    Library lib;
    lib.showWelcomeMessage();

    cout << "\n=============================\n";
    cout << "TEST CASE 01: Add and Display Book\n";
    lib.addBook();  // We add and display the books

    cout << "\nTEST CASE 02: Add and Display User\n";
    lib.addUser();  // we add and display our users 

    // our isolated tests
    cout << "\nTEST CASE 03: Borrowing all copies should mark book unavailable\n";
    Book b1;
    b1.setBook("Book_Test_1");
    b1.updateCopies(2, b1.isAvailable() ? 1 : 0); // Borrow 1
    b1.updateCopies(2, b1.isAvailable() ? b1.isAvailable() : 0); // Borrow remaining if available
    b1.display();
    cout << "Book available? " << (b1.isAvailable() ? "Yes" : "No") << "\n";

    cout << "\nTEST CASE 04: User gets blacklisted after losing 3 books\n";
    User u1;
    u1.setUser("User_Test_1");
    u1.updateBooks(3, 1);  // Lost 1
    u1.updateBooks(3, 1);  // Lost 2
    u1.updateBooks(3, 1);  // Lost 3 -> Should now be blacklisted
    u1.display();
    cout << "User blacklisted? " << (u1.isBlacklisted() ? "Yes" : "No") << "\n";

    cout << "\nTEST CASE 05: Losing a book updates totals correctly\n";
    Book b2;
    b2.setBook("Book_Test_2");
    //int before = b2.isAvailable();
    b2.updateCopies(3, 1); // Lost 1 copy
    b2.display();

    cout << "\nTEST CASE 06: Search for a Book by Title\n";
    string searchTitle;
    cout << "Enter book title to search: ";
    cin >> searchTitle;
    lib.searchBookByTitle(searchTitle);

    return 0;
}

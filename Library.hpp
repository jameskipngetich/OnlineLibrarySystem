#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include "User.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<User> users;
    string name = "Zetech Public Library";

public:
    void addBook() {
        string id = "Book_" + to_string(books.size() + 1);
        Book b;
        b.setBook(id);
        books.push_back(b);
    }

    void addUser() {
        string id = "User_" + to_string(users.size() + 1);
        User u;
        u.setUser(id);
        users.push_back(u);
    }

    void displayBooks() {
        for (const auto& b : books) b.display();
    }

    void displayUsers() {
        for (const auto& u : users) u.display();
    }

    void showWelcomeMessage() {
        cout << "=== Welcome to " << name << " ===" << endl;
    }

    // OUr search function
    // Search for a book by title
    void searchBookByTitle(const string& keyword) {
        cout << "\n====== Searching for: " << keyword << " ======" << endl;
        bool found = false;

        for (auto& book : books) {
            if (book.getTitle() == keyword) {
                book.display();
                found = true;
                break; 
            }
        }

        if (!found) {
            cout << "Book titled \"" << keyword << "\" not found in the library.\n";
        }
    }

};

#endif

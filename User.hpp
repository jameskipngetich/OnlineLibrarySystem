#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <vector>
using namespace std;

class User {
private:
    string id, name, contactInfo;
    int booksInPossession;
    int booksLost;
    bool blacklisted;

public:
    User() : booksInPossession(0), booksLost(0), blacklisted(false) {}

    void setUser(string userId) {
        id = userId;
        cout << "\n=== Adding a User ===\n";
        cout << "Name: "; cin >> name;
        cout << "Contact Info: "; cin >> contactInfo;
    }

    void updateBooks(int operation, int number) {
        if (operation == 1) booksInPossession -= number;        // Return
        else if (operation == 2) booksInPossession += number;   // Borrow
        else if (operation == 3) {                              // Lost
            booksLost += number;
            if (booksLost >= 3) blacklisted = true;
        }
    }

    void display() const {
        cout << "\n=== User Info ===\n";
        cout << "ID: " << id << "\nName: " << name
             << "\nContact: " << contactInfo
             << "\nBooks in Possession: " << booksInPossession
             << "\nBooks Lost: " << booksLost
             << "\nStatus: " << (blacklisted ? "BLACKLISTED" : "WHITELISTED") << endl;
    }

    bool isBlacklisted() const { return blacklisted; }
    string getId() const { return id; }
};

#endif

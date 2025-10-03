#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
using namespace std;

enum DemandState { HOT, MODERATE, COLD };

class Book {
private:
    string id, title, author, description;
    int totalCopies, availableCopies, lostCopies;
    DemandState demand;
    bool available;

public:
    Book() : totalCopies(0), availableCopies(0), lostCopies(0), demand(MODERATE), available(false) {}

    void setBook(string bookId) {
        id = bookId;
        cout << "\n=== Adding a Book ===\n";
        cout << "Title: "; cin >> title;
        cout << "Author: "; cin >> author;
        cout << "Description: "; cin >> description;
        cout << endl;
        cout << "Total Copies: "; cin >> totalCopies;
        availableCopies = totalCopies;

        string demandInput;
        cout << "Demand (hot/moderate/cold): "; cin >> demandInput;
        if (demandInput == "hot") demand = HOT;
        else if (demandInput == "cold") demand = COLD;
        else demand = MODERATE;

        updateAvailability();
    }

    void updateCopies(int operation, int number) {
        if (operation == 1) availableCopies += number;         // Return
        else if (operation == 2) availableCopies -= number;    // Borrow
        else if (operation == 3) {                             // Lost
            totalCopies -= number;
            lostCopies += number;
        }
        updateAvailability();
    }

    void updateAvailability() {
        available = availableCopies > 0;
    }

    void display() const {
        cout << "\n=== Book Info ===\n";
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author
             << "\nDescription: " << description
             << "\nAvailable Copies: " << availableCopies
             << "\nTotal Copies: " << totalCopies
             << "\nDemand: " << (demand == HOT ? "HOT" : (demand == COLD ? "COLD" : "MODERATE")) << endl;
    }

    string getId() const { return id; }
    string getTitle() const { return title; }
    bool isAvailable() const { return availableCopies > 0; }
   // string getTitle() const { return title; }

};

#endif

#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, string a, string id) : LibraryItem(t, a, id), borrowed(false) {}

void Book::display() const {
    cout << "[Book] ID: " << itemID << ", Title: " << title << ", Author: " << author;
    if (borrowed) cout << " (Borrowed)";
    cout << endl;
}

bool Book::isBorrowable() const {
    return true;
}

bool Book::isBorrowed() const {
    return borrowed;
}

void Book::borrow() {
    borrowed = true;
}

void Book::returned() {
    borrowed = false;
}

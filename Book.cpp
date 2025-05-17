#include "Book.h"
#include <iostream>

Book::Book(std::string t, std::string a, std::string id)
    : LibraryItem(t, a, id), borrowed(false) {}

void Book::display() const {
    std::cout << "[Book] ID: " << itemID << ", Title: " << title << ", Author: " << author;
    if (borrowed) std::cout << " (Borrowed)";
    std::cout << std::endl;
}

bool Book::isBorrowable() const { return true; }
bool Book::isBorrowed() const { return borrowed; }
void Book::borrow() { borrowed = true; }
void Book::returned() { borrowed = false; }

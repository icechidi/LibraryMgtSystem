#include "Magazine.h"
#include <iostream>

Magazine::Magazine(std::string t, std::string a, std::string id)
    : LibraryItem(t, a, id) {}

void Magazine::display() const {
    std::cout << "[Magazine] ID: " << itemID << ", Title: " << title << ", Author: " << author << std::endl;
}

bool Magazine::isBorrowable() const { return false; }

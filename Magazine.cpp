#include "Magazine.h"
#include <iostream>
using namespace std;

Magazine::Magazine(string t, string a, string id) : LibraryItem(t, a, id) {}

void Magazine::display() const {
    cout << "[Magazine] ID: " << itemID << ", Title: " << title << ", Author: " << author << endl;
}

bool Magazine::isBorrowable() const {
    return false;
}

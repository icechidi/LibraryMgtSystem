#include "User.h"

User::User() : userID(""), name("") {}

User::User(string id, string n) : userID(id), name(n) {}

void User::borrowItem(string itemID) {
    borrowedItems.push_back(itemID);
}

void User::returnItem(string itemID) {
    auto it = find(borrowedItems.begin(), borrowedItems.end(), itemID);
    if (it != borrowedItems.end())
        borrowedItems.erase(it);
}

bool User::hasBorrowed(string itemID) const {
    return find(borrowedItems.begin(), borrowedItems.end(), itemID) != borrowedItems.end();
}

void User::display() const {
    cout << "User ID: " << userID << ", Name: " << name << endl;
}

#include "User.h"

User::User() : userID(""), name("") {}
User::User(std::string id, std::string n) : userID(id), name(n) {}

void User::borrowItem(std::string itemID) {
    borrowedItems.push_back(itemID);
}

void User::returnItem(std::string itemID) {
    auto it = std::find(borrowedItems.begin(), borrowedItems.end(), itemID);
    if (it != borrowedItems.end())
        borrowedItems.erase(it);
}

bool User::hasBorrowed(std::string itemID) const {
    return std::find(borrowedItems.begin(), borrowedItems.end(), itemID) != borrowedItems.end();
}

void User::display() const {
    std::cout << "User ID: " << userID << ", Name: " << name << std::endl;
}

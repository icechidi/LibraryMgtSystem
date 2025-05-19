#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class User {
    std::string userID, name;
    std::vector<std::string> borrowedItems;
public:
    User();
    User(std::string id, std::string n);
    void borrowItem(std::string itemID);
    void returnItem(std::string itemID);
    bool hasBorrowed(std::string itemID) const;
    void display() const;
};

#endif

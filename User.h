#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class User {
    string userID, name;
    vector<string> borrowedItems;
public:
    User();
    User(string id, string n);
    void borrowItem(string itemID);
    void returnItem(string itemID);
    bool hasBorrowed(string itemID) const;
    void display() const;
};

#endif

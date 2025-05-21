#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <map>
#include <memory>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "User.h"
#include "LibraryException.h"
using namespace std;

class LibrarySystem {
    map<string, unique_ptr<LibraryItem>> items;
    map<string, User> users;

    void logTransaction(const string& action);

public:
    void addBook(string title, string author, string id);
    void addMagazine(string title, string author, string id);
    void addUser(string name, string id);
    void borrowBook(string userID, string bookID);
    void returnBook(string userID, string bookID);
    void displayAllItems() const;
    void displayAllUsers() const;
    void searchByTitle(const string& keyword) const;
};

#endif

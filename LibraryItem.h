#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title, author, itemID;
public:
    LibraryItem(string t, string a, string id);
    virtual void display() const = 0;
    string getID() const;
    string getTitle() const;
    virtual bool isBorrowable() const = 0;
    virtual ~LibraryItem();
};

#endif

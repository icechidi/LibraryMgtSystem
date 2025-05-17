#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
#include <string>

class LibraryItem {
protected:
    std::string title, author, itemID;
public:
    LibraryItem(std::string t, std::string a, std::string id);
    virtual void display() const = 0;
    std::string getID() const;
    std::string getTitle() const;
    virtual bool isBorrowable() const = 0;
    virtual ~LibraryItem() {}
};

#endif

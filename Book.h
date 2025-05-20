#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
    bool borrowed;
public:
    Book(string t, string a, string id);
    void display() const override;
    bool isBorrowable() const override;
    bool isBorrowed() const;
    void borrow();
    void returned();
};

#endif

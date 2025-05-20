#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
public:
    Magazine(string t, string a, string id);
    void display() const override;
    bool isBorrowable() const override;
};

#endif

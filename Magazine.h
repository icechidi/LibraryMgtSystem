#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
public:
    Magazine(std::string t, std::string a, std::string id);
    void display() const override;
    bool isBorrowable() const override;
};

#endif

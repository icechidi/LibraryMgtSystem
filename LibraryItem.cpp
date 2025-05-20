#include "LibraryItem.h"

LibraryItem::LibraryItem(string t, string a, string id) : title(t), author(a), itemID(id) {}

string LibraryItem::getID() const {
    return itemID;
}

string LibraryItem::getTitle() const {
    return title;
}

LibraryItem::~LibraryItem() {}

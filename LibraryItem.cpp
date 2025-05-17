#include "LibraryItem.h"

LibraryItem::LibraryItem(std::string t, std::string a, std::string id)
    : title(t), author(a), itemID(id) {}

std::string LibraryItem::getID() const { return itemID; }
std::string LibraryItem::getTitle() const { return title; }

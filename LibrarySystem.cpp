#include "LibrarySystem.h"

void LibrarySystem::logTransaction(const string& action) {
    ofstream log("transactions.txt", ios::app);
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    log << "[" << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << "] " << action << endl;
}

void LibrarySystem::addBook(string title, string author, string id) {
    items[id] = unique_ptr<LibraryItem>(new Book(title, author, id));
}

void LibrarySystem::addMagazine(string title, string author, string id) {
    items[id] = unique_ptr<LibraryItem>(new Magazine(title, author, id));
}

void LibrarySystem::addUser(string name, string id) {
    users[id] = User(id, name);
}

void LibrarySystem::borrowBook(string userID, string bookID) {
    if (users.find(userID) == users.end()) throw LibraryException("User not found.");
    if (items.find(bookID) == items.end()) throw LibraryException("Item not found.");

    Book* book = dynamic_cast<Book*>(items[bookID].get());
    if (!book) throw LibraryException("Item is not a book.");
    if (book->isBorrowed()) {
        logTransaction("User: " + userID + " attempted to borrow already borrowed book " + bookID);
        throw LibraryException("Book already borrowed.");
    }

    book->borrow();
    users[userID].borrowItem(bookID);
    logTransaction("User: " + userID + " borrowed book " + bookID);
}

void LibrarySystem::returnBook(string userID, string bookID) {
    if (users.find(userID) == users.end()) throw LibraryException("User not found.");
    if (items.find(bookID) == items.end()) throw LibraryException("Item not found.");

    Book* book = dynamic_cast<Book*>(items[bookID].get());
    if (!book) throw LibraryException("Item is not a book.");
    if (!users[userID].hasBorrowed(bookID)) throw LibraryException("User did not borrow this book.");

    book->returned();
    users[userID].returnItem(bookID);
    logTransaction("User: " + userID + " returned book " + bookID);
}

void LibrarySystem::displayAllItems() const {
    for (const auto& p : items) {
        p.second->display();
    }
}

void LibrarySystem::displayAllUsers() const {
    for (const auto& p : users) {
        p.second.display();
    }
}

void LibrarySystem::searchByTitle(const string& keyword) const {
    cout << "Searching for title containing: " << keyword << endl;
    for (const auto& p : items) {
        if (p.second->getTitle().find(keyword) != string::npos)
            p.second->display();
    }
}

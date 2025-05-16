// Library Management System Project
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <memory> 

using namespace std;

class LibraryItem {
protected:
    string title, author, itemID;
public:
    LibraryItem(string t, string a, string id) : title(t), author(a), itemID(id) {}
    virtual void display() const = 0;
    string getID() const { return itemID; }
    string getTitle() const { return title; }
    virtual bool isBorrowable() const = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
    bool borrowed;
public:
    Book(string t, string a, string id) : LibraryItem(t, a, id), borrowed(false) {}
    void display() const override {
        cout << "[Book] ID: " << itemID << ", Title: " << title << ", Author: " << author;
        if (borrowed) cout << " (Borrowed)";
        cout << endl;
    }
    bool isBorrowable() const override { return true; }
    bool isBorrowed() const { return borrowed; }
    void borrow() { borrowed = true; }
    void returned() { borrowed = false; }
};

class Magazine : public LibraryItem {
public:
    Magazine(string t, string a, string id) : LibraryItem(t, a, id) {}
    void display() const override {
        cout << "[Magazine] ID: " << itemID << ", Title: " << title << ", Author: " << author << endl;
    }
    bool isBorrowable() const override { return false; }
};

class User {
    string userID, name;
    vector<string> borrowedItems;
public:
    User() : userID(""), name("") {}
    User(string id, string n) : userID(id), name(n) {}

    void borrowItem(string itemID) { borrowedItems.push_back(itemID); }
    void returnItem(string itemID) {
        auto it = find(borrowedItems.begin(), borrowedItems.end(), itemID);
        if (it != borrowedItems.end())
            borrowedItems.erase(it);
    }
    bool hasBorrowed(string itemID) const {
        return find(borrowedItems.begin(), borrowedItems.end(), itemID) != borrowedItems.end();
    }
    void display() const {
        cout << "User ID: " << userID << ", Name: " << name << endl;
    }
};

class LibraryException : public runtime_error {
public:
    LibraryException(const string& msg) : runtime_error(msg) {}
};

class LibrarySystem {
    map<string, unique_ptr<LibraryItem>> items;
    map<string, User> users;

    void logTransaction(const string& action) {
        ofstream log("transactions.txt", ios::app);
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        log << "[" << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << "] " << action << endl;
    }

public:
    void addBook(string title, string author, string id) {
        items[id] = unique_ptr<LibraryItem>(new Book(title, author, id));
    }

    void addMagazine(string title, string author, string id) {
        items[id] = unique_ptr<LibraryItem>(new Magazine(title, author, id));
    }

    void addUser(string name, string id) {
        users[id] = User(id, name);
    }

    void borrowBook(string userID, string bookID) {
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

    void returnBook(string userID, string bookID) {
        if (users.find(userID) == users.end()) throw LibraryException("User not found.");
        if (items.find(bookID) == items.end()) throw LibraryException("Item not found.");

        Book* book = dynamic_cast<Book*>(items[bookID].get());
        if (!book) throw LibraryException("Item is not a book.");
        if (!users[userID].hasBorrowed(bookID)) throw LibraryException("User did not borrow this book.");

        book->returned();
        users[userID].returnItem(bookID);
        logTransaction("User: " + userID + " returned book " + bookID);
    }

    void displayAllItems() const {
        for (const auto& p : items) {
            p.second->display();
        }
    }

    void displayAllUsers() const {
        for (const auto& p : users) {
            p.second.display();
        }
    }

    void searchByTitle(const string& keyword) const {
        cout << "Searching for title containing: " << keyword << endl;
        for (const auto& p : items) {
            if (p.second->getTitle().find(keyword) != string::npos)
                p.second->display();
        }
    }
};

int main() {
    LibrarySystem lib;
    int choice;
    string title, author, id, userName, userID;

    do {
        cout << "\nLibrary System Menu:\n";
        cout << "1. Add Book\n2. Add Magazine\n3. Add User\n4. Borrow Book\n5. Return Book\n6. View All Items\n7. View All Users\n8. Exit\nChoice: ";

        if (!(cin >> choice)) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;  
        }

        cin.ignore(); 

        try {
            if (choice == 1) {
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Book ID: "; getline(cin, id);
                lib.addBook(title, author, id);
            } else if (choice == 2) {
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Magazine ID: "; getline(cin, id);
                lib.addMagazine(title, author, id);
            } else if (choice == 3) {
                cout << "Enter User Name: "; getline(cin, userName);
                cout << "Enter User ID: "; getline(cin, userID);
                lib.addUser(userName, userID);
            } else if (choice == 4) {
                cout << "Enter User ID: "; getline(cin, userID);
                cout << "Enter Book ID: "; getline(cin, id);
                lib.borrowBook(userID, id);
            } else if (choice == 5) {
                cout << "Enter User ID: "; getline(cin, userID);
                cout << "Enter Book ID: "; getline(cin, id);
                lib.returnBook(userID, id);
            } else if (choice == 6) {
                lib.displayAllItems();
            } else if (choice == 7) {
                lib.displayAllUsers();
            }
        } catch (LibraryException& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 8);

    cout << "Goodbye!\n";
    return 0;
}


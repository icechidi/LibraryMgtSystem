#include <iostream>
#include <limits>
#include "LibrarySystem.h"
using namespace std;

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

    cout << "Thank you for Using our system!\n";
    return 0;
}

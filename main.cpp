#include <iostream>
#include <limits>
#include "LibrarySystem.h"
#include "LibraryItem.h"
#include "Book.h"
#include "User.h"
#include "Magazine.h"

int main() {
    LibrarySystem lib;
    int choice;
    std::string title, author, id, userName, userID;

    do {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Add Book\n2. Add Magazine\n3. Add User\n4. Borrow Book\n5. Return Book\n6. View All Items\n7. View All Users\n8. Exit\nChoice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            continue;  
        }

        std::cin.ignore();

        try {
            if (choice == 1) {
                std::cout << "Enter Title: "; std::getline(std::cin, title);
                std::cout << "Enter Author: "; std::getline(std::cin, author);
                std::cout << "Enter Book ID: "; std::getline(std::cin, id);
                lib.addBook(title, author, id);
            } else if (choice == 2) {
                std::cout << "Enter Title: "; std::getline(std::cin, title);
                std::cout << "Enter Author: "; std::getline(std::cin, author);
                std::cout << "Enter Magazine ID: "; std::getline(std::cin, id);
                lib.addMagazine(title, author, id);
            } else if (choice == 3) {
                std::cout << "Enter User Name: "; std::getline(std::cin, userName);
                std::cout << "Enter User ID: "; std::getline(std::cin, userID);
                lib.addUser(userName, userID);
            } else if (choice == 4) {
                std::cout << "Enter User ID: "; std::getline(std::cin, userID);
                std::cout << "Enter Book ID: "; std::getline(std::cin, id);
                lib.borrowBook(userID, id);
            } else if (choice == 5) {
                std::cout << "Enter User ID: "; std::getline(std::cin, userID);
                std::cout << "Enter Book ID: "; std::getline(std::cin, id);
                lib.returnBook(userID, id);
            } else if (choice == 6) {
                lib.displayAllItems();
            } else if (choice == 7) {
                lib.displayAllUsers();
            }
        } catch (LibraryException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } while (choice != 8);

    std::cout << "Goodbye!\n";
    return 0;
}
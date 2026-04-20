#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

int countBooks = 0;


void addBook(Book books[]) {
    cout << "Enter Book ID: ";
    cin >> books[countBooks].id;
    cout << "Enter Title: ";
    cin >> books[countBooks].title;
    cout << "Enter Author: ";
    cin >> books[countBooks].author;
    cout << "Enter Number of Copies: ";
    cin >> books[countBooks].copies;

    countBooks++;
    cout << "Book added successfully.\n";
}


void issueBook(Book books[]) {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].id == id) {
            if (books[i].copies > 0) {
                books[i].copies--;
                cout << "Book issued successfully.\n";
            } else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}


void returnBook(Book books[]) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].id == id) {
            books[i].copies++;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}


void displayBooks(Book books[]) {
    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << books[i].id
             << ", Title: " << books[i].title
             << ", Author: " << books[i].author
             << ", Copies: " << books[i].copies << endl;
    }
}

int main() {
    Book books[50];
    int choice;

    do {
        cout << "\nLibrary Menu\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(books); break;
            case 2: issueBook(books); break;
            case 3: returnBook(books); break;
            case 4: displayBooks(books); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}


//
// Created by intelory on 3/29/24.
//

#include <iostream>
#include <cstring>

using namespace std;
class LibraryMember;
class Library;

class Book {
    char title[30];
    char author[30];
    bool isAvailable;
    friend class Library;

    friend void checkOutBook(LibraryMember &m, Library &l, int &index);

public:
    Book(char *title="", char *auth="", bool available=true) {
        strcpy(this->title, title);
        strcpy(author , auth);
        isAvailable = available;
    }


    bool getisAvailable() {
        return isAvailable;
    }

    ~Book() {};
};

class Library {
    char name[30];
    Book books[5];
    int numberOfBooks;

    friend void checkOutBook(LibraryMember &m, Library &l, int &index);

public:
    Library() {
        strcpy(name, "City Library");
        numberOfBooks = 0;
    }

    void addBook(Book &book) {
        if (numberOfBooks < 5) {
            books[numberOfBooks++] = book;
        } else {
            cout << "Library is full! \n";
        }
    }

    Book getBook(int i) {
        return books[i];
    }

    int getNumberOfBooks() {
        return numberOfBooks;
    };

    void printInfo() {
        cout << "Library: " << name << "\n";
        for (int i=0;i<numberOfBooks;i++) {
            cout << books[i].title << " " << books[i].author << " " << books[i].isAvailable << "\n";
        }
    }


    ~Library() {}

};

class LibraryMember {
    char name[30];
    int id;
    friend void checkOutBook(LibraryMember &m, Library &l, int &index);

public:
    LibraryMember(char *n , int id) {
        strcpy(name , n);
        this->id=id;
    }

};

void checkOutBook(LibraryMember &m, Library &l ,int &index ) {
    //TODO: find the book by index in the library and change isAvailable field
    if (l.books[index].isAvailable) {
        cout << m.name << " ID: " << m.id << " checking out " << l.books[index].title << "\n";
        l.books[index].isAvailable = false;
    } else {
        cout << "Sorry " << l.books[index].title << " is not available" << endl;
    }
}

int main() {
    Library l1;
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    cout << "Enter book details (title author availability):" << endl;
    char title[100], author[100];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> title >> author >> availability;
        Book b = Book(title, author, availability);
        l1.addBook(b);
    }

    cout << "Library information:" << endl;
    l1.printInfo();

    cout << "Enter the index of the book to check out: ";
    int index;
    cin >> index;

    // Assuming LibraryMember and checkOutBook are properly defined
    LibraryMember m1("Marko", 9541);
    checkOutBook(m1, l1, index);

    return 0;
}



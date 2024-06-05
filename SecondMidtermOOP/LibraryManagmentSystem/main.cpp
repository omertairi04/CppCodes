#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ostream>

using namespace std;

class BookDoesNotExist {
public:
	BookDoesNotExist(){}

	void errorMessage(string bN) {
		cout << "Book with title: " << bN << " not found!" << endl;
	}
};

class Person {
protected:
	string name;
	string address;
	string phone_number;
	int age;
public:
	Person() = default;
	Person(const string &name, const string &address, const string &phone_number, const int age)
		: name(name),
		  address(address),
		  phone_number(phone_number),
		  age(age) {}

	string getName() const { return name; }
	string getAddress() const { return address; }
	string getPhoneNumber() const { return phone_number; }
	int getAge() const { return age; }

	virtual void print() {
		cout << "Name: " << name
		<< "\nAddress: " << address
		<< "\nPhone Number: " << phone_number
		<< "\nAge: " << age << endl;
	}

	// Postfix
	Person &operator++() {
		++age;
		return *this;
	}

	// Prefix
	Person &operator++(int) {
		Person temp = *this;
		++age;
		return temp;
	}
};

enum memberType {
	REGULAR,
	PREMIUM
};

enum staffType {
	INTERN,
	JUNIOR,
	MID_SENIOR,
	SENIOR
};

class Member : public Person {
	string memberId;
	memberType type;

public:
	Member() = default;
	Member(const string &name, const string &address, const string &phone_number,const int age, const string &member_id,
		const memberType type)
		: Person(name, address, phone_number, age),
		  memberId(member_id),
		  type(type) {
	}

	string getMemberId() const {
		return memberId;
	}

	void print() override {
		Person::print();
		cout << "ID: " << memberId << "\nType: "<< type << endl;
	};
};

class Staff : public Person {
	string staffId;
	staffType type;
public:
	Staff() = default;
	Staff(const string &name, const string &address, const string &phone_number, const int age, const string &staff_id,
		staffType type)
		: Person(name, address, phone_number, age),
		  staffId(staff_id),
		  type(type) {
	}
	void print() override {
		Person::print();
		cout << "ID: " << staffId << "\nType: "<< type << endl;
	};
};

class LibraryStaff {
	Staff *staffMembers;
	int numOfStaff;
public:
	LibraryStaff() = default;
	LibraryStaff(const int num,const Staff *staffs) {
		this->numOfStaff = num;
		this->staffMembers = new Staff[numOfStaff];
		for (int i=0;i<numOfStaff;i++) {
			staffMembers[i] = staffs[i];
		}
	}

};

class Book {
	string title;
	string author;
	string ISBN;
	bool isAvailable; // available or checked-out
public:
	Book() = default;

	Book(const string &title, const string &author, const string &isbn, bool is_available)
		: title(title),
		  author(author),
		  ISBN(isbn),
		  isAvailable(is_available) {
	}

	void print() {
		cout << title << " " << author
		<< " " << ISBN << " "
		<< isAvailable << endl;
	}

	string getTitle() {
		return title;
	}

	string getAuthor() const {
		return author;
	}

	string getIsbn() const {
		return ISBN;
	}

	bool getIsavailable() const {
		return isAvailable;
	}

	void setStatus(bool status) {
		isAvailable = status;
	}

	friend std::ostream & operator<<(std::ostream &os, const Book &obj) {
		return os
		       << "title: " << obj.title
		       << " author: " << obj.author
		       << " ISBN: " << obj.ISBN
		       << " isAvailable: " << obj.isAvailable;
	}
};

class BooksInLibrary {
	Book *books;
	Member *members;
	int numOfMembers;
	int numOfBooks;
public:
	BooksInLibrary() = default;

	BooksInLibrary(const int n, const Book *books, const int nM, const Member *m) {
		this->numOfBooks = n;
		this->books = new Book[numOfBooks];
		for (int i=0;i<numOfBooks;i++) {
			this->books[i] = books[i];
		}
		this->numOfMembers = nM;
		this->members = new Member[numOfMembers];
	}

	void rentBook(const string& title, const string& memberID) const {
		// check if book is in the library
		bool exists = false;
		for (int i=0;i<numOfBooks;i++) {
			if (books[i].getTitle() == title) {
				// we found the book, so change status
				books[i].setStatus(false);
				cout << books[i] << endl;
				break;
			}
		}

		if (!exists) {
			throw BookDoesNotExist();
		}
	}

	BooksInLibrary &operator+=(const Book &b) {
		Book *tmp = new Book[numOfBooks + 1];
		for (int i=0;i<numOfBooks;i++) {
			tmp[i] =  books[i];
 		}
		numOfBooks+=1;
		tmp[numOfBooks] = b;
		delete [] books;
		this->books = tmp;
		delete [] tmp;

		return *this;
	}

	BooksInLibrary &operator-=(Book &b) {
		int indexToRemove = -1;

		// Find the index of the book to be removed
		for (int i = 0; i < numOfBooks; ++i) {
			if (books[i].getTitle() == b.getTitle() &&
				books[i].getAuthor() == b.getAuthor() &&
				books[i].getIsbn() == b.getIsbn()) {
				indexToRemove = i;
				break;
				}
		}

		if (indexToRemove == -1) {
			throw BookDoesNotExist();
		}

		// Create a new array one element smaller
		Book *tmp = new Book[numOfBooks - 1];

		// Copy elements to the new array, skipping the one to be removed
		for (int i = 0, j = 0; i < numOfBooks; ++i) {
			if (i != indexToRemove) {
				tmp[j++] = books[i];
			}
		}

		// Update the number of books
		--numOfBooks;

		// Delete the old array
		delete[] books;

		// Point to the new array
		books = tmp;

		return *this;
	}

	void printAllBooks() const {
		for (int i=0;i<numOfBooks;i++) {
			cout << books[i] << endl;
		}
	}

	~BooksInLibrary() {
		delete [] books;
	}
};

int main() {

	int arrSize;

	cin >> arrSize;

	fstream fin ("/home/omer/CLionProjects/SecondMidtermOOP/LibraryManagmentSystem/input.txt");
	string line;

	// For person class
	string name , address, phoneNumber;
	int age;

	Person array[arrSize];

	for (int i=0;i<arrSize;i++) {
		getline(fin, name);
		getline(fin, address);
		getline(fin, phoneNumber);
		fin >> age;
		Person p(name, address, phoneNumber,age);
		array[i] = p;
		p.print();
	}
	cout << "------------\n";

	ofstream out("/home/omer/CLionProjects/SecondMidtermOOP/LibraryManagmentSystem/output.txt");

	for (int i = 0; i < arrSize; ++i) {
		out << array[i].getName() << " "
			<< array[i].getAge() << " "
			<< array[i].getAddress() << " "
			<< array[i].getPhoneNumber() << endl;
	}

	fin.close();
	out.close();
}

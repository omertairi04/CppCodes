//
// Created by omer on 2.6.24.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;

class Book {
	string title;
	string author;
	int year;

public:
	Book(const string &title="", const string &author="", int year=0)
		: title(title),
		  author(author),
		  year(year) {
	}
	bool operator==(const Book &rhs) {
		return this->title == rhs.title
			   && this->author == rhs.author
			   && this->year == rhs.year;
	}

	bool operator!=(const Book &rhs) {
		return !(*this == rhs);
	}

	friend std::ostream & operator<<(std::ostream &os, const Book &obj) {
		return os
		       << "title: " << obj.title
		       << " author: " << obj.author
		       << " year: " << obj.year;
	}

	string getAuthor() {
		return this->author;
	}
};

class BookAlreadyExistsException {
	Book b;
public:
	explicit BookAlreadyExistsException(const Book &b)
		: b(b) {
	}

	void message() {
		cout << "Book \"" << b << "\" already exists in the library" << endl;
	}
};

class Library {
	string name;
	int numOfBooks;
	Book *books;

public:
	Library(const string &name = "") {
		this->name = name;
		numOfBooks = 0;
		books = new Book[numOfBooks];
	}


	Library &operator+=(const Book &b) {
		for (int i=0;i<numOfBooks;i++) {
			if (books[i] == b) {
				throw BookAlreadyExistsException(b);
			}
		}

		Book *tmp = new Book[numOfBooks + 1];
		for (int i=0;i<numOfBooks;i++) {
			tmp[i] = books[i];
		}

		delete [] books;
		tmp[numOfBooks] = b;
		numOfBooks++;
		books = tmp;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &out, Library &lib) {
		out << lib.name << endl;
		for (int i=0;i<lib.numOfBooks;i++) {
			out << lib.books[i] << endl;
		}
		return out;
	}

	Book* getBooksByAuthor(const std::string& author, int& numberFound) {
		numberFound = 0;

		// First pass to count the number of books by the author
		for (int i = 0; i < numOfBooks; i++) {
			if (books[i].getAuthor() == author) {
				numberFound++;
			}
		}

		if (numberFound == 0) {
			return nullptr;
		}

		// Allocate exact number of elements
		Book* result = new Book[numberFound];
		int j = 0;

		// Second pass to populate the result array
		for (int i = 0; i < numOfBooks; i++) {
			if (books[i].getAuthor() == author) {
				result[j] = books[i];
				j++;
			}
		}

		return result;
	}


	~Library() {
	}
};

void wtf() {
	ofstream fout("input.txt");

	string fname, lname;
	int points;
	string line;

	while (getline(std::cin, line)) {
		if (line == "----") {
			break;
		}
		fout << line << endl;
	}
}

void rff1() {
	ifstream fin("output1.txt");
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}

void rff2() {
	ifstream fin("output2.txt");
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}

int main() {


	wtf();


	//YOUR CODE STARTS HERE

	ifstream in("input.txt");

	string libraryName;
	getline(in, libraryName);

	int n;
	in >> n;

	in.ignore();

	Library library(libraryName);

	string title, auth;
	int year;
	for (int i = 0; i < n; i++) {
		getline(in, title);
		getline(in, auth);
		in >> year;
		in.ignore();

		//        cout << title << " " << auth << " " << year << endl;
		Book b(title, auth, year);
		try {
			library += b;
		} catch (BookAlreadyExistsException &e) {
			e.message();
		}
	}

	in.close();

	ofstream out("output1.txt");
	out << library;
	out.close();

	//DO NOT MODIFY THE NEXT PART

	string author;
	getline(std::cin, author);

	//DO NOT MODIFY THE PART ABOVE, CONTINUE AFTER THIS COMMENT

	out = ofstream("output2.txt");
	int num;
	Book * result = library.getBooksByAuthor(author, num);

	if (num==0){
		out << "None" << endl;
	} else {
		for (int i=0;i<num;i++){
			out << result[i] << endl;
		}
	}

	out.close();


	//YOUR CODE ENDS HERE
	rff1();
	cout << "Books written by " << author << " are: " << endl;
	rff2();

	return 0;
}
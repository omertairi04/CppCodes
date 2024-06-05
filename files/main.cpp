#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class User {
	string name;
	int age;
	string faculty;
public:
	User() = default;
	User(const string &name, int age, const string &faculty)
		: name(name),
		  age(age),
		  faculty(faculty) {
	}

	string name1() const {
		return name;
	}

	int age1() const {
		return age;
	}

	string faculty1() const {
		return faculty;
	}

	void print() {
		cout << name <<" " << age << " " << faculty << endl;
	}
};

int main() {

	// fstream myFile;
	ifstream in("omer.txt");

	string name, faculty;
	int age;

	vector<User> users;

	// Read each user's data from the file
	for (int i = 0; i < 3; i++) {
		getline(in, name);  // Read the name
		in >> age;          // Read the age
		in.ignore();        // Consume the newline character
		getline(in, faculty); // Read the faculty
		User u(name, age, faculty);
		users.push_back(u);
		u.print();
	}
	cout << "------------\n";
	ofstream out("/home/omer/CLionProjects/files/output.txt");

	for (int i = 0; i < users.size(); i++) {
		if (users[i].age1() > 18)
			out << users[i].name1() << " " << users[i].age1() << " " << users[i].faculty1() << endl;

	}


	in.close();

	/*
	// write to a .txt file
	myFile.open("omer.txt", ios::out);
	if (myFile.is_open()) {
		myFile << "Hello\n";
		myFile << "This is the second line\n";
		myFile.close();
	}

	// append
	myFile.open("omer.txt", ios::app);
	if (myFile.is_open()) {
		myFile << "Hello2\n";
		myFile.close();
	}
	*/

	// Reading file
	// myFile.open("omer.txt", ios::in);
	// if (myFile.is_open()) {
	// 	string line;
	// 	while(getline(myFile, line)) { // for each line
	// 		cout << line << endl;
	// 	}
	// 	myFile.close();
	// }

	return 0;
}

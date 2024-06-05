#include <iostream>
#include <string>

using namespace std;

class InvalidProfessorAllocationException {
public:
	InvalidProfessorAllocationException(const string& msg) : message(msg) {}
	void print() {
		cout << message << endl;
	}
private:
	string message;
};

class InvalidAssistantAllocationException {
public:
	InvalidAssistantAllocationException(const string& msg) : message(msg) {}
	void print() {
		cout << message << endl;
	}
private:
	string message;
};

class Teacher {
protected:
	long int id;
	string fullName;
public:
	Teacher(long int id, const string &full_name)
		: id(id),
		  fullName(full_name) {
	}

	virtual float calculateClassAllocations() {
		return 0.0;
	};

	virtual void print() {
		cout << fullName << " " << id << endl;
	};
};

class ClassAllocation {
protected:
	float numberOfLectures;
	float numberOfExercises;

public:
	ClassAllocation(float number_of_lectures, float number_of_exercises)
		: numberOfExercises(number_of_exercises), numberOfLectures(number_of_lectures){
	}

	virtual void print() {
		cout << "Lectures: " << numberOfLectures << "; Exercises: " << numberOfExercises << endl;
	}
};

class Professor: public Teacher, public ClassAllocation {
public:
	Professor(long int id, const string &full_name, float number_of_lectures, float number_of_exercises)
		: Teacher(id, full_name),
		  ClassAllocation(number_of_lectures, number_of_exercises) {
		if (number_of_lectures <= 0) {
			throw InvalidProfessorAllocationException("Professor doesn't have lectures.");
		}
	}

	float calculateClassAllocations() override {
		return numberOfLectures * 2;
	};

	void print() override {
		cout << "Professor:" << endl;
		Teacher::print();
		ClassAllocation::print();
	}
};

class Assistant: public Teacher, public ClassAllocation {
public:
	Assistant(long int id, const string &full_name, float number_of_lectures, float number_of_exercises)
		: Teacher(id, full_name),
		  ClassAllocation(number_of_lectures, number_of_exercises) {
		if (number_of_exercises <= 0) {
			throw InvalidAssistantAllocationException("Assistant doesn't have exercises.");
		}
		if (number_of_lectures > 0) {
			throw InvalidAssistantAllocationException("Assistant shouldn't have lectures.");
		}
	}

	void print() override {
		cout << "Assistant:"<<endl;
		Teacher::print();
		ClassAllocation::print();
	};

	float calculateClassAllocations() override {
		return numberOfExercises * 2;
	};
};

Teacher * mostAllocatedTeacher(Teacher** teachers, int n) {
	int index = 0;
	float maxVal = teachers[index]->calculateClassAllocations();

	for (int i=0;i<n;i++) {
		if (teachers[i]->calculateClassAllocations() > maxVal) {
			index = i;
			maxVal = teachers[i]->calculateClassAllocations();
		}
	}

	return teachers[index];

}

int main() {
	int numberOfProfessors;
	cin >> numberOfProfessors;
	Teacher** teachers = new Teacher*[50];

	long id;
	string fullName;
	float numberOfLectures, numberOfExercises;

	// Notice the way the exception is handled and how the variables in the for loop are adjusted
	for (int i = 0; i < numberOfProfessors; ++i) {
		cin >> id;
		cin.ignore();
		getline(cin, fullName);
		cin >> numberOfLectures >> numberOfExercises;

		try {
			teachers[i] = new Professor(id, fullName, numberOfLectures, numberOfExercises);
		}
		catch (InvalidProfessorAllocationException& exception) {
			// Variables are decreased by 1 whenever an object has not been allocated correctly
			--i;
			--numberOfProfessors;
			exception.print();
		}
	}

	int numberOfAssistants;
	cin >> numberOfAssistants;

	// TODO: Handle exceptions
	for (int i = numberOfProfessors; i < numberOfProfessors + numberOfAssistants; ++i) {
		cin >> id;
		cin.ignore();
		getline(cin, fullName);
		cin >> numberOfLectures >> numberOfExercises;
		try {
			teachers[i] = new Assistant(id, fullName, numberOfLectures, numberOfExercises);
		} catch(InvalidAssistantAllocationException & exception) {
			--i;
			--numberOfAssistants;
			exception.print();
		}
	}

	mostAllocatedTeacher(teachers, numberOfProfessors + numberOfAssistants)->print();

	for (int i = 0; i < numberOfProfessors + numberOfAssistants; ++i) {
		delete teachers[i];
	}
	delete[] teachers;

	return 0;
}

//
// Created by intelory on 3/29/24.
//
#include <iostream>
#include <cstring>

using namespace std;

class Student {
    char name[20];
    char id[10];
    float GPA;
    static int totalStudents;
    static float totalGPA;

public:
    Student() {}

    Student(char *n , char *id , float GPA) {
        strcpy(name , n);
        strcpy(this->id,id);
        this->GPA = GPA;
        totalStudents++;
        totalGPA += GPA;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static float getAverageGPA() {
        return totalGPA / totalStudents;
    }

    void print() {
        cout << id << " " << name << " " << GPA << "\n";
    }
};

int Student::totalStudents = 0;
float Student::totalGPA = 0.0;



int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    char name[30], id[10];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> gpa;
        students[i] = Student(name, id, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    cout << "Total students: " << Student::getTotalStudents() << endl;
    cout << "Total average: " << Student::getAverageGPA() << endl;
    return 0;
}


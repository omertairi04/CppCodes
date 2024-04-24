#include <iostream>
#include <cstring>
#include <cmath>

class Employee {
    char name[100];
    char surname[100];
    int salary;

public:
    Employee() {}

    Employee(char *n , char *s , int s1) {
        strcpy(name , n);
        strcpy(surname , s);
        salary = s1;
    }

    Employee(Employee &e) {
        strcpy(name , e.name);
        strcpy(surname , e.surname);
        salary = e.salary;
    }

    void print() {
        std::cout << "Employee name: " << name << std::endl;
        std::cout << "Employee surname: " << surname << std::endl;
        std::cout << "Employee salary: " << salary << std::endl;
    }

    int getSalary () {
        return salary;
    }

};

class TechCompany {
    char name[100];
    Employee employees[20];
    int numOfEmployees;

public:
    TechCompany() {}

    TechCompany(char *c ) {
        strcpy(name , c);
    }

    void print() {
        std::cout << "Tech company name: " << name << std::endl;
        std::cout << "Number of employees: " << numOfEmployees << std::endl;
    }

    double getAverageOfEmployeeSalary() {
        double salary = employees[0].getSalary();
        int count=0;
        for (int i=0; i<numOfEmployees;i++) {
            salary += employees[i].getSalary();
            count++;
        }

        return salary / count;
    }

    int getNumOfEmployees() {
        return numOfEmployees;
    }

    char *getName() {
        return name;
    }

    double getStdDevOfEmployeeSalary() {
        if(numOfEmployees == 0) {
            return 0.0;
        }

        double avg = getAverageOfEmployeeSalary();
        double variance = 0.0;

        for (int i = 0; i < numOfEmployees; ++i) {
            double diff = employees[i].getSalary() - avg;
            variance += diff * diff;
        }

        variance /= numOfEmployees - 1;
        return sqrt(variance);
    }

    ~TechCompany() {}
};

TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies) {
    double highestAvgSal = -1;
    int indexOfHigh = 0;
    for (int i=0;i<numCompanies;i++) {
        if (companies[i].getAverageOfEmployeeSalary() > highestAvgSal) {
            highestAvgSal =companies[i].getAverageOfEmployeeSalary();
            indexOfHigh = i;
        }
    }

    return companies[indexOfHigh];
}

TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies) {
    if (numCompanies == 0) {
        std::cout << "No companies provided!" << std::endl;
        return TechCompany();
    }

    TechCompany maxCompany = companies[0];
    double maxStdDev = companies[0].getStdDevOfEmployeeSalary();

    for (int i = 1; i < numCompanies; ++i) {
        double stdDev = companies[i].getStdDevOfEmployeeSalary();
        if (stdDev > maxStdDev) {
            maxStdDev = stdDev;
            maxCompany = companies[i];
        }
    }

    return maxCompany;
}
bool isSameCompany(TechCompany company1, TechCompany company2) {
    if (company1.getName() == company2.getName()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout<<"-->Testing get and set methods for one object and copy constructor"<<std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout<<"-->Testing addEmployee function"<<std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout<<"-->Testing copy of first employee"<<std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout<<"-->Testing methods"<<std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " <<t1.getName() << std::endl;

    if (isSameCompany(t, t1)){
        std::cout<<"The tech company: "<<t.getName()<<" has the highest standard deviation and highest average salary"<<std::endl;
    }
    return 0;
}

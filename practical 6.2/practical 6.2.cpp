#include <iostream>
#include <vector>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person constructor called\n";
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Intermediate Class
class Employee : public Person {
protected:
    int empID;

public:
    // Constructor chaining
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
        cout << "Employee constructor called\n";
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }

    int getID() {
        return empID;
    }
};

// Top Level Class
class Manager : public Employee {
private:
    string department;

public:
    // Constructor chaining
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id) {
        department = dept;
        cout << "Manager constructor called\n";
    }

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "--------------------------\n";
    }
};

// ----------- MAIN FUNCTION -----------
int main() {

    // -------- Method 1: Static Storage --------
    cout << "\n--- Static Storage Method ---\n";

    Manager managers[2] = {
        Manager("Angel", 21, 101, "HR"),
        Manager("Riya", 30, 102, "Finance")
    };

    for (int i = 0; i < 2; i++) {
        managers[i].displayManager();
    }

    // -------- Method 2: Retrieval-Based (Vector + Search) --------
    cout << "\n--- Retrieval-Based Method ---\n";

    vector<Manager> mgrList;

    mgrList.push_back(Manager("Amit", 35, 201, "IT"));
    mgrList.push_back(Manager("Neha", 40, 202, "Marketing"));

    int searchID;
    cout << "Enter Employee ID to search: ";
    cin >> searchID;

    bool found = false;

    for (auto &m : mgrList) {
        if (m.getID() == searchID) {
            cout << "\nManager Found:\n";
            m.displayManager();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Manager not found.\n";
    }

    return 0;
}

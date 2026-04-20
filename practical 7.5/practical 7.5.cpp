#include <iostream>
#include <vector>
using namespace std;

// -------- Abstract Base Class --------
class GradingSystem {
protected:
    string name;
    int marks;

public:
    GradingSystem(string n, int m) {
        name = n;
        marks = m;
    }

    // Pure virtual function
    virtual void computeGrade() = 0;

    // Display basic info
    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    // Virtual destructor
    virtual ~GradingSystem() {}
};

// -------- Undergraduate Class --------
class Undergraduate : public GradingSystem {
public:
    Undergraduate(string n, int m) : GradingSystem(n, m) {}

    void computeGrade() {
        display();
        if (marks >= 75)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else if (marks >= 50)
            cout << "Grade: C\n";
        else
            cout << "Grade: Fail\n";
        cout << "----------------------\n";
    }
};

// -------- Postgraduate Class --------
class Postgraduate : public GradingSystem {
public:
    Postgraduate(string n, int m) : GradingSystem(n, m) {}

    void computeGrade() {
        display();
        if (marks >= 85)
            cout << "Grade: A+\n";
        else if (marks >= 70)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else
            cout << "Grade: Fail\n";
        cout << "----------------------\n";
    }
};

// -------- MAIN FUNCTION --------
int main() {

    // -------- Method 1: Dynamic Storage --------
    cout << "=== Dynamic Storage (Vector) ===\n";

    vector<GradingSystem*> students;

    students.push_back(new Undergraduate("Angel", 72));
    students.push_back(new Postgraduate("Riya", 78));

    for (int i = 0; i < students.size(); i++) {
        students[i]->computeGrade(); // polymorphism
    }

    // Free memory
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }

    // -------- Method 2: Static Storage --------
    cout << "\n=== Static Storage (Array) ===\n";

    GradingSystem* arr[2];
    arr[0] = new Undergraduate("Amit", 65);
    arr[1] = new Postgraduate("Neha", 88);

    for (int i = 0; i < 2; i++) {
        arr[i]->computeGrade(); // polymorphism
        delete arr[i];
    }

    return 0;
}

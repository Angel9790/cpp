#include <iostream>
using namespace std;

class Employee
{
    string name;
    float basic, bonus;

public:

    Employee(string n = "", float b = 0, float bo = 2000)
    {
        name = n;
        basic = b;
        bonus = bo;
    }


    inline float totalSalary()
    {
        return basic + bonus;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << totalSalary() << endl;
        cout << "-------------------" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee e[10];

    string name;
    float basic, bonus;
    int choice;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter name: ";
        cin >> name;

        cout << "Enter basic salary: ";
        cin >> basic;

        cout << "enter 1 for Default Bonus enter 2 for Custom Bonus: ";
        cin >> choice;

        if(choice == 1)
        {
            e[i] = Employee(name, basic);
        }
        else
        {
            cout << "Enter bonus: ";
            cin >> bonus;
            e[i] = Employee(name, basic, bonus);
        }
    }

    cout << "\nEmployee Details\n";

    for(int i = 0; i < n; i++)
    {
        e[i].display();
    }
    cout<<"This Program is made by Angel Bavarva 25CE006";
    return 0;
}

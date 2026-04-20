#include <iostream>
#include <fstream>
using namespace std;


ostream& currency(ostream& out)
{
    out << "Rs ";
    return out;
}

int main()
{
    ofstream fout("students.txt");
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    string name;
    float marks, fees;


    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Fees: ";
        cin >> fees;

        fout << name << " " << marks << " " << fees << endl;
    }

    fout.close();


    ifstream fin("students.txt");

    cout << "\n\n--- Student Details ---" << endl;
    cout << "Name\tMarks\tFees" << endl;
    cout << "--------------------------" << endl;


    while(fin >> name >> marks >> fees)
    {
        cout << name << "\t"
             << marks << "\t"
             << currency << fees
             << endl;
    }

    fin.close();
    cout<<"This Program is made by Angel Bavarva ";
    return 0;
}

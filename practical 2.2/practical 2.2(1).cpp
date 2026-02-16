#include<iostream>
#include<string.h>
using namespace std;

class student
{
    private:
        string name;
        int roll_no;
        float m1,m2,m3,avg;

    public:
        void putdata()
        {
            cout<<"\nStudent Name : "<<name;
            cout<<"\nRoll no : "<<roll_no;
            cout<<"\nMarks of subject 1 : "<<m1;
            cout<<"\nMarks of subject 2 : "<<m2;
            cout<<"\nMarks of subject 3 : "<<m3;
            cout<<"\nAverage : "<<average();
        }
        student()
        {
            cout<<"student details";
            name="Angel";
            roll_no = 6;
            m1 = 50;
            m2 = 60;
            m3 = 80;

        }
        float average()
        {
            avg = (m1 + m2 + m3)/3.0;
            return avg;
        }

};
int main()
{
    student s1;
    s1.putdata();
    return 0;
}


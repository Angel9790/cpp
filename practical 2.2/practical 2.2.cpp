#include<iostream>
#include<string.h>
using namespace std;

class student
{
private :
    int roll_no;
    char name[50];
    float marks[3];
    int i;
    float total=0,avg;

public :
    student()
    {
        int roll_no=0;
        string name="";
        float marks=0;
    }

    void getdata()
    {
        cout<<"\nEnter student roll no. ";
        cin>>roll_no;
        cout<<"Enter student name :";
        cin>>name;
        for(i=0;i<3;i++)
        {
            cout<<"Enter marks of subject "<<i+1<<" : ";
            cin>>marks[i];
        }
    }

    float average()
    {
        for(i=0;i<3;i++)
        {
            total += marks[i];
        }
        avg=total/3.0;
        return avg;
    }

    void putdata()
    {
        average();
        cout<<"\nRoll no. :"<<roll_no;
        cout<<"\nname : "<<name;

        for(i=0;i<3;i++)
        {
            cout<<"\nMarks of subject "<<i+1<<" : "<<marks[i];
        }
        cout<<"\nAverage : "<<avg;
    }
};

int main()
{
    student s[50];
    int n,i;
    float avg;

    cout<<"Enter the number of students :";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n------------------------------";
        cout<<"\nresult details for student "<<i+1<<endl;
        cout<<"------------------------------\n";
        s[i].getdata();
        s[i].putdata();
    }
    return 0;
}

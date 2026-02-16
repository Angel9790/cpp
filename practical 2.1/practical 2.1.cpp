#include<iostream>
using namespace std;

class rectangle
{
private:
    float length;
    float breadth;
    float parameter;
    float area;
    int n,i;
public:
    void getdata()
    {
        cout<<"Enter length of rectangle:";
        cin>>length;
        cout<<"Enter breadth of rectangle:";
        cin>>breadth;
    }
    void calculateparameter()
    {
        parameter=2*(length+breadth);
    }
    void calculateArea()
    {
        area=(length*breadth);
    }
    void putData()
    {
        calculateparameter();
        calculateArea();
        cout<<"length : "<<length<<endl;
        cout<<"breadth : "<<breadth<<endl;
        cout<<"parameter : "<<parameter<<endl;
        cout<<"Area : "<<area<<endl;
    }
};
int main()
    {
        rectangle r[5];
        int i,n;
        cout<<"Enter the number : ";
        cin>>n;
        for(i=0;i<n;i++)
        {
            cout<<"Enter length and breadth for rectangle "<<i+1<<":"<<endl;
            r[i].getdata();
            r[i].putData();
        }
        return 0;
    }

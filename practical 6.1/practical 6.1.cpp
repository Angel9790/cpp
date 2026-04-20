#include <iostream>
using namespace std;


class Shape
{
protected:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    float area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int n;

    cout << "Enter number of circles: ";
    cin >> n;


    Circle c[50];

    cout << "\nEnter radius for circles (Static Array):\n";
    for(int i = 0; i < n; i++)
    {
        float r;
        cout << "Circle " << i+1 << ": ";
        cin >> r;
        c[i].setRadius(r);
    }

    cout << "\nAreas (Static Array):\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Circle " << i+1 << " Area = " << c[i].area() << endl;
    }


    Circle *d = new Circle[n];

    cout << "\nEnter radius for circles (Dynamic Array):\n";
    for(int i = 0; i < n; i++)
    {
        float r;
        cout << "Circle " << i+1 << ": ";
        cin >> r;
        d[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic Array):\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Circle " << i+1 << " Area = " << d[i].area() << endl;
    }

    delete[] d;

    return 0;
}

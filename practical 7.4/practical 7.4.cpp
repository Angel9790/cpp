#include <iostream>
#include <vector>
using namespace std;

// -------- Base Class --------
class Shape {
public:
    virtual void area() = 0; // pure virtual function

    // Virtual destructor
    virtual ~Shape() {}
};

// -------- Rectangle Class --------
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    void area() {
        cout << "Rectangle Area: " << length * width << endl;
    }
};

// -------- Circle Class --------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    void area() {
        cout << "Circle Area: " << 3.14 * radius * radius << endl;
    }
};

// -------- MAIN FUNCTION --------
int main() {

    // -------- Method 1: Dynamic Storage --------
    cout << "=== Dynamic Storage (Vector) ===\n";

    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(2.5));

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->area(); // polymorphism
    }

    // Free memory
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    // -------- Method 2: Static Storage --------
    cout << "\n=== Static Storage (Array) ===\n";

    Shape* arr[2];
    arr[0] = new Rectangle(4, 6);
    arr[1] = new Circle(3);

    for (int i = 0; i < 2; i++) {
        arr[i]->area(); // polymorphism
        delete arr[i];
    }

    return 0;
}

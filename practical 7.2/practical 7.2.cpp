#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // -------- Operator Overloading --------

    // + operator
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // - operator
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Display function
    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

// -------- MAIN FUNCTION --------
int main() {

    Complex c1(3, 4), c2(1, 2);

    // Operations
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    // -------- Optional: Collection --------
    vector<Complex> results;
    results.push_back(sum);
    results.push_back(diff);

    cout << "\nStored Results:\n";
    for (int i = 0; i < results.size(); i++) {
        cout << "Result " << i + 1 << ": ";
        results[i].display();
    }

    return 0;
}

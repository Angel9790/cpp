#include <iostream>
#include <queue>
using namespace std;

// Forward declaration
class Fahrenheit;

// -------- Celsius Class --------
class Celsius {
private:
    double temp;

public:
    Celsius(double t = 0) {
        temp = t;
    }

    double getTemp() const {
        return temp;
    }

    // Conversion: Celsius → Fahrenheit
    operator Fahrenheit();

    void display() const {
        cout << temp << " celsius";
    }
};

// -------- Fahrenheit Class --------
class Fahrenheit {
private:
    double temp;

public:
    Fahrenheit(double t = 0) {
        temp = t;
    }

    double getTemp() const {
        return temp;
    }

    // Conversion: Fahrenheit → Celsius
    operator Celsius() {
        double c = (temp - 32) * 5 / 9;
        return Celsius(c);
    }

    void display() const {
        cout << temp << " farenheit";
    }
};

// -------- Define Celsius → Fahrenheit --------
Celsius::operator Fahrenheit() {
    double f = (temp * 9 / 5) + 32;
    return Fahrenheit(f);
}

// -------- Equality Operator --------
bool operator==(Celsius c, Fahrenheit f) {
    Fahrenheit tempF = c; // convert Celsius → Fahrenheit
    return tempF.getTemp() == f.getTemp();
}

// -------- MAIN FUNCTION --------
int main() {

    // -------- Conversion Demo --------
    Celsius c1(25);
    Fahrenheit f1 = c1;   // C → F

    cout << "Celsius: ";
    c1.display();

    cout << "\nConverted to Fahrenheit: ";
    f1.display();

    // Reverse conversion
    Fahrenheit f2(77);
    Celsius c2 = f2;      // F → C

    cout << "\nFahrenheit: ";
    f2.display();

    cout << "\nConverted to Celsius: ";
    c2.display();

    // -------- Comparison --------
    cout << "\n\nChecking Equality:\n";
    if (c1 == f2)
        cout << "Temperatures are Equal\n";
    else
        cout << "Temperatures are NOT Equal\n";

    // -------- Method 1: Queue (FIFO) --------
    cout << "\n--- Queue Method ---\n";

    queue<Fahrenheit> q;
    q.push(Celsius(0));
    q.push(Celsius(100));

    while (!q.empty()) {
        q.front().display();
        cout << endl;
        q.pop();
    }

    // -------- Method 2: Static Array --------
    cout << "\n--- Static Array Method ---\n";

    Celsius arr[2] = {Celsius(10), Celsius(30)};

    for (int i = 0; i < 2; i++) {
        Fahrenheit f = arr[i];
        arr[i].display();
        cout << " = ";
        f.display();
        cout << endl;
    }

    return 0;
}

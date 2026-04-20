#include <iostream>
#include <cmath>
using namespace std;

// Custom Exception Class
class NegativeNumberException {
public:
    void message() {
        cout << "Error! Negative number entered. Cannot find square root." << endl;
    }
};

int main() {
    float num;

    cout << "Enter a number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw NegativeNumberException();
        }

        cout << "Square root = " << sqrt(num) << endl;
    }

    catch (NegativeNumberException e) {
        e.message();
    }

    return 0;
}

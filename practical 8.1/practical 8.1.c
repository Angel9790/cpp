#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator: ";
        if (!(cin >> a))   // check invalid input
            throw "Invalid input! Please enter integers only.";

        cout << "Enter denominator: ";
        if (!(cin >> b))   // check invalid input
            throw "Invalid input! Please enter integers only.";

        if (b == 0)        // check division by zero
            throw "Error! Division by zero is not allowed.";

        // Division done immediately
        cout << "Result = " << a / b << endl;
    }

    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}

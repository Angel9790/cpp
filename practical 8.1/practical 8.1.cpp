#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator: ";
        if (!(cin >> a))
            throw "Invalid input! Please enter integers only.";

        cout << "Enter denominator: ";
        if (!(cin >> b))
            throw "Invalid input! Please enter integers only.";

        if (b == 0)
            throw "Error! Division by zero is not allowed.";


        cout << "Result = " << a / b << endl;
    }

    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}

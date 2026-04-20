#include <iostream>
#include <vector>
using namespace std;

class Calculator {
private:
    vector<double> results; // store results

public:
    // -------- Overloaded add() functions --------

    int add(int a, int b) {
        int res = a + b;
        results.push_back(res);
        return res;
    }

    double add(double a, double b) {
        double res = a + b;
        results.push_back(res);
        return res;
    }

    double add(int a, double b) {
        double res = a + b;
        results.push_back(res);
        return res;
    }

    double add(double a, int b) {
        double res = a + b;
        results.push_back(res);
        return res;
    }

    // -------- Display Results --------
    void displayResults() {
        cout << "\nStored Results:\n";
        for (int i = 0; i < results.size(); i++) {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

// -------- MAIN FUNCTION --------
int main() {
    Calculator calc;

    // Test cases
    cout << "Int + Int: " << calc.add(5, 3) << endl;
    cout << "Double + Double: " << calc.add(2.5, 3.5) << endl;
    cout << "Int + Double: " << calc.add(4, 2.7) << endl;
    cout << "Double + Int: " << calc.add(6.8, 2) << endl;

    // Display all stored results
    calc.displayResults();

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;


    while (true) {
        cout << "Enter file name (or type exit to quit): ";
        cin >> filename;

        if (filename == "exit") {
            cout << "Program ended.\n";
            return 0;
        }

        file.open(filename);

        if (!file) {
            cout << "Error! File cannot be opened. Try again.\n";
        } else {
            break;
        }
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        stringstream ss(line);
        double num, sum = 0;
        int count = 0;
        bool isValid = true;

        try {
            while (ss >> num) {
                sum += num;
                count++;
            }


            if (!ss.eof()) {
                throw "Corrupted data found!";
            }

            if (count > 0) {
                cout << "Line " << lineNumber
                     << " -> Sum: " << sum
                     << ", Average: " << sum / count << endl;
            }
        }

        catch (const char* msg) {
            cout << "Line " << lineNumber << " skipped: " << msg << endl;
        }
    }

    file.close();
    return 0;
}

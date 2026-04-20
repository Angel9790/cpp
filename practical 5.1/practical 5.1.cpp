#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void toLowerCase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string paragraph, line;


    while (getline(file, line)) {
        paragraph += line + " ";
    }
    file.close();

    string words[100];
    int freq[100] = {0};
    int count = 0;

    string temp = "";

    for (int i = 0; i <= paragraph.length(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\0') {
            if (temp != "") {
                toLowerCase(temp);

                int found = -1;
                for (int j = 0; j < count; j++) {
                    if (words[j] == temp) {
                        found = j;
                        break;
                    }
                }

                if (found != -1) {
                    freq[found]++;
                } else {
                    words[count] = temp;
                    freq[count] = 1;
                    count++;
                }
                temp = "";
            }
        } else {
            temp += paragraph[i];
        }
    }


    ofstream outFile("output.txt");

    if (!outFile) {
        cout << "Error creating output file!" << endl;
        return 1;
    }

    outFile << "Word Frequencies:\n";
    for (int i = 0; i < count; i++) {
        outFile << words[i] << " : " << freq[i] << endl;
    }

    outFile.close();

    cout << "Word frequencies written to output.txt" << endl;

    return 0;
}

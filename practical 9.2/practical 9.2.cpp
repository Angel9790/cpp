#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string sentence, word;
    map<string, int> freq;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);

    while (ss >> word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        freq[word]++;
    }

    for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}


#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canCreateNote(
    const string& note,
    const vector<string>& articles
);

string readFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open " << filename << endl;
        return "";
    }

    string text;
    string line;

    while (getline(file, line)) {
        text += line;
        text += '\n';
    }

    return text;
}

int main() {
    string othello = readFile("othello.txt");
    string romeoAndJuliet = readFile("romeo_and_juliet.txt");

    if (othello.empty() || romeoAndJuliet.empty()) {
        cerr << "Check that both text files exist and contain text."
             << endl;
        return 1;
    }

    vector<string> articles = {othello};

    bool result = canCreateNote(romeoAndJuliet, articles);

    if (result) {
        cout << "Romeo and Juliet can be constructed from Othello."
             << endl;
    } else {
        cout << "Romeo and Juliet cannot be constructed from Othello."
             << endl;
    }

    return 0;
}

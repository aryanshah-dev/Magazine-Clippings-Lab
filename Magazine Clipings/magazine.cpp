
#include "CharacterHashMap.h"

#include <cctype>
#include <string>
#include <vector>

using namespace std;

string prepareText(const string& text) {
    string result;

    for (unsigned char ch : text) {
        if (!isspace(ch)) {
            result += static_cast<char>(tolower(ch));
        }
    }

    return result;
}

bool canCreateNote(
    const string& note,
    const vector<string>& articles
) {
    CharacterHashMap available;

    for (const string& article : articles) {
        string prepared = prepareText(article);

        for (char ch : prepared) {
            available.increment(ch);
        }
    }

    string preparedNote = prepareText(note);

    for (char ch : preparedNote) {
        if (!available.use(ch)) {
            return false;
        }
    }

    return true;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Store all valid encoded strings
vector<string> results;

void findEncodings(string s, int index, string current) {
    // Base case: if we've reached the end of the string, save the result
    if (index == s.length()) {
        results.push_back(current);
        return;
    }

    // Option 1: Take a single digit
    int num1 = s[index] - '0';
    char letter1 = 'a' + num1 - 1;
    findEncodings(s, index + 1, current + letter1);

    // Option 2: Take two digits (if available and valid <= 26)
    if (index + 1 < s.length()) {
        int num2 = stoi(s.substr(index, 2));
        if (num2 <= 26) {
            char letter2 = 'a' + num2 - 1;
            findEncodings(s, index + 2, current + letter2);
        }
    }
}

int main() {
    string s;
    if (!(cin >> s)) return 0;

    findEncodings(s, 0, "");

    // Output the total count
    cout << results.size() << endl;

    // Output each encoding
    for (const string& encoding : results) {
        cout << encoding << endl;
    }

    return 0;
}

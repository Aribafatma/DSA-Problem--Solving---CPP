#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O for large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    // Frequency array for 26 lowercase English letters
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Print characters in alphabetical order based on their counts
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}

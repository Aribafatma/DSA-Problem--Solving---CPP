#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        string result = "";

        for (char c : s) {
            // If the current character matches the last added character, remove it
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                // Otherwise, add the character to the result
                result.push_back(c);
            }
        }

        cout << result << "\n";
    }

    return 0;
}

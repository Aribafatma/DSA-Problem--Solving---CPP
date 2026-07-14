#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            // 1. Print leading spaces
            for (int j = 0; j < i - 1; ++j) {
                cout << " ";
            }
            
            // 2. Print the character pattern based on the row type
            if (i == 1) {
                // First row: print asterisks separated by spaces
                for (int j = 1; j <= n; ++j) {
                    cout << "*";
                    if (j < n) {
                        cout << " ";
                    }
                }
            } else if (i == n) {
                // Last row: only a single apex asterisk
                cout << "*";
            } else {
                // Middle rows: left asterisk, inner spaces, right asterisk
                cout << "*";
                int inner_spaces = 2 * n - 2 * i - 1;
                for (int j = 0; j < inner_spaces; ++j) {
                    cout << " ";
                }
                cout << "*";
            }
            
            // Move to the next line
            cout << "\n";
        }
    }

    return 0;
}

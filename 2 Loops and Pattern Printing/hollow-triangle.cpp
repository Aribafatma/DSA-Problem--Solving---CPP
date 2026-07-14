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
            for (int j = 0; j < n - i; ++j) {
                cout << " ";
            }
            
            if (i == 1) {
                // First row: only one asterisk
                cout << "*";
            } else if (i == n) {
                // Last row: print asterisks separated by spaces
                for (int j = 1; j <= n; ++j) {
                    cout << "*";
                    if (j < n) {
                        cout << " ";
                    }
                }
            } else {
                // Middle rows: left asterisk, inner spaces, right asterisk
                cout << "*";
                for (int j = 0; j < 2 * i - 3; ++j) {
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

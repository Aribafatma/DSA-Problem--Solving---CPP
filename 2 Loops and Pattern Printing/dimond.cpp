#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        // 1. Upper Triangle (Rows 1 to n)
        for (int i = 1; i <= n; ++i) {
            // Print leading spaces
            for (int j = 0; j < n - i; ++j) {
                cout << " ";
            }
            // Print asterisks separated by spaces
            for (int j = 1; j <= i; ++j) {
                cout << "*";
                if (j < i) {
                    cout << " ";
                }
            }
            cout << "\n";
        }

        // 2. Lower Triangle (Rows 1 to n - 1)
        for (int i = 1; i < n; ++i) {
            // Print leading spaces
            for (int j = 0; j < i; ++j) {
                cout << " ";
            }
            // Print asterisks separated by spaces
            for (int j = 1; j <= n - i; ++j) {
                cout << "*";
                if (j < n - i) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}

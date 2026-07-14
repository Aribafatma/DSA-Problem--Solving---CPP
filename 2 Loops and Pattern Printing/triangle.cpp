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
            
            // 2. Print asterisks with spaces in between
            for (int j = 1; j <= i; ++j) {
                cout << "*";
                if (j < i) {
                    cout << " ";
                }
            }
            
            // 3. Move to the next line
            cout << "\n";
        }
    }

    return 0;
}

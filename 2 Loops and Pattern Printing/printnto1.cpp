#include <iostream>

using namespace std;

int main() {
    int N;
    // Read the input integer N
    if (cin >> N) {
        // Loop from N down to 1
        for (int i = N; i >= 1; i--) {
            cout << i;
            
            // Print a space after the number, 
            // except after the last number (1)
            if (i > 1) {
                cout << " ";
            }
        }
    }
    return 0;
}

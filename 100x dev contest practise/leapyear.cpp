#include <iostream>

using namespace std;

int main() {
    int Y;
    // Read the input year
    cin >> Y;

    // Apply the rules:
    // 1. If divisible by 100, must also be divisible by 400.
    // 2. If not divisible by 100, must be divisible by 4.
    if (Y % 100 == 0) {
        if (Y % 400 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (Y % 4 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

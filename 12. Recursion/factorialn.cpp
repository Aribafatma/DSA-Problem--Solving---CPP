#include <iostream>
using namespace std;

// Recursive function to find factorial
int factorial(int n) {
    // Base Case: Factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive Case: n * factorial of (n-1)
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}

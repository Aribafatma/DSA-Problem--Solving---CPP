#include <iostream>
#include <cmath>

using namespace std;

// Euclidean Algorithm to find GCD
int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

// Optimized Primality Test (checking up to sqrt(n))
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num1 = 24, num2 = 36;

    // GCD Output
    cout << "GCD of " << num1 << " and " << num2 << " is: " << getGCD(num1, num2) << endl;

    // Primality Output
    int checkNum = 29;
    if (isPrime(checkNum)) {
        cout << checkNum << " is a prime number." << endl;
    } else {
        cout << checkNum << " is not a prime number." << endl;
    }

    return 0;
}

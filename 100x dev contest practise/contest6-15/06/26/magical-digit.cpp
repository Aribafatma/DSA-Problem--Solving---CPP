#include <iostream>

using namespace std;

// Recursive function to sum the digits of a number
long long sum_digits(long long n) {
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n / 10);
}

// Recursive function to reduce the number to a single digit
long long get_magical_digit(long long n) {
    if (n < 10) return n; // Base case: it's already a single digit
    return get_magical_digit(sum_digits(n)); // Recursive step
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    cout << get_magical_digit(n) << "\n";
    
    return 0;
}

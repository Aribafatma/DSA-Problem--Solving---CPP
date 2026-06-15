#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    // __builtin_ctzll counts trailing zeros for 64-bit integers
    cout << __builtin_ctzll(n) << "\n";
    
    return 0;
}

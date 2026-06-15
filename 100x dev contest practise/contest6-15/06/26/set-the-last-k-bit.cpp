
#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    int k;
    cin >> n >> k;
    
    // Create a mask with the lower K bits set to 1
    // Using 1ULL ensures the bit shift uses an unsigned 64-bit integer
    long long mask = (1ULL << k) - 1;
    
    // Apply bitwise OR to set the last K bits
    long long result = n | mask;
    
    cout << result << "\n";
    
    return 0;
}

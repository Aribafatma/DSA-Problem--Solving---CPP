#include <iostream>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        // Count the number of 1s in (n & (n >> 1))
        return __builtin_popcount(n & (n >> 1)) == 1;
    }
};

// ADD THIS MAIN FUNCTION AT THE BOTTOM
int main() {
    Solution solver;
    
    // Test with example 6 (Binary: 110 -> 1 pair)
    int test_num = 6; 
    
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Result for " << test_num << ": " << solver.consecutiveSetBits(test_num) << endl;
    
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    // Optimize standard input/output streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    long long min_val;
    int min_pos = 1;
    
    // Initialize with the first element of the array
    cin >> min_val;
    
    // Loop through the remaining elements from 1-based index 2 to N
    for (int i = 2; i <= n; ++i) {
        long long current_val;
        cin >> current_val;
        
        // Use strict less-than (<) to keep the smallest index in case of duplicates
        if (current_val < min_val) {
            min_val = current_val;
            min_pos = i;
        }
    }
    
    // Output the results separated by a space
    cout << min_val << " " << min_pos << "\n";
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Custom comparator function
bool compareUnits(int a, int b) {
    int last_a = abs(a) % 10;
    int last_b = abs(b) % 10;
    
    // If last digits are different, sort by last digit
    if (last_a != last_b) {
        return last_a < last_b;
    }
    // If last digits are the same, sort by actual value
    return a < b;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Sort the vector using the custom comparator
    sort(arr.begin(), arr.end(), compareUnits);
    
    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}

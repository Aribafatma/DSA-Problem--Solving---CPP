#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Custom comparator function
bool compareMagnitude(int a, int b) {
    // Cast to long long to safety handle absolute values uniformly
    long long abs_a = abs(static_cast<long long>(a));
    long long abs_b = abs(static_cast<long long>(b));
    
    if (abs_a != abs_b) {
        return abs_a < abs_b;
    }
    // If absolute values are equal, smaller actual value comes first
    return a < b;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Sort the vector using our custom comparator
    sort(arr.begin(), arr.end(), compareMagnitude);
    
    // Print the sorted array elements separated by spaces
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator function
bool compareStrings(const string &a, const string &b) {
    // If lengths are different, sort by length ascending
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    // If lengths are the same, sort lexicographically ascending
    return a < b;
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Sort using our custom rules
    sort(arr.begin(), arr.end(), compareStrings);
    
    // Print each string on a new line
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}

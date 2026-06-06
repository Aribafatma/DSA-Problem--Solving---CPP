#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator to determine which concatenation yields a larger number
bool compareStrings(const string& a, const string& b) {
    return a + b > b + a;
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
    
    // Sort strings using our greedy custom comparator
    sort(arr.begin(), arr.end(), compareStrings);
    
    // Edge case: If the largest element after sorting is "0", 
    // then all numbers are "0", so the output should just be "0".
    if (arr[0] == "0") {
        cout << "0\n";
        return 0;
    }
    
    // Print the numbers sequentially to form the largest concatenated string
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << "\n";
    
    return 0;
}

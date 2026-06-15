#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator to sort strings for lexicographically smallest concatenation
bool compareStrings(const string& a, const string& b) {
    return (a + b) < (b + a);
}

int main() {
    // Optimize standard input/output streams for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Sort the strings using the custom comparator
    sort(nums.begin(), nums.end(), compareStrings);

    // Edge case: If the smallest formed number starts with '0', the whole number is just "0"
    if (nums[0] == "0") {
        cout << "0\n";
        return 0;
    }

    // Concatenate all strings to get the final result
    string result = "";
    for (const string& s : nums) {
        result += s;
    }

    cout << result << "\n";

    return 0;
}

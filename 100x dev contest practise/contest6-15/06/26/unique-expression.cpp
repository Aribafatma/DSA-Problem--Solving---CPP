#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Base case: If there's only 1 element, there's exactly 1 unique result
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int slots = n - 1;
    int total_combinations = 1 << slots; // 2^(n-1)
    vector<int> results;
    results.reserve(total_combinations);

    // Iterate through all 2^(n-1) combinations using a bitmask
    for (int mask = 0; mask < total_combinations; mask++) {
        int current_sum = a[0];
        for (int i = 0; i < slots; i++) {
            // If the i-th bit is set, treat it as a '+' sign, otherwise '-'
            if ((mask >> i) & 1) {
                current_sum += a[i + 1];
            } else {
                current_sum -= a[i + 1];
            }
        }
        results.push_back(current_sum);
    }

    // Sort and remove duplicates to find distinct values
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    // Print the number of distinct elements
    cout << results.size() << "\n";

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Use long long to prevent integer overflow since sums can reach 10^14
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        // Build the prefix sum array
        pref[i] = pref[i - 1] + val;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Calculate the range sum in O(1) time
        long long range_sum = pref[r] - pref[l - 1];
        cout << range_sum << "\n";
    }

    return 0;
}

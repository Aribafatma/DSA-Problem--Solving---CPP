#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // pref[i] will store the sum of even-indexed elements up to index i
    // Using long long to prevent integer overflow
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        
        // If the 1-based index is even, include it in the sum
        if (i % 2 == 0) {
            pref[i] = pref[i - 1] + val;
        } else {
            pref[i] = pref[i - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // O(1) query response
        long long even_sum = pref[r] - pref[l - 1];
        cout << even_sum << "\n";
    }

    return 0;
}

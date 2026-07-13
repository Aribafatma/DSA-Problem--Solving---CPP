#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Fast standard I/O operations for performance efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Read the array elements (using long long for elements up to 10^9)
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<string> ans(n);
    stack<long long> st;

    // Process from left to right
    for (int i = 0; i < n; ++i) {
        
        // Step 1: Remove all elements from the stack that are smaller than or equal to a[i]
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }

        // Step 2: If stack is empty, no greater element exists to the left
        if (st.empty()) {
            ans[i] = "X";
        } else {
            ans[i] = to_string(st.top());
        }

        // Step 3: Push current element onto stack
        st.push(a[i]);
    }

    // Print the final outputs separated by spaces
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}

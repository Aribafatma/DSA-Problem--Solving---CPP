#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<string> ans(n);
    stack<long long> st;
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack that are smaller than or equal to current element
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        
        // If stack is empty, no greater element exists to the right
        if (st.empty()) {
            ans[i] = "x";
        } else {
            ans[i] = to_string(st.top());
        }
        
        // Push the current element onto the stack
        st.push(a[i]);
    }
    
    // Print the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}

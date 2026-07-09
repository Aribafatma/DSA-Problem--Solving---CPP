#include <iostream>
#include <stack>

using namespace std;

// The required MinStack class implementation
class MinStack {
private:
    stack<int> st;       // Primary stack for all elements
    stack<int> minSt;    // Auxiliary stack to track minimum elements

public:
    MinStack() {}
    
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        } else {
            minSt.push(minSt.top());
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }
};

// Driver code to process Codeforces input structure
int main() {
    // Optimize standard I/O operations for competitive programming performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; 
    if (!(cin >> q)) return 0;
    
    MinStack ms;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            ms.push(x);
        } 
        else if (type == 2) {
            ms.pop();
        } 
        else if (type == 3) {
            cout << ms.top() << "\n";
        } 
        else if (type == 4) {
            cout << ms.getMin() << "\n";
        }
    }
    
    return 0;
}

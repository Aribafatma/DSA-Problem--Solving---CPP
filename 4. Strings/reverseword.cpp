#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWords(string &s) {
    stack<string> st;
    string result = "";
    for (int i = 0; i < s.length(); i++) {

        if (s[i] != '.') {
            result += s[i];
        }

        // If we see a dot, we push the
        // previously seen word into the stack.
        else if (!result.empty()) {
            st.push(result);
            result = "";
        }
    }

    // Last word remaining, add it to stack
    if (!result.empty()) {
        st.push(s);
    }

    result = "";
    // Now add from top to bottom of the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
        if (!st.empty()) {
            result += ".";
        }
    }
    return result;
}

int main() {
    string s = "Ariba";
    cout << reverseWords(s) << endl;
    return 0;
}
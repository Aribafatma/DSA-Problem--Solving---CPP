#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> matrix(n);
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    vector<int> heights(m, 0);
    int max_area = 0;

    // Process row by row
    for (int i = 0; i < n; ++i) {
        // Step 1: Update column heights for the current row
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }

        // Step 2: Find max rectangle for the current heights using a stack
        stack<int> s;
        for (int j = 0; j <= m; ++j) {
            int cur_h = (j == m) ? 0 : heights[j];
            
            while (!s.empty() && cur_h < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? j : j - s.top() - 1;
                max_area = max(max_area, h * w);
            }
            s.push(j);
        }
    }

    cout << max_area << endl;
    return 0;
}

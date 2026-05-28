#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < m; j++) cin >> B[j];

    vector<int> merged;
    merged.reserve(n + m);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            merged.push_back(A[i]);
            i++;
        } else {
            merged.push_back(B[j]);
            j++;
        }
    }

    // Add remaining elements
    while (i < n) {
        merged.push_back(A[i]);
        i++;
    }
    while (j < m) {
        merged.push_back(B[j]);
        j++;
    }

    for (int k = 0; k < (int)merged.size(); k++) {
        cout << merged[k] << " ";
    }
    cout << "\n";

    return 0;
}

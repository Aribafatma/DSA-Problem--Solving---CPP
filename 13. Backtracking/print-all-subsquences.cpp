#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // There are 2^N total subsequences (including the empty one).
    // We start from 1 to skip the empty subsequence.
    int total_subsequences = 1 << N; 

    for (int i = 1; i < total_subsequences; ++i) {
        bool first = true;
        for (int j = 0; j < N; ++j) {
            // Check if the j-th bit is set in the current mask 'i'
            if ((i >> (N - 1 - j)) & 1) {
                if (!first) cout << " ";
                cout << A[j];
                first = false;
            }
        }
        cout << "\n";
    }

    return 0;
}

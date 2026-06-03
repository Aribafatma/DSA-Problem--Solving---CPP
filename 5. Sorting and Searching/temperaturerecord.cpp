#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for large input size
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> temp(N);
    for (int i = 0; i < N; ++i) {
        cin >> temp[i];
    }

    // Sort the temperatures in non-decreasing order
    sort(temp.begin(), temp.end());

    // Print the sorted output
    for (int i = 0; i < N; ++i) {
        cout << temp[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}

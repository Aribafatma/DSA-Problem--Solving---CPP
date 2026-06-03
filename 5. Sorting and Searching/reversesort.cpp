#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator to sort in descending order
bool compareDescending(int a, int b) {
    return a > b;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Use std::sort with the custom comparator
    sort(arr.begin(), arr.end(), compareDescending);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> getPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0]; // First element is the same

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i]; // Current = Previous Sum + Current Element
    }
    return prefixSum;
}

int main() {
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> result = getPrefixSum(arr);

    for (int x : result) cout << x << " "; // Output: 10 30 40 45 60
    return 0;
}

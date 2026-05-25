#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate factorial n!
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Sort the array to ensure next_permutation generates all possibilities
    sort(nums.begin(), nums.end());

    // Print the total number of permutations (n!)
    cout << factorial(n) << endl;

    // Generate and print each permutation
    do {
        for (int i = 0; i < n; i++) {
            cout << nums[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}

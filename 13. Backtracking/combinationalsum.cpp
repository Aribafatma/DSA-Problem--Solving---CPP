#include <iostream>
#include <vector>

using namespace std;

/**
 * Backtracking function to find all unique combinations.
 *  index: Current starting index in the candidates array.
 * target: Remaining sum to reach.
 *  candidates: The list of available integers.
 *  current: The current combination being built.
 *  results: A container to store all valid combinations.
 */
void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& results) {
    // Base Case: target reached
    if (target == 0) {
        results.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        // If the candidate is smaller than or equal to the target, it can be part of a combination
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            // Recurse with the same index 'i' because we can reuse the same number
            findCombinations(i, target - candidates[i], candidates, current, results);
            // Backtrack: remove the number to try the next candidate
            current.pop_back();
        }
    }
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }

    vector<vector<int>> results;
    vector<int> current;

    findCombinations(0, target, candidates, current, results);

    // Output the total number of combinations
    cout << results.size() << "\n";

    // Output each combination in the required format: [length] [elements...]
    for (const auto& combination : results) {
        cout << combination.size();
        for (int num : combination) {
            cout << " " << num;
        }
        cout << "\n";
    }

    return 0;
}

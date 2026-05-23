#include <iostream>
#include <vector>

// Recursive backtracking function
void findSubsets(const std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    // Base Case: Every path down the decision tree forms a valid subset
    result.push_back(current);

    // Loop through the remaining choices
    for (int i = index; i < nums.size(); ++i) {
        // 1. Make Choice: Include the element at index 'i'
        current.push_back(nums[i]);

        // 2. Recurse: Move to the next elements to find further combinations
        findSubsets(nums, i + 1, current, result);

        // 3. Backtrack: Remove the element to try other options
        current.pop_back();
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    // Start backtracking from index 0
    findSubsets(nums, 0, current, result);

    // Output all generated subsets
    std::cout << "All generated subsets:\n";
    for (const auto& subset : result) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}

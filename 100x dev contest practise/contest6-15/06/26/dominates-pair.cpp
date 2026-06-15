#include <iostream>
#include <vector>

using namespace std;

long long total_pairs = 0;

// Merge function that counts the dominant pairs and merges sorted subarrays
void merge_and_count(vector<long long>& nums, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    // Count the dominant pairs where i is in the left subarray and j is in the right subarray
    while (i <= mid) {
        while (j <= right && nums[i] > 3LL * nums[j]) {
            j++;
        }
        total_pairs += (j - (mid + 1));
        i++;
    }

    // Standard merge operation to sort the array
    vector<long long> temp;
    temp.reserve(right - left + 1);
    i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

// Divide and Conquer wrapper
void merge_sort(vector<long long>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge_and_count(nums, left, mid, right);
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    merge_sort(nums, 0, n - 1);

    cout << total_pairs << "\n";

    return 0;
}

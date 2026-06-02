#include <iostream>
#include <vector>

using namespace std;

// Function to count reverse pairs and merge sorted subarrays
long long countAndMerge(vector<int>& arr, int left, int mid, int right) {
    long long count = 0;
    int j = mid + 1;

    // 1. Count pairs where A[i] > 2 * A[j]
    for (int i = left; i <= mid; i++) {
        // Use long long for the multiplication to avoid overflow
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // 2. Standard merge process to keep the array sorted
    vector<int> temp;
    int i = left, k = mid + 1;
    while (i <= mid && k <= right) {
        if (arr[i] <= arr[k]) temp.push_back(arr[i++]);
        else temp.push_back(arr[k++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (k <= right) temp.push_back(arr[k++]);

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[left + idx] = temp[idx];
    }

    return count;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    long long count = 0;
    
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += countAndMerge(arr, left, mid, right);
    
    return count;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1) << endl;

    return 0;
}

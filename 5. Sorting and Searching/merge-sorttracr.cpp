#include <iostream>
#include <vector>

using namespace std;

// Merges two sorted halves and prints the merged range
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Print the merge log
    cout << "Merge: [" << left << " " << right << "] ->";
    for (int idx = left; idx <= right; idx++) {
        cout << " " << arr[idx];
    }
    cout << "\n";
}

// Recursive merge sort trace function
void mergeSortTrace(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Print the division log
        cout << "Divide: [" << left << " " << right << "]\n";

        int mid = left + (right - left) / 2;

        // Recursively sort left and right halves
        mergeSortTrace(arr, left, mid);
        mergeSortTrace(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
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

    mergeSortTrace(arr, 0, n - 1);

    return 0;
}

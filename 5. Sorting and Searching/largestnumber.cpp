#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for large input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Use a frequency array for digits 0-9
    int freq[10] = {0};
    for (int i = 0; i < N; ++i) {
        int digit;
        cin >> digit;
        freq[digit]++;
    }

    // Print digits from 9 down to 0 to form the largest number
    for (int i = 9; i >= 0; --i) {
        while (freq[i] > 0) {
            cout << i;
            freq[i]--;
        }
    }
    cout << endl;

    return 0;
}

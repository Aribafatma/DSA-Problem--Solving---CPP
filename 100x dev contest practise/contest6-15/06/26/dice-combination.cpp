#include <iostream>
#include <vector>

using namespace std;

// Recursive function to find and print all combinations
void solve(int remaining_sum, vector<int>& current_sequence) {
    // Base Case: If the target sum is reached, print the sequence
    if (remaining_sum == 0) {
        for (size_t i = 0; i < current_sequence.size(); ++i) {
            cout << current_sequence[i] << (i + 1 == current_sequence.size() ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // Try all possible dice rolls from 1 to 6
    for (int die = 1; die <= 6; ++die) {
        if (remaining_sum - die >= 0) {
            current_sequence.push_back(die);       // Choose
            solve(remaining_sum - die, current_sequence); // Recurse
            current_sequence.pop_back();          // Backtrack
        } else {
            // Since dice values are increasing, if 'die' exceeds remaining_sum, 
            // any subsequent higher dice numbers will also exceed it.
            break; 
        }
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    vector<int> current_sequence;
    solve(k, current_sequence);

    return 0;
}

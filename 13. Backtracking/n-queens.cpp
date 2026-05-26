#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, int n, vector<string>& board) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& results) {
    if (row == n) {
        results.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, board)) {
            board[row][col] = 'Q';
            solve(row + 1, n, board, results);
            board[row][col] = '.'; // Backtrack
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<string>> results;
    vector<string> board(n, string(n, '.'));

    solve(0, n, board, results);

    // Print the total number of configurations
    cout << results.size() << endl;

    // Print each configuration
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << results[i][j] << endl;
        }
        // Print a blank line between configurations, but not after the last one
        if (i < results.size() - 1) {
            cout << endl;
        }
    }

    return 0;
}

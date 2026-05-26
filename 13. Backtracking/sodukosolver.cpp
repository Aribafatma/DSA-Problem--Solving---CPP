#include <iostream>
#include <vector>

using namespace std;

// Check if placing num at board[row][col] is valid
bool isValid(vector<string>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == num) return false;
        // Check column
        if (board[i][col] == num) return false;
        // Check 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
    }
    return true;
}

bool solve(vector<string>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solve(board)) return true;
                        board[i][j] = '.'; // Backtrack
                    }
                }
                return false; // No valid number found for this cell
            }
        }
    }
    return true; // All cells filled
}

int main() {
    vector<string> board(9);
    for (int i = 0; i < 9; i++) {
        cin >> board[i];
    }

    if (solve(board)) {
        for (int i = 0; i < 9; i++) {
            cout << board[i] << endl;
        }
    }

    return 0;
}

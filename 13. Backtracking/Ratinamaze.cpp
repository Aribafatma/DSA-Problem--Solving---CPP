#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findPaths(int r, int c, int n, vector<vector<int>>& maze, 
               vector<vector<bool>>& visited, string path, vector<string>& results) {
    // Base Case: Reached the destination
    if (r == n - 1 && c == n - 1) {
        results.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[r][c] = true;

    // Direction arrays for Down, Left, Right, Up (Lexicographical order)
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char move[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];

        // Check if next move is within bounds, not blocked, and not visited
        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && 
            maze[nextR][nextC] == 1 && !visited[nextR][nextC]) {
            findPaths(nextR, nextC, n, maze, visited, path + move[i], results);
        }
    }

    // Backtrack: Unmark current cell
    visited[r][c] = false;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> results;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Start only if the entry and exit points are not blocked
    if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
        findPaths(0, 0, n, maze, visited, "", results);
    }

    if (results.empty()) {
        cout << 0 << endl;
    } else {
        for (const string& s : results) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}

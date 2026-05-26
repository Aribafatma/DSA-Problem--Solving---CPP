#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Direction arrays in lexicographical order: Down (D), Left (L), Right (R), Up (U)
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

void findPaths(int x, int y, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& result) {
    // Base Case: Reached the destination
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Check if the next move is valid: within bounds, not blocked, and not visited
        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && 
            maze[nextX][nextY] == 1 && !visited[nextX][nextY]) {
            findPaths(nextX, nextY, n, maze, visited, path + dir[i], result);
        }
    }

    // Backtrack: mark cell as unvisited for other potential paths
    visited[x][y] = false;
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

    vector<string> result;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Start only if the entry and exit points are not blocked
    if (maze[0][0] == 1 && maze[n-1][n-1] == 1) {
        findPaths(0, 0, n, maze, visited, "", result);
    }

    if (result.empty()) {
        cout << 0 << endl;
    } else {
        cout << result.size() << endl;
        for (const string& path : result) {
            cout << path << endl;
        }
    }

    return 0;
}

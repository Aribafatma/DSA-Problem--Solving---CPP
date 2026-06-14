#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    if (!(cin >> n >> m >> x)) return 0;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int current;
            cin >> current;
            if (current == x) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

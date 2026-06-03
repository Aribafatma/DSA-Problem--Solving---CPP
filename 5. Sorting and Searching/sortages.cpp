#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Frequency array to store counts of ages 0 to 100
    int count[101] = {0};
    int age;

    for (int i = 0; i < n; ++i) {
        cin >> age;
        count[age]++;
    }

    // Output ages in non-decreasing order
    bool first = true;
    for (int i = 0; i <= 100; ++i) {
        while (count[i] > 0) {
            if (!first) cout << " ";
            cout << i;
            count[i]--;
            first = false;
        }
    }
    cout << endl;

    return 0;
}

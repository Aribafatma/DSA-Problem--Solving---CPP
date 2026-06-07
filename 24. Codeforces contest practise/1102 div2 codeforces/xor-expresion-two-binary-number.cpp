#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s, z;
    cin >> s >> z;
    
    // FIX 1: Correctly declared 2D array with dimensions [2][2]
    long long c[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        int b = z[i] - '0';
        c[a][b]++;
    }
    
    // Compute frequencies of each transition component
    unsigned long long f1, f2, f3;
    unsigned long long two_k = 1ULL << k;
    if (k % 2 == 1) {
        f1 = (two_k + 1) / 3;
        f2 = f1;
        f3 = f1;
    } else {
        f1 = (two_k - 1) / 3 + 1;
        f2 = f1;
        f3 = (two_k - 1) / 3;
    }
    
    // FIX 2: Replaced __int128 with standard unsigned long long to avoid 32-bit compiler crashes
    unsigned long long total_ans = 0;
    
    // Iterate through all pairs of bit categories
    for (int a1 = 0; a1 <= 1; a1++) {
        for (int b1 = 0; b1 <= 1; b1++) {
            if (c[a1][b1] == 0) continue;
            for (int a2 = 0; a2 <= 1; a2++) {
                for (int b2 = 0; b2 <= 1; b2++) {
                    if (c[a2][b2] == 0) continue;
                    
                    // Combine bits into a 2-bit state value (0 to 3)
                    // State 2 (binary 10) represents (j-th bit = 1, l-th bit = 0)
                    int v1 = (a1 << 1) | a2;
                    int v2 = (b1 << 1) | b2;
                    int v3 = v1 ^ v2;
                    
                    unsigned long long freq2 = 0;
                    if (v1 == 2) freq2 += f1;
                    if (v2 == 2) freq2 += f2;
                    if (v3 == 2) freq2 += f3;
                    
                    unsigned long long pairs = (unsigned long long)c[a1][b1] * c[a2][b2];
                    total_ans += pairs * freq2;
                }
            }
        }
    }
    
    cout << total_ans << "\n";
}

int main() {
    // Optimize standard I/O streams for fast competitive execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

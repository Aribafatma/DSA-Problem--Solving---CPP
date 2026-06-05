#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global reference point coordinates
long long ref_a, ref_b;

// Structure to hold individual point coordinates
struct Point {
    long long x, y;
    long long distSq; // Stores the squared Euclidean distance to (a, b)
};

// Custom comparator to sort according to the specified rules
bool comparePoints(const Point& p1, const Point& p2) {
    // 1. Sort by squared Euclidean distance in ascending order
    if (p1.distSq != p2.distSq) {
        return p1.distSq < p2.distSq;
    }
    // 2. If distances match, sort by x coordinate in ascending order
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    // 3. If x coordinates match, sort by y coordinate in ascending order
    return p1.y < p2.y;
}

int main() {
    // Optimize standard I/O streams for speed in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n >> ref_a >> ref_b)) return 0;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        
        // Calculate squared Euclidean distance to prevent floating-point precision loss
        long long dx = points[i].x - ref_a;
        long long dy = points[i].y - ref_b;
        points[i].distSq = (dx * dx) + (dy * dy);
    }

    // Sort the vector utilizing our custom tier rule function
    sort(points.begin(), points.end(), comparePoints);

    // Print the sorted output results
    for (int i = 0; i < n; ++i) {
        cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}

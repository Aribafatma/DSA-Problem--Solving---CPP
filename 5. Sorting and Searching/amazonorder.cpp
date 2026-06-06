#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store the details of each order
struct Order {
    long long orderId;
    long long timestamp;
    long long priority;
};

// Custom comparator to sort according to the rules
bool compareOrders(const Order& a, const Order& b) {
    // 1. Higher priority comes first (descending)
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    }
    // 2. If priorities are equal, earlier timestamp comes first (ascending)
    if (a.timestamp != b.timestamp) {
        return a.timestamp < b.timestamp;
    }
    // 3. If priority and timestamp are equal, smaller orderId comes first (ascending)
    return a.orderId < b.orderId;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Order> orders(n);
    for (int i = 0; i < n; ++i) {
        cin >> orders[i].orderId >> orders[i].timestamp >> orders[i].priority;
    }
    
    // Sort using the custom comparator function
    sort(orders.begin(), orders.end(), compareOrders);
    
    // Print the sorted results
    for (int i = 0; i < n; ++i) {
        cout << orders[i].orderId << " " << orders[i].timestamp << " " << orders[i].priority << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to store the details of each flight
struct Flight {
    long long flightNumber;
    int departureTime;
    string destination;
};

// Custom comparator to sort according to the rules
bool compareFlights(const Flight& a, const Flight& b) {
    // 1. Earlier departure time comes first (ascending)
    if (a.departureTime != b.departureTime) {
        return a.departureTime < b.departureTime;
    }
    // 2. If departure times are equal, smaller flightNumber comes first (ascending)
    return a.flightNumber < b.flightNumber;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Flight> flights(n);
    for (int i = 0; i < n; ++i) {
        cin >> flights[i].flightNumber >> flights[i].departureTime >> flights[i].destination;
    }
    
    // Sort using the custom comparator function
    sort(flights.begin(), flights.end(), compareFlights);
    
    // Print the sorted results
    for (int i = 0; i < n; ++i) {
        cout << flights[i].flightNumber << " " << flights[i].departureTime << " " << flights[i].destination << "\n";
    }
    
    return 0;
}

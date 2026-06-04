#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Represent a student record
struct Student {
    string name;
    int marks;
};

// Custom comparator function
bool compareScholars(const Student &a, const Student &b) {
    // If marks are different, sort by marks in descending order
    if (a.marks != b.marks) {
        return a.marks > b.marks;
    }
    // If marks are equal, sort by name in lexicographical ascending order
    return a.name < b.name;
}

int main() {
    // Optimize standard I/O streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].marks;
    }
    
    // Sort using our custom rules
    sort(students.begin(), students.end(), compareScholars);
    
    // Print results line by line
    for (int i = 0; i < n; ++i) {
        cout << students[i].name << " " << students[i].marks << "\n";
    }
    
    return 0;
}

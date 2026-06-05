#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to store student details
struct Student {
    string name;
    int totalMarks;
    int physicsMarks;
    int chemMarks;
    int mathsMarks;
};

// Custom comparator to sort according to the rules
bool compareStudents(const Student& a, const Student& b) {
    // 1. Higher totalMarks comes first
    if (a.totalMarks != b.totalMarks) {
        return a.totalMarks > b.totalMarks;
    }
    // 2. Higher mathsMarks comes first
    if (a.mathsMarks != b.mathsMarks) {
        return a.mathsMarks > b.mathsMarks;
    }
    // 3. Higher physicsMarks comes first
    if (a.physicsMarks != b.physicsMarks) {
        return a.physicsMarks > b.physicsMarks;
    }
    // 4. Lexicographically smaller name comes first
    return a.name < b.name;
}

int main() {
    // Optimize standard I/O operations for competitive programming performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name 
            >> students[i].totalMarks 
            >> students[i].physicsMarks 
            >> students[i].chemMarks 
            >> students[i].mathsMarks;
    }

    // Sort the vector using our custom rules
    sort(students.begin(), students.end(), compareStudents);

    // Print the sorted output
    for (const auto& student : students) {
        cout << student.name << " " 
             << student.totalMarks << " " 
             << student.physicsMarks << " " 
             << student.chemMarks << " " 
             << student.mathsMarks << "\n";
    }

    return 0;
}

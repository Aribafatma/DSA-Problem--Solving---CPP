#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function required by the problem
int findMin(Node* head) {
    if (head == nullptr) {
        return -1;
    }
    
    int min_val = head->data;
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data < min_val) {
            min_val = current->data;
        }
        current = current->next;
    }
    
    return min_val;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    if (n == 0) {
        cout << -1 << "\n";
        return 0;
    }
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    // Read the array elements and build the linked list
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Get the minimum and print the output
    cout << findMin(head) << "\n";
    
    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    return 0;
}

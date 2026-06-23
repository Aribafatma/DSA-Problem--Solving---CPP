#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function required by the problem (1-indexed)
int findKth(Node* head, int k) {
    Node* current = head;
    int current_index = 1;

    // Traverse the list until we find the k-th node or reach the end
    while (current != nullptr) {
        if (current_index == k) {
            return current->data;
        }
        current_index++;
        current = current->next;
    }

    // If the k-th node does not exist
    return -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Build the linked list from input
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

    int k;
    cin >> k;

    // Find and print the k-th node value
    cout << findKth(head, k) << "\n";

    // Free memory to prevent memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}

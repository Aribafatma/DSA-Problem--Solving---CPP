#include <iostream>

using namespace std;

// Definition for a singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// --- Required Function for Submission ---
Node* reverseBetween(Node* head, int left, int right) {
    if (!head || left == right) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    // Move prev to the node just before the 'left' position
    for (int i = 0; i < left - 1; ++i) {
        prev = prev->next;
    }

    // curr always points to the first node of the sub-list to be reversed
    Node* curr = prev->next;

    // Reverse the links one by one
    for (int i = 0; i < right - left; ++i) {
        Node* nxt = curr->next;
        curr->next = nxt->next;
        nxt->next = prev->next;
        prev->next = nxt;
    }

    Node* newHead = dummy->next;
    delete dummy; 
    return newHead;
}

// Driver code to handle Codeforces I/O format
int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 0) return 0;

        // Read the head node
        int val;
        cin >> val;
        Node* head = new Node(val);
        Node* tail = head;

        // Read the remaining nodes to build the list
        for (int i = 1; i < n; ++i) {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        // Read left and right positions
        int left, right;
        cin >> left >> right;

        // Process the list
        head = reverseBetween(head, left, right);

        // Print the final modified linked list
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << (temp->next ? " " : "");
            temp = temp->next;
        }
        cout << "\n";
    }

    return 0;
}

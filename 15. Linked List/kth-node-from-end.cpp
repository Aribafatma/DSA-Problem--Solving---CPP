#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function required by the problem template
Node* kthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;

    // Advance fast pointer by k nodes
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return nullptr;
        fast = fast->next;
    }

    // Advance both pointers until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        Node* head = nullptr;
        Node* tail = nullptr;

        // Build the linked list from standard input
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node(value);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int k;
        cin >> k;

        // Get the target node
        Node* resultNode = kthFromEnd(head, k);

        // Print the data value of the target node
        if (resultNode != nullptr) {
            cout << resultNode->data << "\n";
        }

        // Free allocated memory to prevent leaks
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    return 0;
}

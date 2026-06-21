#include <iostream>
#include <vector>

using namespace std;

// Definition for the Singly Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// The required function implementation requested by the platform
int countX(Node* head, int x) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == x) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Read list node values and build the linked list sequentially
    for (int i = 0; i < n; i++) {
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

    // Read target element x to search for
    int x;
    cin >> x;

    // Execute lookup and output the frequency result
    cout << countX(head, x) << "\n";

    // Clean up memory to prevent memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}

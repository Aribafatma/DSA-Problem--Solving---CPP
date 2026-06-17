#include <iostream>

using namespace std;

// Definition of the linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// --- Your required function implementation ---
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "X\n";
}

// Main function to read input and build the list
int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 0) {
            printList(nullptr);
            return 0;
        }

        int val;
        cin >> val;
        Node* head = new Node(val);
        Node* tail = head;

        for (int i = 1; i < n; i++) {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        printList(head);
    }

    return 0;
}

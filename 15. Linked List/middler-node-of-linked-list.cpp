#include <iostream>
#include <vector>

using namespace std;

// Structure for the Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to find the first middle node
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    // The exact condition to stop early and target the FIRST middle node on even lengths
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    // Constructing the linked list from standard input
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Finding the middle node
    Node* middleNode = findMiddle(head);
    
    if (middleNode != NULL) {
        cout << middleNode->data << "\n";
    }
    
    // Optional: Free memory to avoid memory leaks
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    // Fast I/O optimize for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Solve the problem
    solve();
    
    return 0;
}

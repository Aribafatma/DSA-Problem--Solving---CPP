#include <iostream>

using namespace std;

// Definition for a singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// --- Implement only this function for the platform submission ---
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr != nullptr) {
        Node* nextNode = curr->next; // Temporarily store the next node
        curr->next = prev;           // Reverse the current node's pointer
        prev = curr;                 // Move prev pointer one step forward
        curr = nextNode;             // Move curr pointer one step forward
    }
    
    return prev; // prev will point to the new head of the reversed list
}

// Main function to test the implementation with Codeforces input/output format
int main() {
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
        
        // Read the remaining nodes
        for (int i = 1; i < n; ++i) {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        // Reverse the linked list
        head = reverseList(head);
        
        // Print the reversed linked list
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << (temp->next ? " " : "");
            temp = temp->next;
        }
        cout << "\n";
    }
    
    return 0;
}

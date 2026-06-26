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

// Core function required to delete the node
void deleteNode(Node* node) {
    if (node == NULL || node->next == NULL) return;
    
    Node* temp = node->next;
    node->data = temp->data;      // Copy next node's data over
    node->next = temp->next;      // Skip the next node
    delete temp;                  // Free memory
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    Node* head = NULL;
    Node* tail = NULL;
    vector<Node*> nodeReferences; // Stores pointers to access the target node directly by index
    
    // 1. Read the list values and construct the linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        nodeReferences.push_back(newNode);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // 2. Read the 0-based index of the node to delete (e.g., 1 for the second node)
    int targetIndex;
    cin >> targetIndex;
    
    // 3. Delete the node if it's within a valid, non-last node range
    if (targetIndex >= 0 && targetIndex < n - 1) {
        deleteNode(nodeReferences[targetIndex]);
    }
    
    // 4. Print the remaining elements in the linked list
    Node* curr = head;
    bool first = true;
    while (curr != NULL) {
        if (!first) cout << " ";
        cout << curr->data;
        first = false;
        curr = curr->next;
    }
    cout << "\n";
    
    // 5. Clean up remaining dynamically allocated nodes
    curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    
    return 0;
}

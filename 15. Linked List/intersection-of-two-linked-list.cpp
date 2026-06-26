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

// Function to find the intersection node
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == NULL || headB == NULL) return NULL;
    
    Node* ptrA = headA;
    Node* ptrB = headB;
    
    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }
    
    return ptrA;
}

void solve() {
    int totalA, totalB, intersectLen;
    if (!(cin >> totalA >> totalB >> intersectLen)) return;
    
    int skipA = totalA - intersectLen;
    int skipB = totalB - intersectLen;
    
    // 1. Build unique section of List A
    Node* headA = NULL;
    Node* tailA = NULL;
    for (int i = 0; i < skipA; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!headA) {
            headA = newNode;
            tailA = newNode;
        } else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }
    
    // 2. Build unique section of List B
    Node* headB = NULL;
    Node* tailB = NULL;
    for (int i = 0; i < skipB; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!headB) {
            headB = newNode;
            tailB = newNode;
        } else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }
    
    // 3. Build the shared intersection segment
    Node* headIntersect = NULL;
    Node* tailIntersect = NULL;
    for (int i = 0; i < intersectLen; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!headIntersect) {
            headIntersect = newNode;
            tailIntersect = newNode;
        } else {
            tailIntersect->next = newNode;
            tailIntersect = newNode;
        }
    }
    
    // 4. Stitch the segments together to form the Y-structure
    if (tailA) {
        tailA->next = headIntersect;
    } else {
        headA = headIntersect; // If skipA is 0, headA starts directly at intersection
    }
    
    if (tailB) {
        tailB->next = headIntersect;
    } else {
        headB = headIntersect; // If skipB is 0, headB starts directly at intersection
    }
    
    // Find intersection node
    Node* intersectionNode = getIntersectionNode(headA, headB);
    
    // Output the data if found, else null indicator
    if (intersectionNode != NULL) {
        cout << intersectionNode->data << "\n";
    } else {
        cout << "NULL\n";
    }
    
    // Optional: Clean up allocated nodes to prevent heap leaks
    // Note: Freeing a Y-structure requires care so shared nodes aren't double deleted
    Node* curr = headA;
    while (curr && curr != headIntersect) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    curr = headB;
    while (curr && curr != headIntersect) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    curr = headIntersect;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    // Fast I/O configuration for competitive environments
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// --- REQUIRED FUNCTION TO IMPLEMENT ---
Node* deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        if (head != nullptr) delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

// Helper function to build a linked list from an array/vector
Node* buildList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        Node* head = buildList(arr);
        head = deleteMiddle(head);
        printList(head);
    }

    return 0;
}

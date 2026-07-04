#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    The list is sorted in non-decreasing order. Delete all duplicates so that
    each value appears only once, and return the head of the modified list.
*/

/*
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
*/

Node* deleteDuplicates(Node* head) {
    // Return early if list is empty or has one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* current = head;
    
    // Traverse the linked list
    while (current != nullptr && current->next != nullptr) {
        // Check if current value matches next value
        if (current->val == current->next->val) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; // Free up memory
        } else {
            // Move to next distinct element
            current = current->next;
        }
    }
    
    return head;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = deleteDuplicates(ll.head);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}
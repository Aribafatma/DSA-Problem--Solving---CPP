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
    Sort the linked list in ascending order and return the new head.
*/

// Helper function to merge two sorted lists
Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* curr = &dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    if (l1 != nullptr) curr->next = l1;
    if (l2 != nullptr) curr->next = l2;
    
    return dummy.next;
}

// Helper function to find the middle element
Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
    Implement only the function below.
    Sort the linked list in ascending order and return the new head.
*/
Node* sortList(Node* head)
{
    // Base case: if list is empty or has only one element
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Split the list into two halves
    Node* mid = getMid(head);
    Node* rightHalf = mid->next;
    mid->next = nullptr; // Disconnect the left half from the right half
    
    // Recursively sort both halves
    Node* leftSorted = sortList(head);
    Node* rightSorted = sortList(rightHalf);
    
    // Merge the sorted halves back together
    return merge(leftSorted, rightSorted);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = sortList(ll.head);

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
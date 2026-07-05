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
    Merge two sorted (non-decreasing) lists into one sorted list and return
    the head of the merged list. Either list may be empty (nullptr).
*/

/**
 * Note: Check your template code to see if the node's value variable 
 * is named 'val' or 'data', and adjust the code below accordingly.
 */
Node* mergeTwoLists(Node* l1, Node* l2) {
    // Create a dummy node to act as the start of the merged list
    Node dummy(0);
    Node* tail = &dummy;
    
    // Traverse both lists until one becomes empty
    while (l1 != nullptr && l2 != nullptr) {
        // Compare data fields (change 'val' to 'data' if needed)
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Append the remaining nodes of the non-empty list
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    
    // Return the actual head of the merged list
    return dummy.next;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1;
    cin >> n1;

    LinkedList a;
    a.build(n1);

    int n2;
    cin >> n2;

    LinkedList b;
    b.build(n2);

    Node* head = mergeTwoLists(a.head, b.head);

    Node* cur = head;

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
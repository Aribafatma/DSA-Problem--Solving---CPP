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
    Partition the list so that every node with value < x comes before every
    node with value >= x, preserving the original relative order within each
    of the two partitions. Return the head of the partitioned list.
*/

Node* partition(Node* head, int x) {
    // Create dummy heads for the two separate sub-lists
    Node lessHead(0);    // Tracks nodes with values < x
    Node greaterHead(0); // Tracks nodes with values >= x

    // Pointers to the tail ends of both sub-lists
    Node* lessTail = &lessHead;
    Node* greaterTail = &greaterHead;

    Node* curr = head;

    // Traverse the original list
    while (curr != nullptr) {
        // CHANGED: Use curr->val instead of curr->data
        if (curr->val < x) { 
            lessTail->next = curr;
            lessTail = lessTail->next;
        } else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }

    // Connect the end of the 'less' list to the beginning of the 'greater' list
    lessTail->next = greaterHead.next;

    // Terminate the combined list properly
    greaterTail->next = nullptr;

    // Return the head of the newly partitioned list
    return lessHead.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int x;
    cin >> x;

    ll.head = partition(ll.head, x);

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
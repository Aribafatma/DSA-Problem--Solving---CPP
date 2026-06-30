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
    Reverse the nodes of the list k at a time and return the new head.
    If the number of nodes is not a multiple of k, the leftover nodes at the
    end remain in their original order.
*/

Node* reverseKGroup(Node* head, int k) {
    // Step 1: Check if there are at least k nodes left in the list
    Node* curr = head;
    for (int i = 0; i < k; i++) {
        if (!curr) return head; // Fewer than k nodes, leave as-is
        curr = curr->next;
    }

    // Step 2: Reverse the first k nodes of the current group
    Node* prevNode = nullptr;
    Node* currNode = head;
    Node* nextNode = nullptr;
    
    for (int i = 0; i < k; i++) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    // Step 3: Recurse for the remaining nodes and connect the groups
    if (nextNode != nullptr) {
        head->next = reverseKGroup(nextNode, k);
    }

    // prevNode is now the new head of this reversed k-node group
    return prevNode;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int k;
    cin >> k;

    ll.head = reverseKGroup(ll.head, k);

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
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
    Node* tail;
    vector<Node*> nodes;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void build(int n)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            nodes.push_back(node);

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
    Return true if the linked list has a cycle, otherwise false.
*/

bool hasCycle(Node* head) {
    // Base case: an empty list or a list with only one node cannot have a cycle
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head; // Moves 1 step at a time
    Node* fast = head; // Moves 2 steps at a time

    // Traverse the list until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        // If they meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If fast pointer reaches the end, there is no cycle
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int pos;
    cin >> pos;

    if(pos != -1)
        ll.tail->next = ll.nodes[pos];

    cout << (hasCycle(ll.head) ? "true" : "false") << '\n';

    return 0;
}
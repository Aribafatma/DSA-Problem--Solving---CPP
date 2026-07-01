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
    Return the number of nodes in the loop, or 0 if there is no loop.
*/

/*
// Definition for singly-linked list node (for reference)
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};
*/

int lengthOfLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return 0;
    }

    Node* slow = head;
    Node* fast = head;

    // Phase 1: Detect if a cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            // Phase 2: Count the number of nodes in the loop
            int count = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    // No cycle found
    return 0;
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

    cout << lengthOfLoop(ll.head) << '\n';

    return 0;
}
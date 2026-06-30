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
    Return the node where the cycle begins, or nullptr if there is no cycle.
*/

Node* detectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    // Phase 1: Determine if a cycle exists
    bool hasCycle = false;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If there is no cycle, return nullptr
    if (!hasCycle) {
        return nullptr;
    }

    // Phase 2: Find the entry node of the cycle
    // Reset slow pointer to the head of the list
    slow = head;
    
    // Move both pointers at equal speed (1 step at a time)
    // They will meet exactly at the starting node of the cycle
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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

    Node* ans = detectCycle(ll.head);

    int idx = -1;

    for(int i = 0; i < n; i++)
    {
        if(ll.nodes[i] == ans)
        {
            idx = i;
            break;
        }
    }

    cout << idx << '\n';

    return 0;
}
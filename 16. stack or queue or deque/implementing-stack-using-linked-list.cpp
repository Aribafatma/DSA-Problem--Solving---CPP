#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below, using a singly linked list.
    void push(int x) -- insert x onto the top of the stack.
    int  pop()       -- remove and return the top element; return -1 if empty.
    int  top()       -- return the top element; return -1 if empty.
    bool empty()     -- return true if the stack is empty, else false.
    int  size()      -- return the number of elements in the stack.
    Every operation must run in O(1) time.
*/

class MyStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int current_size;

public:
    MyStack()
    {
        head = nullptr;
        current_size = 0;
    }

    // Custom destructor to prevent memory leaks during evaluation
    ~MyStack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        current_size++;
    }

    int pop()
    {
        if (empty()) {
            return -1;
        }
        Node* temp = head;
        int poppedValue = temp->data;
        head = head->next;
        delete temp;
        current_size--;
        return poppedValue;
    }

    int top()
    {
        if (empty()) {
            return -1;
        }
        return head->data;
    }

    bool empty()
    {
        return head == nullptr;
    }

    int size()
    {
        return current_size;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyStack st;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            st.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
        {
            cout << st.pop() << '\n';
        }
        else if (op == "top")
        {
            cout << st.top() << '\n';
        }
        else if (op == "empty")
        {
            cout << (st.empty() ? "true" : "false") << '\n';
        }
        else // size
        {
            cout << st.size() << '\n';
        }
    }

    return 0;
}

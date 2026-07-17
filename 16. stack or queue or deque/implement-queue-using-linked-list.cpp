#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/
class MyQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;
    int queueSize;

public:
    MyQueue() {
        frontNode = nullptr;
        backNode = nullptr;
        queueSize = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (empty()) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            backNode = newNode;
        }
        queueSize++;
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        Node* temp = frontNode;
        int poppedValue = temp->data;
        
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        
        delete temp;
        queueSize--;
        return poppedValue;
    }

    int front() {
        if (empty()) {
            return -1;
        }
        return frontNode->data;
    }

    int back() {
        if (empty()) {
            return -1;
        }
        return backNode->data;
    }

    bool empty() {
        return queueSize == 0; // or frontNode == nullptr
    }

    int size() {
        return queueSize;
    }
};



    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyQueue que;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            que.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
            cout << que.pop() << '\n';
        else if (op == "front")
            cout << que.front() << '\n';
        else if (op == "back")
            cout << que.back() << '\n';
        else if (op == "empty")
            cout << (que.empty() ? "true" : "false") << '\n';
        else // size
            cout << que.size() << '\n';
    }

    return 0;
}
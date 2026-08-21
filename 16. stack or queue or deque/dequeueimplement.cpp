#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    void push_front(int x) -- insert x at the front.
    void push_back(int x)  -- insert x at the back.
    int  pop_front()       -- remove and return the front element; -1 if empty.
    int  pop_back()        -- remove and return the back element; -1 if empty.
    int  front()           -- return the front element; -1 if empty.
    int  back()            -- return the back element; -1 if empty.
    bool empty()           -- return true if the deque is empty, else false.
    int  size()            -- return the number of elements.
    All operations must run in O(1).
*/

class MyDeque {
public:

    MyDeque()
    {

    }

    void push_front(int x)
    {

    }

    void push_back(int x)
    {

    }

    int pop_front()
    {

    }

    int pop_back()
    {

    }

    int front()
    {

    }

    int back()
    {

    }

    bool empty()
    {

    }

    int size()
    {

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyDeque dq;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
            cout << "null" << '\n';
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
            cout << "null" << '\n';
        }
        else if (op == "pop_front")
            cout << dq.pop_front() << '\n';
        else if (op == "pop_back")
            cout << dq.pop_back() << '\n';
        else if (op == "front")
            cout << dq.front() << '\n';
        else if (op == "back")
            cout << dq.back() << '\n';
        else if (op == "empty")
            cout << (dq.empty() ? "true" : "false") << '\n';
        else // size
            cout << dq.size() << '\n';
    }

    return 0;
}
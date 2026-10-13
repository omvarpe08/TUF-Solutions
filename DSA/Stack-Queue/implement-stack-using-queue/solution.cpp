#include <queue>
using namespace std;

class QueueStack {
    queue<int> q;

public:
    QueueStack() {}

    void push(int x) {
        q.push(x);

        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

// TC = O(N) ..for push operation
// TC = O(1) ..for all other operation except push
// SC = O(N) 

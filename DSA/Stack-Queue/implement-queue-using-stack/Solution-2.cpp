class StackQueue {
    stack<int> s1;
    stack<int> s2;
public:
    StackQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {

        if(s2.size()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        else
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            s2.pop();
            return val;
        
    }
    
    int peek() {
        if(s2.size()) {
            return s2.top();
        }
        else {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};
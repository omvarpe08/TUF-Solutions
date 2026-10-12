class ArrayStack {

    int st[1000];
    int topIdx;

public:
    ArrayStack() {
        topIdx = -1;
    }
    
    void push(int x) {
        topIdx++;
        st[topIdx] = x;

        //or
        //st[++topIdx] = x;
    }
    
    int pop() {
        if(topIdx == -1) return -1;
        return st[topIdx--];

        //or
        //return st[topIdx];
        //topIdx--;
    }
    
    int top() {
        if(topIdx == -1) return -1;
        return st[topIdx];
    }
    
    bool isEmpty() {
        if(topIdx == -1) return 1;
        return 0;

        //or
        //return topIdx == -1;
    }
};

// TC = O(1) ..here u can see operation is taking O(1) TC.
// SC = O(N) ..array of size N = 1000
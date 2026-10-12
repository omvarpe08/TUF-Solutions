class ArrayQueue {

    int q[1000];
    int start;
    int end;
    int size;

public:
    ArrayQueue() {
        start = 0;
        end = -1;
        size = 0;
    }
    
    void push(int x) {
        if (size == 1000) return;

        end = (end+1) % 1000;
        q[end] = x;
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;

    /*  if(size == 1) { 
                        
            int x = q[start];                 
            start = 0;
            end = -1;
            size--;
            return x;

            //we can also add this condn but this is not compulsory. if we use this condn than once queue gets empty it start pushing element from its beginnin again but if we dont use this condn then it will start adding element from end+1 or start.
        }
    */

        int x = q[start];
        start = (start+1) % 1000;
        size--;
        return x;
    }
    
    int peek() {
        if(size == 0) return -1;
        return q[start];
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

// TC = O(1) ..here u can see operation is taking O(1) TC.
// SC = O(N) ..array of size N = 1000


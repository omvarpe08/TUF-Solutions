class LinkedListQueue {
    class Node {
    public:
        int data;
        Node* next;

        Node(int data1) {
            data = data1;
            next = nullptr;
        }
    };

    Node* topIdx;
    Node* curr;

public:
    LinkedListQueue() {
        topIdx = nullptr;
        curr = nullptr;
    }
    
    void push(int x) {
        if(topIdx == NULL) {
            Node* newNode = new Node(x);
            curr = newNode;
            topIdx = newNode;
            return;
        }
        Node* newNode = new Node(x);
        curr->next = newNode;
        curr = newNode;
    }
    
    int pop() {
        if(isEmpty()) return -1;

        if(topIdx == curr) {
            int val = topIdx->data;
            delete topIdx;
            topIdx = nullptr;
            curr = nullptr;
            return val;
        }
        int val = topIdx->data;
        Node* temp = topIdx;
        topIdx = topIdx->next;
        delete temp;
        return val;
    }
    
    int peek() {
        if(isEmpty()) return -1;

        return topIdx->data;
    }
    
    bool isEmpty() {
        return topIdx == NULL;
    }
};
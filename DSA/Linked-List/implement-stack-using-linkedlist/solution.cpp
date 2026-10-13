class LinkedListStack {

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

public:
    LinkedListStack() {
        topIdx = nullptr;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topIdx;
        topIdx = newNode;

    }
    
    int pop() {
        if (isEmpty()) return -1;

        int x = topIdx->data;
        Node* temp = topIdx;
        topIdx = topIdx->next;
        delete temp;
        return x;
    }
    
    int top() {
        if (isEmpty()) return -1;
        return topIdx->data;
    }
    
    bool isEmpty() {
        return topIdx == nullptr;
    }
};
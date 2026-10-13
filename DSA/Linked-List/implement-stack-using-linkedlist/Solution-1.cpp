class LinkedListStack {
    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* topNode;

public:
    LinkedListStack() {
        topNode = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;

        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;

        return val;
    }

    int top() {
        if (isEmpty()) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};


// TC = O(1) ...for all operations
// SC = O(N) ...for N elements.
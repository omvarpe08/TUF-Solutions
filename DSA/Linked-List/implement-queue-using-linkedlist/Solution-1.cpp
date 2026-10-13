class LinkedListQueue {
    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop() {
        if (front == nullptr) {
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    int peek() {
        if (front == nullptr) {
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// TC = O(1) ...for all operations
// SC = O(N) ...for N elements.
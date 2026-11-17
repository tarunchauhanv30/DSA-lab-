#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* node = new Node(value);
        node->next = topNode;
        topNode = node;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty\\n";
            return -1;
        }

        int value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    int top() const {
        if (isEmpty()) return -1;
        return topNode->data;
    }
};

int main() {
    Stack stack;
    int operations;
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int value;
            cin >> value;
            stack.push(value);
        } else if (choice == 2) {
            cout << stack.pop() << "\\n";
        } else if (choice == 3) {
            cout << stack.top() << "\\n";
        } else if (choice == 4) {
            cout << (stack.isEmpty() ? "Empty" : "Not empty") << "\\n";
        }
    }

    return 0;
}

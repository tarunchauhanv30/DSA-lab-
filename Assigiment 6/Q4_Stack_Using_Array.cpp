#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) : capacity(size), topIndex(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full\\n";
            return;
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty\\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() const {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

int main() {
    int capacity, operations;
    cin >> capacity >> operations;

    if (capacity <= 0 || operations < 0) return 0;

    Stack stack(capacity);

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

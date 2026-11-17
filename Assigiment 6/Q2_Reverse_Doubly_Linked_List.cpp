#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void reverseDoublyList(Node*& head) {
    Node* current = head;
    Node* newHead = nullptr;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        newHead = current;
        current = nextNode;
    }

    head = newHead;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\\n";
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* node = new Node(value);

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    cout << "Original doubly linked list: ";
    display(head);

    reverseDoublyList(head);

    cout << "Reversed doubly linked list: ";
    display(head);

    return 0;
}

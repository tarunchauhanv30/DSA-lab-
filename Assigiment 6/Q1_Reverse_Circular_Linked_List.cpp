#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void reverseCircularList(Node*& head) {
    if (head == nullptr || head->next == head) return;

    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    } while (current != head);

    head->next = previous;
    head = previous;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\\n";
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

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
            node->next = head;
        } else {
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    cout << "Original circular linked list: ";
    display(head);

    reverseCircularList(head);

    cout << "Reversed circular linked list: ";
    display(head);

    return 0;
}

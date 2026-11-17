#include <iostream>
using namespace std;

class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
        head = nullptr;
    }

    void insertBeginning(int value) {
        Node* node = new Node(value);

        if (head == nullptr) {
            head = node;
            node->next = head;
            return;
        }

        Node* tail = head;
        while (tail->next != head) tail = tail->next;

        node->next = head;
        tail->next = node;
        head = node;
    }

    void insertEnd(int value) {
        Node* node = new Node(value);

        if (head == nullptr) {
            head = node;
            node->next = head;
            return;
        }

        Node* tail = head;
        while (tail->next != head) tail = tail->next;

        tail->next = node;
        node->next = head;
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position\\n";
            return;
        }

        if (position == 1) {
            insertBeginning(value);
            return;
        }

        if (head == nullptr) {
            cout << "Invalid position\\n";
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != head; i++) {
            current = current->next;
        }

        if (position > 1 && current->next == head && position > 2) {
            cout << "Invalid position\\n";
            return;
        }

        Node* node = new Node(value);
        node->next = current->next;
        current->next = node;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "List is empty or position is invalid\\n";
            return;
        }

        if (position == 1) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            Node* tail = head;
            while (tail->next != head) tail = tail->next;

            Node* removed = head;
            head = head->next;
            tail->next = head;
            delete removed;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != head; i++) {
            current = current->next;
        }

        if (current->next == head) {
            cout << "Invalid position\\n";
            return;
        }

        Node* removed = current->next;
        current->next = removed->next;
        delete removed;
    }

    void display() const {
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
};

int main() {
    CircularLinkedList list;
    int n, value, position;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Original circular list: ";
    list.display();

    cin >> value;
    list.insertBeginning(value);
    cout << "After insertion at beginning: ";
    list.display();

    cin >> value;
    list.insertEnd(value);
    cout << "After insertion at end: ";
    list.display();

    cin >> position >> value;
    list.insertAtPosition(value, position);
    cout << "After insertion at position: ";
    list.display();

    cin >> position;
    list.deleteAtPosition(position);
    cout << "After deletion at position: ";
    list.display();

    return 0;
}

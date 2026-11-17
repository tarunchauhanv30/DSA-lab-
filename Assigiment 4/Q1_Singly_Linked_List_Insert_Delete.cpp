#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertBeginning(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void insertEnd(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = node;
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

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position\\n";
            return;
        }

        Node* node = new Node(value);
        node->next = temp->next;
        temp->next = node;
    }

    void deleteBeginning() {
        if (head == nullptr) {
            cout << "List is empty\\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty\\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or empty list\\n";
            return;
        }

        if (position == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp->next != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Invalid position\\n";
            return;
        }

        Node* removed = temp->next;
        temp->next = removed->next;
        delete removed;
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\\n";
    }
};

int main() {
    LinkedList list;
    int n, value, position;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Original list: ";
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

    list.deleteBeginning();
    cout << "After deletion at beginning: ";
    list.display();

    list.deleteEnd();
    cout << "After deletion at end: ";
    list.display();

    return 0;
}

#include <iostream>
using namesspace std;
struct Node {
    int data;  
    Node* next; 

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;   
    second->next = third;  
    third->next = fourth;  
    fourth->next = fifth;  

    std::cout << "Linked List of 5 elements: ";
    printList(head);


    return 0;
}
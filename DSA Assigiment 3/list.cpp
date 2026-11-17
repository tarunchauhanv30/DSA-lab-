#include <iostream>
using namespace std;
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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

    cout << "Linked List of 5 elements: ";
    printList(head);

    // Insert at start
    Node* tmp = new Node(5);
    tmp->next = head;
    head = tmp;
    cout << "Linked List of elements after adding at start: ";
    printList(head);

    // Insert at end 
    Node* tmp2 = new Node(70);
    Node* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = tmp2;
    cout << "linked list of elements after adding to end: ";
    printList(head);

    //insect at n postions
     int pos;
    std::cout<<"enter a position to add : ";
    std::cin>>pos;
    Node* tmp3 =new Node(300);
    Node *ptr2= head;

    for(int i=1;i<pos-1;i++){
        ptr2=ptr2->next;
    }
    tmp3->next=ptr2->next;
    ptr2->next=tmp3; 
    std::cout << "Linked List of elements after adding at pos " << pos<<" : ";
    printList(head);
    return 0;
}